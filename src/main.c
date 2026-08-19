
#include "raylib.h"
#include "cards.h"
#include "assert.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
/* #include "raymath.h" */
/* #include "stdio.h" */
/* #include "stdlib.h" */

#define GET_BIT(number, n) (((number) >> (n)) & 0x01)
#define SET_BIT(number, n) ( (number) |= (0x01 << (n)))

#define GET_BIT_4(number, n) (((number) >> (n)) & 0x0F)
#define SET_BIT_4(number, val, n) ( (number) |= (((val) & 0x0F) << (n)))

#define GET_BIT_6(number, n) (((number) >> (n)) & 0x3F)
#define SET_BIT_6(number, val, n) ( (number) |= (((val) & 0x3F) << (n)))

#define GET_INDEX(number)       GET_BIT_6((number),        0)
#define SET_INDEX(number, val)  SET_BIT_6((number), (val), 0)
#define GET_SUIT(number)        GET_BIT_4((number),        6)
#define SET_SUIT(number,  val)  SET_BIT_4((number), (val), 6)
#define GET_JUNK(number)        GET_BIT((number),   10)
#define SET_JUNK(number)        SET_BIT((number),   10)
#define GET_DOUBLE_JUNK(number) GET_BIT((number),   11)
#define SET_DOUBLE_JUNK(number) SET_BIT((number),   11)
#define GET_BRIGHT(number)      GET_BIT((number),   12)
#define SET_BRIGHT(number)      SET_BIT((number),   12)
#define GET_ANIMAL(number)      GET_BIT((number),   13)
#define SET_ANIMAL(number)      SET_BIT((number),   13)
#define GET_RIBBON(number)      GET_BIT((number),   14)
#define SET_RIBBON(number)      SET_BIT((number),   14)
#define GET_JOKER(number)       GET_BIT((number),   15)
#define SET_JOKER(number)       SET_BIT((number),   15)

#define HWATU_JANUARY_HIKARI    0x1040
#define HWATU_JANUARY_KASU_1    0x0441
#define HWATU_JANUARY_KASU_2    0x0442
#define HWATU_JANUARY_TANZAKU   0x4043
#define HWATU_FEBRUARY_KASU_1   0x0484
#define HWATU_FEBRUARY_KASU_2   0x0485
#define HWATU_FEBRUARY_TANE     0x2086
#define HWATU_FEBRUARY_TANZAKU  0x4087
#define HWATU_MARCH_HIKARI      0x10C8
#define HWATU_MARCH_KASU_1      0x04C9
#define HWATU_MARCH_KASU_2      0x04CA
#define HWATU_MARCH_TANZAKU     0x40CB
#define HWATU_APRIL_KASU_1      0x050C
#define HWATU_APRIL_KASU_2      0x050D
#define HWATU_APRIL_TANE        0x210E
#define HWATU_APRIL_TANZAKU     0x410F
#define HWATU_MAY_TANZAKU       0x4150
#define HWATU_MAY_KASU_1        0x0551
#define HWATU_MAY_KASU_2        0x0552
#define HWATU_MAY_TANE          0x0953
#define HWATU_JUNE_KASU_1       0x0594
#define HWATU_JUNE_KASU_2       0x0595
#define HWATU_JUNE_TANE         0x2196
#define HWATU_JUNE_TANZAKU      0x4197
#define HWATU_JULY_KASU_1       0x05D8
#define HWATU_JULY_KASU_2       0x05D9
#define HWATU_JULY_TANE         0x21DA
#define HWATU_JULY_TANZAKU      0x41DB
#define HWATU_AUGUST_HIKARI     0x121C
#define HWATU_AUGUST_KASU_1     0x061D
#define HWATU_AUGUST_KASU_2     0x061E
#define HWATU_AUGUST_TANE       0x221F
#define HWATU_SEPTEMBER_KASU_1  0x06E0
#define HWATU_SEPTEMBER_KASU_2  0x06E1
#define HWATU_SEPTEMBER_TANE    0x0AE2
#define HWATU_SEPTEMBER_TANZAKU 0x42E3
#define HWATU_OCTOBER_KASU_1    0x06A4
#define HWATU_OCTOBER_KASU_2    0x06A5
#define HWATU_OCTOBER_TANE      0x22A6
#define HWATU_OCTOBER_TANZAKU   0x42A7
#define HWATU_NOVEMBER_HIKARI   0x12E8
#define HWATU_NOVEMBER_KASU_1   0x06E9
#define HWATU_NOVEMBER_KASU_2   0x0AEA
#define HWATU_NOVEMBER_KASU_3   0x06EB
#define HWATU_DECEMBER_HIKARI   0x132C
#define HWATU_DECEMBER_KASU     0x0B2D
#define HWATU_DECEMBER_TANE     0x232E
#define HWATU_DECEMBER_TANZAKU  0x432f

