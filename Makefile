
CARD_WIDTH   := 100
ASPECT_RATIO := 0.6128
CARD_HEIGHT  := $(shell echo "scale=0; $(CARD_WIDTH) / $(ASPECT_RATIO)" | bc)

SVG_DIR := download
PNG_DIR := images
H_DIR   := gen
OUT_DIR := out

SVG_FILES := $(wildcard $(SVG_DIR)/*.svg)
PNG_FILES := $(patsubst $(SVG_DIR)/%.svg, $(PNG_DIR)/%.png, $(SVG_FILES))
H_FILES   := $(patsubst $(SVG_DIR)/%.svg, $(H_DIR)/%.h, $(SVG_FILES))

C_FLAGS  = -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wformat=2
LD_FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: $(OUT_DIR)/main

$(OUT_DIR)/main: src/main.c src/cards.h src/raygui.h $(H_FILES) | $(OUT_DIR)
	gcc -o $@ $< $(C_FLAGS) -DCARD_WIDTH=$(CARD_WIDTH) -DCARD_HEIGHT=$(CARD_HEIGHT) -I./$(H_DIR) $(LD_FLAGS)

$(H_DIR)/%.h: $(PNG_DIR)/%.png | $(H_DIR) out/toHeader $(PNG_FILES)
	./$(OUT_DIR)/toHeader $< $@

$(PNG_DIR)/%.png: $(SVG_DIR)/%.svg | $(PNG_DIR)
	inkscape --export-width=$(CARD_WIDTH) --export-height=$(CARD_HEIGHT) --export-type="png" $< --export-filename=$@

$(OUT_DIR)/toHeader: src/toHeader.c | $(OUT_DIR)
	gcc -o $@ $< $(C_FLAGS) $(LD_FLAGS)

.PHONY: run
run: out/main
	./$(OUT_DIR)/main

.PHONY: clean
clean:
	rm -rf $(OUT_DIR)

.PHONY: clean-gen
clean-gen: clean
	rm -rf $(PNG_DIR)
	rm -rf $(H_DIR)

.PHONY: clean-all
clean-all: clean-gen
	rm -rf $(SVG_DIR)

$(PNG_DIR):
	mkdir -p $@

$(H_DIR):
	mkdir -p $@

$(OUT_DIR):
	mkdir -p $@

.PHONY: download
download:
	./tools/download
