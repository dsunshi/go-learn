
#include "raylib.h"
#include "cards.h"
#include "assert.h"
#include "time.h"
#include <stdlib.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
/* #include "raymath.h" */
/* #include "stdio.h" */
/* #include "stdlib.h" */

#define SUIT_ANY    (0x0F)

typedef int (* match_fn)(unsigned int, unsigned int);

Texture2D CARD_TEXTURES[NUM_CARDS];

void init() {
        for (int i = 0; i < NUM_CARDS; i++) {
                CARD_TEXTURES[i] = LoadTextureFromImage(IMAGE_DECK[GET_INDEX(CARDS[i])]);
        }
}

void cleanup() {
        for (int i = 0; i < NUM_CARDS; i++) {
                UnloadTexture(CARD_TEXTURES[i]);
        }
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

void draw_card_shadow(float center_x, float center_y) {
        float x = center_x - CARD_WIDTH  / 2.0f;
        float y = center_y - CARD_HEIGHT / 2.0f;
        float roundness    = CARD_HEIGHT / 1000.0f;
        int segments       = 0;

        float shadow_offset = roundness * 30.0f;

        Rectangle r = { x + shadow_offset,
                        y + shadow_offset,
                        (float) (CARD_WIDTH  * 1.0f),
                        (float) (CARD_HEIGHT * 1.0f) };

        DrawRectangleRounded(r, roundness, segments, Fade((Color) { 59, 66, 82, 255}, 0.5f));
}

void draw_card_from_texture(Texture2D image, float center_x, float center_y, float scale) {
        float x = center_x - CARD_WIDTH  / 2.0f;
        float y = center_y - CARD_HEIGHT / 2.0f;
        float roundness    = CARD_HEIGHT / 1000.0f;
        int segments       = 0;

        float shadow_offset = roundness * 30.0f;

        Rectangle r = { x + shadow_offset,
                        y + shadow_offset,
                        (float) (CARD_WIDTH  * 1.0f),
                        (float) (CARD_HEIGHT * 1.0f) };

        DrawRectangleRounded(r, roundness, segments, Fade((Color) { 59, 66, 82, 255}, 0.5f));
        DrawTextureEx(image, (Vector2) {x, y}, 0.0f, scale, WHITE);
}

void draw_highlighted_card_from_texture(Texture2D image, float center_x, float center_y, float scale) {
        float x = center_x - CARD_WIDTH  / 2.0f;
        float y = center_y - CARD_HEIGHT / 2.0f;
        float roundness    = CARD_HEIGHT / 1000.0f;
        int segments       = 0;

        /* float shadow_offset = roundness * 30.0f; */

        /* Rectangle r = { x + shadow_offset, */
        /*                 y + shadow_offset, */
        /*                 (float) (CARD_WIDTH  * 1.0f), */
        /*                 (float) (CARD_HEIGHT * 1.0f) }; */
        
        float h_scale = 0.1f;
        float delta_x = (CARD_WIDTH  * (1.0f + h_scale)) - CARD_WIDTH;
        float delta_y = (CARD_HEIGHT * (1.0f + h_scale)) - CARD_HEIGHT;
        Rectangle h = { x - delta_x / 2.0f,
                        y - delta_y / 2.0f,
                        (float) (CARD_WIDTH  * (1.0f + h_scale)),
                        (float) (CARD_HEIGHT * (1.0f + h_scale)) };

        /* DrawRectangleRounded(r, roundness, segments, Fade((Color) {59, 66, 82, 255}, 0.5f)); */
        DrawRectangleRounded(h, roundness, segments, Fade((Color) {180, 142, 173, 255}, 1.0f));
        DrawTextureEx(image, (Vector2) {x, y}, 0.0f, scale, WHITE);
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

void draw_match_screen(int screen_width, int screen_height) {
        int header_y = screen_height * 0.05f;
        int footer_y = screen_height * 0.95f;
        int table_height = screen_height * 0.9f;
        float scale = 0.5f;

        float card_height = CARD_HEIGHT * scale;
        float card_width  = CARD_WIDTH * scale;

        /* Left side */
        int num_rows = 2;
        int num_cols = 2;
        int gy = (table_height - ( num_rows * card_height )) / (num_rows + 1);
        int wy = card_height;
        
        int gx = ((screen_width / 2) - ( num_cols * card_height )) / (num_cols + 1);
        int wx = card_width;
        
        unsigned int mask = 0x00;
        int length = 0x00;

        static int suit = -1;
        static int seed = -1;
        static int highlighted = -1;
        static bool correct = false;
        
        if (seed < 0) {
                seed = time(NULL);
        }
        srand(seed);

        if (suit < 0) {
                suit = ((unsigned int) rand()) % 12 + 1;
        }

        SET_SUIT(mask, suit);

        int *suits = find_images(mask, and_match, &length);
        shuffle(suits, length);
        /* assert(length == 4); */
        
        int *all_suits = find_images(suit, except_suit, &length);
        shuffle(all_suits, length);

        /* Copy the match */
        int x = rand() % 6;
        all_suits[x] = suits[3];

        ClearBackground((Color) {94, 129, 172, 255});

        DrawText("Suit Match", 20, 20, 40, BLACK);

        int t = 0;
        for (int i = 1; i <= num_cols; i++) {
                for (int j = 1; j <= num_rows; j++) {
                        float x = i * (gx + wx) - card_width / 2.0f;
                        float y = j * (gy + wy) + header_y - card_height / 2.0f;

                        if (t < 3) {
                                draw_card_from_texture(CARD_TEXTURES[GET_INDEX(suits[t])], x, y, scale);
                        } else {
                                if (correct) { 
                                        draw_card_from_texture(CARD_TEXTURES[GET_INDEX(suits[t])], x, y, scale);
                                } else { 
                                        draw_card_shadow(x, y);
                                }
                        }
                        t++;
                }
        }

        num_cols = 3;
        gx = ((screen_width / 2) - ( num_cols * card_height )) / (num_cols + 1);

        // Check if the left mouse button was pressed this frame
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                // Fetch the x and y coordinates as a Vector2 struct
                t = 0;
                Vector2 click = GetMousePosition(); 
                for (int i = 1; i <= num_cols; i++) {
                        for (int j = 1; j <= num_rows; j++) {
                                float x = i * (gx + wx) - card_width / 2.0f + screen_width / 2.0f;
                                float y = j * (gy + wy) + header_y - card_height / 2.0f;

                                if (click.x > x - card_width / 2.0f && click.x < x + card_width / 2.0f) {
                                        if (click.y > y - card_height / 2.0f && click.y < y + card_height / 2.0f) {
                                                highlighted = t;
                                        }
                                }
                                t++;
                        }
                }
        }

        t = 0;
        for (int i = 1; i <= num_cols; i++) {
                for (int j = 1; j <= num_rows; j++) {
                        float x = i * (gx + wx) - card_width / 2.0f + screen_width / 2.0f;
                        float y = j * (gy + wy) + header_y - card_height / 2.0f;

                        if (t == highlighted) {
                                draw_highlighted_card_from_texture(CARD_TEXTURES[GET_INDEX(all_suits[t])], x, y, scale);
                        } else {
                                draw_card_from_texture(CARD_TEXTURES[GET_INDEX(all_suits[t])], x, y, scale);
                        }

                        t++;
                }
        }

        if (GuiButton((Rectangle){ screen_width - 175, footer_y - header_y * 2, 175, header_y * 3 }, "Check")) {
                if (highlighted >= 0 ) {
                        if (GET_SUIT(all_suits[highlighted]) == GET_SUIT(suits[0])) {
                                correct = true;
                        } else {
                                correct = false;
                        }
                }
        }
        
        if (correct) {
                if (GuiButton((Rectangle){ screen_width - 175*2, footer_y - header_y * 2, 175, header_y * 3 }, "Next")) {
                        suit = -1;
                        correct = false;
                        highlighted = -1;
                        seed = -1;
                }
        }
        
        free(suits);
        free(all_suits);
}

int main(void) {
        int gap          = CARD_WIDTH  / 2;
        int image_height = CARD_HEIGHT * 5;
        int MAX_CARDS    = 4;
        int image_width  = (image_height * 16.0f) / 9.0f;

        InitWindow(image_width, image_height, "Card drawing example");

        init();
        /* unsigned int mask = 0x00; */
        /* int length = 0x00; */
        /* SET_ANIMAL(mask); */
        /* SET_BRIGHT(mask); */
        /* SET_DOUBLE_JUNK(mask); */
        /* SET_JOKER(mask); */
        /* SET_JUNK(mask); */
        /* SET_RIBBON(mask); */
        /* SET_SUIT(mask, 3); */

        /* Texture2D *textures = find_images(mask, and_match, &length); */
        /* float scale         = fmin(0.5f, ((float) MAX_CARDS / (float) length) * 0.5f); */
        
        /* printf("Found %d matches!\n", length); */

        while (!WindowShouldClose()) {
                BeginDrawing();

                /* ClearBackground((Color) {203, 166, 247, 255}); */
                ClearBackground(RAYWHITE);

                draw_match_screen(image_width, image_height);

                /* for (int i = 0; i < length; i++) { */
                /*         float x = ((float) i + 1.0) * (image_width / (length + 1)); */
                /*         float y = (float) image_height / 2.0f; */

                /*         draw_card_from_texture(textures[i], x, y, scale); */
                /* } */

                EndDrawing();
        }

        /* free_images(textures, length); */
        cleanup();

        CloseWindow();

        return 0;
}
