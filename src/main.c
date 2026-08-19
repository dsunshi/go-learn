
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

#define GET_ANIMAL(number)      GET_BIT((number),   13)
#define GET_BRIGHT(number)      GET_BIT((number),   12)
#define GET_DOUBLE_JUNK(number) GET_BIT((number),   11)
#define GET_INDEX(number)       GET_BIT_6((number),        0)
#define GET_JOKER(number)       GET_BIT((number),   15)
#define GET_JUNK(number)        GET_BIT((number),   10)
#define GET_RIBBON(number)      GET_BIT((number),   14)
#define GET_SUIT(number)        GET_BIT_4((number),        6)
#define SET_ANIMAL(number)      SET_BIT((number),   13)
#define SET_BRIGHT(number)      SET_BIT((number),   12)
#define SET_DOUBLE_JUNK(number) SET_BIT((number),   11)
#define SET_INDEX(number, val)  SET_BIT_6((number), (val), 0)
#define SET_JOKER(number)       SET_BIT((number),   15)
#define SET_JUNK(number)        SET_BIT((number),   10)
#define SET_RIBBON(number)      SET_BIT((number),   14)
#define SET_SUIT(number,  val)  SET_BIT_4((number), (val), 6)

#define HWATU_JANUARY_HIKARI    ((unsigned int) 0x1040)
#define HWATU_JANUARY_KASU_1    ((unsigned int) 0x0441)
#define HWATU_JANUARY_KASU_2    ((unsigned int) 0x0442)
#define HWATU_JANUARY_TANZAKU   ((unsigned int) 0x4043)
#define HWATU_FEBRUARY_KASU_1   ((unsigned int) 0x0484)
#define HWATU_FEBRUARY_KASU_2   ((unsigned int) 0x0485)
#define HWATU_FEBRUARY_TANE     ((unsigned int) 0x2086)
#define HWATU_FEBRUARY_TANZAKU  ((unsigned int) 0x4087)
#define HWATU_MARCH_HIKARI      ((unsigned int) 0x10C8)
#define HWATU_MARCH_KASU_1      ((unsigned int) 0x04C9)
#define HWATU_MARCH_KASU_2      ((unsigned int) 0x04CA)
#define HWATU_MARCH_TANZAKU     ((unsigned int) 0x40CB)
#define HWATU_APRIL_KASU_1      ((unsigned int) 0x050C)
#define HWATU_APRIL_KASU_2      ((unsigned int) 0x050D)
#define HWATU_APRIL_TANE        ((unsigned int) 0x210E)
#define HWATU_APRIL_TANZAKU     ((unsigned int) 0x410F)
#define HWATU_MAY_TANZAKU       ((unsigned int) 0x4150)
#define HWATU_MAY_KASU_1        ((unsigned int) 0x0551)
#define HWATU_MAY_KASU_2        ((unsigned int) 0x0552)
#define HWATU_MAY_TANE          ((unsigned int) 0x0953)
#define HWATU_JUNE_KASU_1       ((unsigned int) 0x0594)
#define HWATU_JUNE_KASU_2       ((unsigned int) 0x0595)
#define HWATU_JUNE_TANE         ((unsigned int) 0x2196)
#define HWATU_JUNE_TANZAKU      ((unsigned int) 0x4197)
#define HWATU_JULY_KASU_1       ((unsigned int) 0x05D8)
#define HWATU_JULY_KASU_2       ((unsigned int) 0x05D9)
#define HWATU_JULY_TANE         ((unsigned int) 0x21DA)
#define HWATU_JULY_TANZAKU      ((unsigned int) 0x41DB)
#define HWATU_AUGUST_HIKARI     ((unsigned int) 0x121C)
#define HWATU_AUGUST_KASU_1     ((unsigned int) 0x061D)
#define HWATU_AUGUST_KASU_2     ((unsigned int) 0x061E)
#define HWATU_AUGUST_TANE       ((unsigned int) 0x221F)
#define HWATU_SEPTEMBER_KASU_1  ((unsigned int) 0x06E0)
#define HWATU_SEPTEMBER_KASU_2  ((unsigned int) 0x06E1)
#define HWATU_SEPTEMBER_TANE    ((unsigned int) 0x0AE2)
#define HWATU_SEPTEMBER_TANZAKU ((unsigned int) 0x42E3)
#define HWATU_OCTOBER_KASU_1    ((unsigned int) 0x06A4)
#define HWATU_OCTOBER_KASU_2    ((unsigned int) 0x06A5)
#define HWATU_OCTOBER_TANE      ((unsigned int) 0x22A6)
#define HWATU_OCTOBER_TANZAKU   ((unsigned int) 0x42A7)
#define HWATU_NOVEMBER_HIKARI   ((unsigned int) 0x12E8)
#define HWATU_NOVEMBER_KASU_1   ((unsigned int) 0x06E9)
#define HWATU_NOVEMBER_KASU_2   ((unsigned int) 0x0AEA)
#define HWATU_NOVEMBER_KASU_3   ((unsigned int) 0x06EB)
#define HWATU_DECEMBER_HIKARI   ((unsigned int) 0x132C)
#define HWATU_DECEMBER_KASU     ((unsigned int) 0x0B2D)
#define HWATU_DECEMBER_TANE     ((unsigned int) 0x232E)
#define HWATU_DECEMBER_TANZAKU  ((unsigned int) 0x432f)

