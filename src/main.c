
#include "raylib.h"
#include "cards.h"
#include "assert.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
/* #include "raymath.h" */
/* #include "stdio.h" */
/* #include "stdlib.h" */

#define SUIT_ANY    (0x0F)

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

int* find_images(unsigned int mask, int *length) {
        int size = 0;

        if (mask == 0) {
                printf("[ERROR] Empty Mask!");
                *length = 0;
                return NULL;
        }
     
        for (int i = 0; i < NUM_CARDS; i++) {
                if (and_match(mask, CARDS[i])) {
                        size++;
                }
        }

        int *arr = (int*) malloc((unsigned long) size * sizeof(int));

        if (arr == NULL) {
                printf("[ERROR] Failed to allocate!");
                *length = 0;
                return NULL;
        }
        
        *length = 0;
        for (int i = 0; i < NUM_CARDS; i++) {
                if (and_match(mask, CARDS[i])) {
                        arr[*length] = GET_INDEX(CARDS[i]);
                        *length += 1;
                }
        }
    
        if (size != *length) {
                /* TODO: Error printing */
                printf("Size = %d, but length = %d", size, *length);
                *length = 0;
                return NULL;
        }

        return arr;
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
        /* SET_DOUBLE_JUNK(mask); */
        /* SET_JOKER(mask); */
        /* SET_JUNK(mask); */
        SET_RIBBON(mask);
        SET_SUIT(mask, SUIT_ANY);

        int *matches = find_images(mask, &length);

        float scale         = ((float) MAX_CARDS / (float) length) * 0.5f;
        Texture2D *textures = (Texture2D *) malloc((unsigned long) length * sizeof(Texture2D));

        for (int i = 0; i < length; i++) {
                textures[i] = LoadTextureFromImage(IMAGE_DECK[matches[i]]);
        }
        
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

        for (int i = 0; i < length; i++) {
                UnloadTexture(textures[i]);
        }

        free(matches);

        CloseWindow();

        return 0;
}
