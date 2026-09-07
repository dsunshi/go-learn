
#include "raylib.h"

#include "cards.h"

int main(void) {
        int image_height = CARD_HEIGHT * 2;
        int image_width  = (int) ((((float) image_height) * 16.0f) / 9.0f);

        InitWindow(image_width, image_height, "Card drawing example");
        init();

        CardStyle style = (CardStyle) {
                .draw_highlight = true,
                .draw_shadow = true,
                .draw_card = true,
                .highlight_color = (Color) {163, 190, 140, 255},
                .shadow_opacity = 1.0,
                .r = (SHADOW_WIDTH - CARD_WIDTH) / 3.0f,
                .theta = 120.0f,
                .scale = 1.0f,
        };

        while (!WindowShouldClose()) {
                BeginDrawing();

                ClearBackground((Color) {216, 222, 233, 255});

                draw_card(HWATU_APRIL_TANE, style, ((float) image_width)/2.0f, ((float) image_height)/2.0f);

                EndDrawing();
        }

        cleanup();
        CloseWindow();

        return 0;
}