const unsigned int CARDS[NUM_CARDS] = {
        HWATU_JANUARY_HIKARI,
        HWATU_JANUARY_KASU_1,
        HWATU_JANUARY_KASU_2,
        HWATU_JANUARY_TANZAKU,
        HWATU_FEBRUARY_KASU_1,
        HWATU_FEBRUARY_KASU_2,
        HWATU_FEBRUARY_TANE,
        HWATU_FEBRUARY_TANZAKU,
        HWATU_MARCH_HIKARI,
        HWATU_MARCH_KASU_1,
        HWATU_MARCH_KASU_2,
        HWATU_MARCH_TANZAKU,
        HWATU_APRIL_KASU_1,
        HWATU_APRIL_KASU_2,
        HWATU_APRIL_TANE,
        HWATU_APRIL_TANZAKU,
        HWATU_MAY_TANZAKU,
        HWATU_MAY_KASU_1,
        HWATU_MAY_KASU_2,
        HWATU_MAY_TANE,
        HWATU_JUNE_KASU_1,
        HWATU_JUNE_KASU_2,
        HWATU_JUNE_TANE,
        HWATU_JUNE_TANZAKU,
        HWATU_JULY_KASU_1,
        HWATU_JULY_KASU_2,
        HWATU_JULY_TANE,
        HWATU_JULY_TANZAKU,
        HWATU_AUGUST_HIKARI,
        HWATU_AUGUST_KASU_1,
        HWATU_AUGUST_KASU_2,
        HWATU_AUGUST_TANE,
        HWATU_SEPTEMBER_KASU_1,
        HWATU_SEPTEMBER_KASU_2,
        HWATU_SEPTEMBER_TANE,
        HWATU_SEPTEMBER_TANZAKU,
        HWATU_OCTOBER_KASU_1,
        HWATU_OCTOBER_KASU_2,
        HWATU_OCTOBER_TANE,
        HWATU_OCTOBER_TANZAKU,
        HWATU_NOVEMBER_HIKARI,
        HWATU_NOVEMBER_KASU_1,
        HWATU_NOVEMBER_KASU_2,
        HWATU_NOVEMBER_KASU_3,
        HWATU_DECEMBER_HIKARI,
        HWATU_DECEMBER_KASU,
        HWATU_DECEMBER_TANE,
        HWATU_DECEMBER_TANZAKU
};
        
void test_define(const Hwatu h, const unsigned int i, const unsigned int n);
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

unsigned int build_define(const Hwatu h, const unsigned int i);
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

int is_match(unsigned int mask, unsigned int card) {
        if (GET_SUIT(mask) == GET_SUIT(card)) {
                return 1;
        } else {
                unsigned int mask_flags = mask >> 10;
                unsigned int card_flags = card >> 10;

                return (mask_flags & card_flags);
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
                if (is_match(mask, CARDS[i])) {
                        size++;
                }
        }

        int *arr = (int*) malloc(size * sizeof(int));

        if (arr == NULL) {
                printf("[ERROR] Failed to allocate!");
                *length = 0;
                return NULL;
        }
        
        *length = 0;
        for (int i = 0; i < NUM_CARDS; i++) {
                if (is_match(mask, CARDS[i])) {
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

        /* Texture2D textures[NUM_CARDS]; */

        /* for (int j; j < NUM_CARDS; j++) { */
        /*         textures[j] = LoadTextureFromImage(FULL_DECK[j]->image); */
        /* } */


        /* float sliderValue = 0.0f; */
        /* int month; */

        int mask   = 0x00;
        int length = 0x00;
        /* SET_ANIMAL(mask); */
        /* SET_BRIGHT(mask); */
        /* SET_DOUBLE_JUNK(mask); */
        /* SET_JOKER(mask); */
        /* SET_JUNK(mask); */
        SET_RIBBON(mask);
        /* SET_SUIT(mask, 1); */

        int *matches = find_images(mask, &length);

        float scale = ((float) MAX_CARDS / (float) length) * 0.5f;
        Texture2D *textures = (Texture2D *) malloc(length * sizeof(Texture2D));

        for (int i = 0; i < length; i++) {
                textures[i] = LoadTextureFromImage(IMAGE_DECK[matches[i]]);
        }
        
        printf("Found %d matches!\n", length);

        while (!WindowShouldClose()) {
                BeginDrawing();

                ClearBackground(RAYWHITE);

                /* month = ((int) sliderValue); */

                for (int i = 0; i < length; i++) {
                        int x = i*image_width/length + ((int)  gap * scale);
                        int y = image_height/2 - ((int) CARD_HEIGHT * scale);
                        DrawTextureEx(textures[i], (Vector2) {x, y}, 0.0f, scale, WHITE); 
                        /* DrawTexture(MONTHS[month][i], x, y, WHITE); */
                }

                /* GuiSliderBar((Rectangle){ gap, (CARD_HEIGHT/2 - CARD_HEIGHT/4)/2, image_width - gap * 2, CARD_HEIGHT/4 }, "1", "12", &sliderValue, 0.0f, 11.0f); */
                EndDrawing();
        }

        for (int i = 0; i < length; i++) {
                UnloadTexture(textures[i]);
        }
        free(matches);

        // Unload resources
        /* for (int i = 0; i < NUM_CARDS; i++) { */
        /*         UnloadTexture(textures[i]); */
        /* } */
        
        // TODO Need to unload images?
        /* UnloadImage(<image>); */
        CloseWindow();

        return 0;
}
