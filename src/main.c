
#include "raylib.h"
#include "cards.h"
#include "assert.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
/* #include "raymath.h" */
/* #include "stdio.h" */
/* #include "stdlib.h" */

#define SUIT_ANY    (0x0F)

typedef int (* match_fn)(unsigned int, unsigned int);

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

void free_images(Texture2D *images, int length) {
        for (int i = 0; i < length; i++) {
                UnloadTexture(images[i]);
        }

        free(images);
}

Texture2D* find_images(unsigned int mask, match_fn match, int *length) {
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

        Texture2D *textures = (Texture2D *) malloc((unsigned long) size * sizeof(Texture2D));

        if (textures == NULL) {
                printf("[ERROR] Failed to allocate!");
                *length = 0;
                return NULL;
        }
        
        *length = 0;
        for (int i = 0; i < NUM_CARDS; i++) {
                unsigned int card = CARDS[i];
                if (match(mask, card)) {
                        /* printf("Loading 0x%04X\n", card); */
                        textures[*length] = LoadTextureFromImage(IMAGE_DECK[GET_INDEX(card)]);
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

int main(void) {
        int gap          = CARD_WIDTH  / 2;
        int image_height = CARD_HEIGHT * 2;
        int MAX_CARDS    = 4;
        int image_width  = (MAX_CARDS + 1) * gap + MAX_CARDS * CARD_WIDTH;

        InitWindow(image_width, image_height, "Card drawing example");

        unsigned int mask = 0x00;
        int length = 0x00;
        /* SET_ANIMAL(mask); */
        /* SET_BRIGHT(mask); */
        SET_DOUBLE_JUNK(mask);
        /* SET_JOKER(mask); */
        /* SET_JUNK(mask); */
        /* SET_RIBBON(mask); */
        SET_SUIT(mask, SUIT_ANY);

        Texture2D *textures = find_images(mask, and_match, &length);
        float scale         = ((float) MAX_CARDS / (float) length) * 0.5f;
        
        printf("Found %d matches!\n", length);

        while (!WindowShouldClose()) {
                BeginDrawing();

                ClearBackground(RAYWHITE);

                for (int i = 0; i < length; i++) {
                        float x = ((float) i) * ((float) image_width / (float) length) + ((float) gap) * scale;
                        float y = ((float) image_height / 2.0f) - CARD_HEIGHT * scale;

                        DrawTextureEx(textures[i], (Vector2) {x, y}, 0.0f, scale, WHITE); 
                }

                EndDrawing();
        }

        free_images(textures, length);

        CloseWindow();

        return 0;
}
