
#include "raylib.h"
#include "cards.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
/* #include "raymath.h" */
/* #include "stdio.h" */
/* #include "stdlib.h" */


int main(void) {
        int gap = CARD_WIDTH / 2;
        int image_width  = 5 * gap + 4 * CARD_WIDTH;
        int image_height = CARD_HEIGHT * 2;

        InitWindow(image_width, image_height, "Card drawing example");

        Texture2D textures[NUM_CARDS];

        for (int j; j < NUM_CARDS; j++) {
                textures[j] = LoadTextureFromImage(FULL_DECK[j]->image);
        }

        Texture2D MONTHS[12][4] = {
                {
                        LoadTextureFromImage(hwatu_january_hikari.image),
                        LoadTextureFromImage(hwatu_january_kasu_1.image),
                        LoadTextureFromImage(hwatu_january_kasu_2.image),
                        LoadTextureFromImage(hwatu_january_tanzaku.image)
                },
                {
                        LoadTextureFromImage(hwatu_february_kasu_1.image),
                        LoadTextureFromImage(hwatu_february_kasu_2.image),
                        LoadTextureFromImage(hwatu_february_tane.image),
                        LoadTextureFromImage(hwatu_february_tanzaku.image)
                },
                {
                        LoadTextureFromImage(hwatu_march_hikari.image),
                        LoadTextureFromImage(hwatu_march_kasu_1.image),
                        LoadTextureFromImage(hwatu_march_kasu_2.image),
                        LoadTextureFromImage(hwatu_march_tanzaku.image)
                },
                {
                        LoadTextureFromImage(hwatu_april_kasu_1.image),
                        LoadTextureFromImage(hwatu_april_kasu_2.image),
                        LoadTextureFromImage(hwatu_april_tane.image),
                        LoadTextureFromImage(hwatu_april_tanzaku.image)
                },
                {
                        LoadTextureFromImage(hwatu_may_kasu_1.image),
                        LoadTextureFromImage(hwatu_may_kasu_2.image),
                        LoadTextureFromImage(hwatu_may_tane.image),
                        LoadTextureFromImage(hwatu_may_tanzaku.image)
                },
                {
                        LoadTextureFromImage(hwatu_june_kasu_1.image),
                        LoadTextureFromImage(hwatu_june_kasu_2.image),
                        LoadTextureFromImage(hwatu_june_tane.image),
                        LoadTextureFromImage(hwatu_june_tanzaku.image)
                },
                {
                        LoadTextureFromImage(hwatu_july_kasu_1.image),
                        LoadTextureFromImage(hwatu_july_kasu_2.image),
                        LoadTextureFromImage(hwatu_july_tane.image),
                        LoadTextureFromImage(hwatu_july_tanzaku.image)
                },
                {
                        LoadTextureFromImage(hwatu_august_hikari.image),
                        LoadTextureFromImage(hwatu_august_kasu_1.image),
                        LoadTextureFromImage(hwatu_august_kasu_2.image),
                        LoadTextureFromImage(hwatu_august_tane.image)
                },
                {
                        LoadTextureFromImage(hwatu_september_kasu_1.image),
                        LoadTextureFromImage(hwatu_september_kasu_2.image),
                        LoadTextureFromImage(hwatu_september_tane.image),
                        LoadTextureFromImage(hwatu_september_tanzaku.image)
                },
                {
                        LoadTextureFromImage(hwatu_october_kasu_1.image),
                        LoadTextureFromImage(hwatu_october_kasu_2.image),
                        LoadTextureFromImage(hwatu_october_tane.image),
                        LoadTextureFromImage(hwatu_october_tanzaku.image)
                },
                {
                        LoadTextureFromImage(hwatu_november_hikari.image),
                        LoadTextureFromImage(hwatu_november_kasu_1.image),
                        LoadTextureFromImage(hwatu_november_kasu_2.image),
                        LoadTextureFromImage(hwatu_november_kasu_3.image)
                },
                {
                        LoadTextureFromImage(hwatu_december_hikari.image),
                        LoadTextureFromImage(hwatu_december_kasu.image),
                        LoadTextureFromImage(hwatu_december_tane.image),
                        LoadTextureFromImage(hwatu_december_tanzaku.image)
                }
        };

        float sliderValue = 0.0f;
        int month;

        while (!WindowShouldClose()) {
                BeginDrawing();

                ClearBackground(RAYWHITE);

                month = ((int) sliderValue);

                for (int i = 0; i < 4; i++) {
                        int x = i*image_width/4 + gap/2;
                        int y = image_height/2 - CARD_HEIGHT/2;

                        DrawTexture(MONTHS[month][i], x, y, WHITE);
                }

                GuiSliderBar((Rectangle){ gap, (CARD_HEIGHT/2 - CARD_HEIGHT/4)/2, image_width - gap * 2, CARD_HEIGHT/4 }, "1", "12", &sliderValue, 0.0f, 11.0f);
                EndDrawing();
        }

        // Unload resources
        for (int i = 0; i < NUM_CARDS; i++) {
                UnloadTexture(textures[i]);
        }
        
        // TODO Need to unload images?
        /* UnloadImage(<image>); */
        CloseWindow();

        return 0;
}
