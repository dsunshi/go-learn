
#include "raylib.h"

#include "cards.h"
#include "assert.h"
#include "time.h"

#include <stdlib.h>
#include <math.h>

/* #define RAYGUI_IMPLEMENTATION */
/* #include "raygui.h" */
/* #include "raymath.h" */
#include "stdio.h"
/* #include "stdlib.h" */

#define SUIT_ANY    (0x0F)

typedef int (* match_fn)(unsigned int, unsigned int);

Texture2D CARD_TEXTURES[NUM_CARDS];
Texture2D SHADOW;

void init() {
        for (int i = 0; i < NUM_CARDS; i++) {
                CARD_TEXTURES[i] = LoadTextureFromImage(IMAGE_DECK[GET_INDEX(CARDS[i])]);
        }
        SHADOW = LoadTextureFromImage(SHADOW_IMG);
}

void cleanup() {
        for (int i = 0; i < NUM_CARDS; i++) {
                UnloadTexture(CARD_TEXTURES[i]);
        }
        UnloadTexture(SHADOW);
}

int except_suit(unsigned int suit, unsigned int card) {
        return !(suit == GET_SUIT(card));
}

int and_match(unsigned int mask, unsigned int card) {
        unsigned int mask_flags = mask >> 10;
        unsigned int card_flags = card >> 10;

        if (GET_SUIT(mask) == SUIT_ANY) {
                return mask_flags == (mask_flags & card_flags);
        } else {
                return (mask_flags == (mask_flags & card_flags)) && (GET_SUIT(mask) == GET_SUIT(card));
        }
}

int or_match(unsigned int mask, unsigned int card) {
        if (GET_SUIT(mask) == GET_SUIT(card)) {
                return 1;
        } else {
                unsigned int mask_flags = mask >> 10;
                unsigned int card_flags = card >> 10;

                return (int) (mask_flags & card_flags);
        }
}

typedef struct CardStyle {
        bool  draw_highlight;
        bool  draw_shadow;
        bool  draw_card;
        Color highlight_color;
        float shadow_opacity;
        float r;
        float theta;
        float scale;
} CardStyle;

/* float r     = (SHADOW_WIDTH - CARD_WIDTH) / 3.0f; */
/* float theta = 120.0f; */
void draw_card_from_texture(Texture2D image, CardStyle style, float center_x, float center_y) {
        float card_x = center_x - CARD_WIDTH  / 2.0f;
        float card_y = center_y - CARD_HEIGHT / 2.0f;

        if (style.draw_shadow) {
                float shadow_x  = center_x - SHADOW_WIDTH  / 2.0f;
                float shadow_y  = center_y - SHADOW_HEIGHT / 2.0f;
                float xo = style.r * cos(style.theta);
                float yo = style.r * sin(style.theta);

                DrawTextureEx(SHADOW, (Vector2) {shadow_x + xo, shadow_y + yo}, 0.0f, style.scale, Fade(WHITE, style.shadow_opacity));
        }

        if (style.draw_highlight) {
                float roundness = 0.1;
                float h_scale   = 1.1;
                float highlight_x = center_x - CARD_WIDTH  * h_scale / 2.0f;
                float highlight_y = center_y - CARD_HEIGHT * h_scale / 2.0f;
                int segments  = 0;

                Rectangle h = { highlight_x,
                                highlight_y,
                                (float) CARD_WIDTH * h_scale,
                                (float) CARD_HEIGHT * h_scale };

                DrawRectangleRounded(h, roundness, segments, style.highlight_color);
        }

        if (style.draw_card) {
                // Color *must* be WHTIE in order for the png transparency to work!
                DrawTextureEx(image, (Vector2) {card_x, card_y}, 0.0f, style.scale, WHITE);
        }
}

int* find_images(unsigned int mask, match_fn match, int *length) {
        int size = 0;

        if (mask == 0) {
                printf("[ERROR] Empty Mask!");
                *length = 0;
                return NULL;
        }
     
        for (int i = 0; i < NUM_CARDS; i++) {
                if (match(mask, CARDS[i])) {
                        size++;
                }
        }

        int *textures = (int *) malloc((unsigned long) size * sizeof(int));

        if (textures == NULL) {
                printf("[ERROR] Failed to allocate!");
                *length = 0;
                return NULL;
        }
        
        *length = 0;
        for (int i = 0; i < NUM_CARDS; i++) {
                unsigned int card = CARDS[i];
                if (match(mask, card)) {
                        textures[*length] = card;
                        *length += 1;
                }
        }
    
        if (size != *length) {
                /* TODO: Error printing */
                printf("Size = %d, but length = %d", size, *length);
                *length = 0;
                return NULL;
        }

        return textures;
}

// Source - https://stackoverflow.com/a/6127606
// Posted by John Leehey, modified by community. See post 'Timeline' for change history
// Retrieved 2026-08-22, License - CC BY-SA 3.0
/* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */
void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main(void) {
        int image_height = CARD_HEIGHT * 2;
        int image_width  = (image_height * 16.0f) / 9.0f;

        InitWindow(image_width, image_height, "Card drawing example");
        init();

        while (!WindowShouldClose()) {
                BeginDrawing();

                ClearBackground((Color) {216, 222, 233, 255});
                /* ClearBackground(RAYWHITE); */

                CardStyle style = (CardStyle) {
                        .draw_highlight = true,
                        .draw_shadow = true,
                        .draw_card = true,
                        .highlight_color = (Color) {163, 190, 140, 255},
                        .shadow_opacity = 0.75,
                        .r = (SHADOW_WIDTH - CARD_WIDTH) / 3.0f,
                        .theta = 120.0f,
                        .scale = 1.0,
                };

                /* draw_match_screen(image_width, image_height); */
                draw_card_from_texture(CARD_TEXTURES[GET_INDEX(HWATU_APRIL_TANE)], style, image_width/2, image_height/2);
                /* draw_card_from_texture(CARD_TEXTURES[GET_INDEX(HWATU_MAY_TANE)], image_width/2 - CARD_WIDTH/2, image_height/2, 1.0); */

                EndDrawing();
        }

        cleanup();
        CloseWindow();

        return 0;
}
