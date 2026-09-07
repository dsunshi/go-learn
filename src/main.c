
#include "raylib.h"

#include "cards.h"

extern Texture2D CARD_TEXTURES[NUM_CARDS];

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

        float h = (float) image_width/2.0f;
        float k = (float) image_height/2.0f;

        Rectangle src = {0.0f, 0.0f, (float) CARD_WIDTH, (float) CARD_HEIGHT};
        Rectangle dst = {h, k,
                         (float) CARD_WIDTH, (float) CARD_HEIGHT};
        Vector2   org = {(float) CARD_WIDTH, (float) CARD_HEIGHT};

        float rot = 15.0f;

        float ox = h - CARD_WIDTH/2.0f;
        float oy = k - CARD_HEIGHT/2.0f;

        float xp = (ox - h) * cos(rot) - (oy - k) * sin(rot) + h;
        float yp = (ox - h) * sin(rot) + (oy - k) * cos(rot) + k;
        float dx = ox - xp;
        float dy = oy - yp;

        while (!WindowShouldClose()) {
                BeginDrawing();

                ClearBackground((Color) {216, 222, 233, 255});

                Texture2D image = CARD_TEXTURES[GET_INDEX(HWATU_APRIL_TANE)];
                rot = 15 * 3.14 / 180.0f;
                xp = (ox - h) * cos(rot) - (oy - k) * sin(rot) + h;
                yp = (ox - h) * sin(rot) + (oy - k) * cos(rot) + k;
                dx = ox - xp;
                dy = oy - yp;
                dst = (Rectangle) {h + CARD_WIDTH/2.0f + dx, k + CARD_HEIGHT/2.0f + dy, (float) CARD_WIDTH, (float) CARD_HEIGHT};
                rot = 15;
                DrawTexturePro(image, src, dst, org, rot, WHITE);

                DrawLine((int)ox, 0, (int)ox, image_height, RED);
                DrawLine(0, (int)oy, image_width, (int)oy, RED);
                
                DrawLine((int)xp, 0, (int)xp, image_height, BLUE);
                DrawLine(0, (int)yp, image_width, (int)yp, BLUE);
                
                /* rot = 5.0f; */
                /* xp = (ox - h) * cos(rot) - (oy - k) * sin(rot) + h; */
                /* yp = (ox - h) * sin(rot) + (oy - k) * cos(rot) + k; */
                /* dx = ox - xp; */
                /* dy = oy - yp; */
                /* dst = (Rectangle) {h + dx, k + dy, (float) CARD_WIDTH, (float) CARD_HEIGHT}; */
                /* image = CARD_TEXTURES[GET_INDEX(HWATU_MAY_TANE)]; */
                /* DrawTexturePro(image, src, dst, org, rot, WHITE); */
                
                /* rot = -15.0f; */
                /* xp = (ox - h) * cos(rot) - (oy - k) * sin(rot) + h; */
                /* yp = (ox - h) * sin(rot) + (oy - k) * cos(rot) + k; */
                /* dx = ox - xp; */
                /* dy = oy - yp; */
                /* dst = (Rectangle) {h + dx, k + dy, (float) CARD_WIDTH, (float) CARD_HEIGHT}; */
                /* image = CARD_TEXTURES[GET_INDEX(HWATU_JUNE_TANE)]; */
                /* DrawTexturePro(image, src, dst, org, rot, WHITE); */

                DrawLine((int)image_width/2, 0, (int)image_width/2, image_height, GRAY);
                DrawLine(0, (int)image_height/2, image_width, (int)image_height/2, GRAY);
                /* draw_card(HWATU_APRIL_TANE, style, ); */
                EndDrawing();
        }

        cleanup();
        CloseWindow();

        return 0;
}
