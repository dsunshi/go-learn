
#include "raylib.h"

#include "cards.h"

extern Texture2D CARD_TEXTURES[NUM_CARDS];

int main(void) {
        int image_height = CARD_HEIGHT * 2;
        int image_width  = (int) ((((float) image_height) * 16.0f) / 9.0f);

        InitWindow(image_width, image_height, "Card drawing example");
        init();

        SetTargetFPS(60);

        int rotation = 0;
        int card = 0;
        int timer = 0;

        while (!WindowShouldClose()) {
                BeginDrawing();

                ClearBackground((Color) {216, 222, 233, 255});

                Vector2 center = (Vector2) {(float) image_width/2.0f, (float) image_height/2.0f};

                draw_card(CARDS[card], center, 1.0f, rotation, true, (SHADOW_WIDTH - CARD_WIDTH) / 3.0f, -11.0f * 3.14f / 6.0f);

                rotation = (rotation + 1) % 360;
                timer++;

                if(timer > 3 * 60) {
                        timer = 0;
                        card = (card + 1) % NUM_CARDS;
                }

                EndDrawing();
        }

        cleanup();
        CloseWindow();

        return 0;
}
