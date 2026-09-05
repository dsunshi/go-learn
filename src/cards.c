
#include "raylib.h"
#include "cards.h"

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


void draw_card(unsigned int card, CardStyle style, float center_x, float center_y) {
        
        Texture2D image = CARD_TEXTURES[GET_INDEX(card)];

        float card_x = center_x - CARD_WIDTH  * style.scale / 2.0f;
        float card_y = center_y - CARD_HEIGHT * style.scale / 2.0f;

        if (style.draw_shadow) {
                float shadow_x  = center_x - SHADOW_WIDTH  * style.scale / 2.0f;
                float shadow_y  = center_y - SHADOW_HEIGHT * style.scale / 2.0f;
                float xo = style.r * (float) cos(style.theta);
                float yo = style.r * (float) sin(style.theta);

                DrawTextureEx(SHADOW,
                              (Vector2) {shadow_x + xo, shadow_y + yo},
                              0.0f,
                              style.scale,
                              Fade(WHITE, style.shadow_opacity));
        }
        

        if (style.draw_highlight) {
                float roundness  = 0.1f;
                float hx_scale   = style.scale * 1.1f;
                float hy_scale   = style.scale * 1.07f;
                float highlight_x = center_x - CARD_WIDTH  * hx_scale / 2.0f;
                float highlight_y = center_y - CARD_HEIGHT * hy_scale / 2.0f;
                int segments  = 0;

                Rectangle h = { highlight_x,
                                highlight_y,
                                (float) CARD_WIDTH * hx_scale,
                                (float) CARD_HEIGHT * hy_scale };

                DrawRectangleRounded(h, roundness, segments, style.highlight_color);
        }
        
        if (style.draw_card) {
                // Color *must* be WHTIE in order for the png transparency to work!
                DrawTextureEx(image, (Vector2) {card_x, card_y}, 0.0f, style.scale, WHITE);
        }
}

unsigned int* find_images(unsigned int mask, match_fn match, int *length) {
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

        unsigned int *textures = (unsigned int *) malloc((unsigned long) size * sizeof(unsigned int));

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
                        int j = (int) (i + ((size_t) rand()) / (RAND_MAX / (n - i) + 1));
                        int t = array[j];
                        array[j] = array[i];
                        array[i] = t;
                }
        }
}