void test_define(const Hwatu h, const unsigned int i, const unsigned int n) {
        assert(h.bright      == (GET_BRIGHT(i)));
        assert(h.animal      == (GET_ANIMAL(i)));
        assert(h.ribbon      == (GET_RIBBON(i)));
        assert(h.junk        == (GET_JUNK(i)));
        assert(h.double_junk == (GET_DOUBLE_JUNK(i)));
        assert(h.joker       == (GET_JOKER(i)));
        assert(h.suit        == GET_SUIT(i));
        assert(n             == GET_INDEX(i));
}

unsigned int build_define(const Hwatu h, const unsigned int i) {
        unsigned int result = 0x00;

        if (h.bright) {
                SET_BRIGHT(result);
        }
        if (h.animal) {
                SET_ANIMAL(result);
        }
        if (h.ribbon) {
                SET_RIBBON(result);
        }
        if (h.junk) {
                SET_JUNK(result);
        }
        if (h.double_junk) {
                SET_DOUBLE_JUNK(result);
        }
        if (h.joker) {
                SET_JOKER(result);
        }

        SET_SUIT(result,  h.suit);
        SET_INDEX(result, i);

        return result;
}
/* typedef struct Hwatu { */
/*         bool bright; */
/*         bool animal; */
/*         bool ribbon; */
/*         bool junk; */
/*         bool double_junk; */
/*         bool joker; */
/*         unsigned char suit; // Enum? */
/*         Image image; // Pointer to actual image data? */
/* } Hwatu; */

