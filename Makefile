
CARD_WIDTH   := 200
ASPECT_RATIO := 0.6128
CARD_HEIGHT  := $(shell echo "scale=0; $(CARD_WIDTH) / $(ASPECT_RATIO)" | bc)

SHADOW_SCALE  := 0.25
SHADOW_WIDTH  := $(shell echo "scale=0; $(CARD_WIDTH)   * (1.0 + $(SHADOW_SCALE))" | bc)
SHADOW_HEIGHT := $(shell echo "scale=0; $(SHADOW_WIDTH) / $(ASPECT_RATIO)" | bc)

SC0X := $(shell echo "scale=0; ($(SHADOW_WIDTH)  - $(CARD_WIDTH)) / 2.0" | bc)
SC0Y := $(shell echo "scale=0; ($(SHADOW_HEIGHT) - $(CARD_HEIGHT)) / 2.0" | bc)

SC1X := $(shell echo "scale=0; $(SHADOW_WIDTH)  - $(SC0X)" | bc)
SC1Y := $(shell echo "scale=0; $(SHADOW_HEIGHT) - $(SC0Y)" | bc)

SVG_DIR := download
PNG_DIR := images
H_DIR   := gen
OUT_DIR := out

SVG_FILES := $(wildcard $(SVG_DIR)/*.svg)
PNG_FILES := $(patsubst $(SVG_DIR)/%.svg, $(PNG_DIR)/%.png, $(SVG_FILES))
H_FILES   := $(patsubst $(SVG_DIR)/%.svg, $(H_DIR)/%.h, $(SVG_FILES))

C_FLAGS  = -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wformat=2
LD_FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TEMP_IMG := $(shell mktemp).png

SHADOW_COLOR := 2e3440

all: $(OUT_DIR)/main

$(PNG_DIR)/shadow.png:
	magick -size $(SHADOW_WIDTH)x$(SHADOW_HEIGHT) canvas:transparent PNG32:$(TEMP_IMG)
	magick $(TEMP_IMG) -fill "#$(SHADOW_COLOR)" -draw "rectangle $(SC0X),$(SC0Y) $(SC1X),$(SC1Y)" $(TEMP_IMG)
	magick $(TEMP_IMG) -filter Gaussian -blur 0x8 $@

$(H_DIR)/shadow.h: $(PNG_DIR)/shadow.png $(OUT_DIR)/toHeader
	./$(OUT_DIR)/toHeader $< $@

$(OUT_DIR)/main: src/main.c src/cards.c src/cards.h src/raygui.h $(H_FILES) $(H_DIR)/shadow.h | $(OUT_DIR)
	gcc -o $@ $< src/cards.c $(C_FLAGS) -DCARD_WIDTH=$(CARD_WIDTH) -DCARD_HEIGHT=$(CARD_HEIGHT) -I./$(H_DIR) $(LD_FLAGS)

$(H_DIR)/%.h: $(PNG_DIR)/%.png | $(H_DIR) out/toHeader $(PNG_FILES)
	./$(OUT_DIR)/toHeader $< $@

$(PNG_DIR)/%.png: $(SVG_DIR)/%.svg | $(PNG_DIR)
	inkscape --export-width=$(CARD_WIDTH) --export-height=$(CARD_HEIGHT) --export-type="png" $< --export-filename=$(TEMP_IMG)
	dipc nord $(TEMP_IMG) -o $@

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
