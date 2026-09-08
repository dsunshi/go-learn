
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

#define HALF(x) (((float) (x)) / 2.0f)

void draw_texture(const Texture2D image, const Vector2 size, const Vector2 pos, const float scale, const int deg) {
        const Rectangle source = (Rectangle) {0.0f, 0.0f, size.x, size.y};
        const float rad = ((float) deg) * 3.14159f / 180.0f;

        const Vector2 orig_center = (Vector2) {pos.x - HALF(size.x * scale), pos.y - HALF(size.y  * scale)};
        const Vector2 turn_center = (Vector2) {(orig_center.x - pos.x) * (float) cos(rad) - (orig_center.y - pos.y) * (float) sin(rad) + pos.x,
                                               (orig_center.x - pos.x) * (float) sin(rad) + (orig_center.y - pos.y) * (float) cos(rad) + pos.y};

        const Vector2 delta  = (Vector2) {orig_center.x - turn_center.x, orig_center.y - turn_center.y};

        const Rectangle dest = (Rectangle) {pos.x + HALF(CARD_WIDTH) + delta.x,
                                                pos.y + HALF(CARD_HEIGHT) + delta.y,
                                                size.x,
                                                size.y};

        /* if (deg == 0) { */
        /*         DrawTextureEx(image, orig_center, 0.0f, scale, WHITE); */
        /* } else { */
        /*         DrawTexturePro(image, source, dest, size, (float) deg, WHITE); */
        /* } */
        DrawTexturePro(image, source, dest, size, (float) deg, WHITE);
}

void draw_card(const unsigned int card, const Vector2 pos, const float scale, const int deg, const bool shadow, const float r, const float theta) {
        const Vector2 cast       = (Vector2) {r * (float) cos(theta), r * (float) sin(theta)};
        const Vector2 shadow_pos = (Vector2) {pos.x + cast.x, pos.y + cast.y};
        const Texture2D image    = CARD_TEXTURES[GET_INDEX(card)];

        const Vector2 card_size   = (Vector2) {(float) CARD_WIDTH,   (float) CARD_HEIGHT};
        const Vector2 shadow_size = (Vector2) {(float) SHADOW_WIDTH, (float) SHADOW_HEIGHT};

        if (shadow) {
                draw_texture(SHADOW, shadow_size, shadow_pos, scale, deg);
        }

        draw_texture(image, card_size, pos, scale, deg);
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