int main(void) {
        int gap = CARD_WIDTH / 2;
        int image_width  = 5 * gap + 4 * CARD_WIDTH;
        int image_height = CARD_HEIGHT * 2;

        InitWindow(image_width, image_height, "Card drawing example");

        Texture2D textures[NUM_CARDS];

        for (int j; j < NUM_CARDS; j++) {
                textures[j] = LoadTextureFromImage(FULL_DECK[j]->image);
        }

        test_define(hwatu_january_hikari,HWATU_JANUARY_HIKARI   ,     0);
        test_define(hwatu_january_kasu_1,HWATU_JANUARY_KASU_1   ,     1);
        test_define(hwatu_january_kasu_2,HWATU_JANUARY_KASU_2   ,     2);
        test_define(hwatu_january_tanzaku,HWATU_JANUARY_TANZAKU  ,    3);
        test_define(hwatu_february_kasu_1,HWATU_FEBRUARY_KASU_1   ,     4);
        test_define(hwatu_february_kasu_2,HWATU_FEBRUARY_KASU_2   ,     5);
        test_define(hwatu_february_tane,HWATU_FEBRUARY_TANE     ,       6);
        test_define(hwatu_february_tanzaku,HWATU_FEBRUARY_TANZAKU  ,    7);
        test_define(hwatu_march_hikari,HWATU_MARCH_HIKARI      ,     8);
        test_define(hwatu_march_kasu_1,HWATU_MARCH_KASU_1      ,     9);
        test_define(hwatu_march_kasu_2,HWATU_MARCH_KASU_2      ,     10);
        test_define(hwatu_march_tanzaku,HWATU_MARCH_TANZAKU     ,    11);
        test_define(hwatu_april_kasu_1,HWATU_APRIL_KASU_1     ,      12);
        test_define(hwatu_april_kasu_2,HWATU_APRIL_KASU_2     ,      13);
        test_define(hwatu_april_tane,HWATU_APRIL_TANE       ,        14);
        test_define(hwatu_april_tanzaku,HWATU_APRIL_TANZAKU    ,     15);
        test_define(hwatu_may_tanzaku,HWATU_MAY_TANZAKU      ,    16);
        test_define(hwatu_may_kasu_1,HWATU_MAY_KASU_1       ,     17);
        test_define(hwatu_may_kasu_2,HWATU_MAY_KASU_2       ,     18);
        test_define(hwatu_may_tane,HWATU_MAY_TANE         ,       19);
        test_define(hwatu_june_kasu_1,HWATU_JUNE_KASU_1      ,     20);
        test_define(hwatu_june_kasu_2,HWATU_JUNE_KASU_2      ,     21);
        test_define(hwatu_june_tane,HWATU_JUNE_TANE        ,       22);
        test_define(hwatu_june_tanzaku,HWATU_JUNE_TANZAKU     ,    23);
        test_define(hwatu_july_kasu_1,HWATU_JULY_KASU_1      ,     24);
        test_define(hwatu_july_kasu_2,HWATU_JULY_KASU_2      ,     25);
        test_define(hwatu_july_tane,HWATU_JULY_TANE        ,       26);
        test_define(hwatu_july_tanzaku,HWATU_JULY_TANZAKU     ,    27);
        test_define(hwatu_august_hikari,HWATU_AUGUST_HIKARI    ,     28);
        test_define(hwatu_august_kasu_1,HWATU_AUGUST_KASU_1    ,     29);
        test_define(hwatu_august_kasu_2,HWATU_AUGUST_KASU_2    ,     30);
        test_define(hwatu_august_tane,HWATU_AUGUST_TANE      ,       31);
        test_define(hwatu_september_kasu_1,HWATU_SEPTEMBER_KASU_1 ,     32);
        test_define(hwatu_september_kasu_2,HWATU_SEPTEMBER_KASU_2 ,     33);
        test_define(hwatu_september_tane,HWATU_SEPTEMBER_TANE   ,       34);
        test_define(hwatu_september_tanzaku,HWATU_SEPTEMBER_TANZAKU ,   35);
        test_define(hwatu_october_kasu_1,HWATU_OCTOBER_KASU_1   ,     36);
        test_define(hwatu_october_kasu_2,HWATU_OCTOBER_KASU_2   ,     37);
        test_define(hwatu_october_tane,HWATU_OCTOBER_TANE     ,       38);
        test_define(hwatu_october_tanzaku,HWATU_OCTOBER_TANZAKU  ,    39);
        test_define(hwatu_november_hikari,HWATU_NOVEMBER_HIKARI  ,     40);
        test_define(hwatu_november_kasu_1,HWATU_NOVEMBER_KASU_1  ,     41);
        test_define(hwatu_november_kasu_2,HWATU_NOVEMBER_KASU_2  ,     42);
        test_define(hwatu_november_kasu_3,HWATU_NOVEMBER_KASU_3  ,     43);
        test_define(hwatu_december_hikari,HWATU_DECEMBER_HIKARI  ,   44);
        test_define(hwatu_december_kasu,HWATU_DECEMBER_KASU    ,     45);
        test_define(hwatu_december_tane,HWATU_DECEMBER_TANE    ,     46);
        test_define(hwatu_december_tanzaku,HWATU_DECEMBER_TANZAKU ,  47);

        return 0;

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
