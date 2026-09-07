
#ifndef CARDS_H
#define CARDS_H

#ifndef CARD_WIDTH
#define CARD_WIDTH 200 
#endif

#ifndef CARD_HEIGHT
#define CARD_HEIGHT 326
#endif

#ifndef SHADOW_WIDTH
#define SHADOW_WIDTH  250
#endif

#ifndef SHADOW_HEIGHT
#define SHADOW_HEIGHT 407
#endif

#define MONTHS             12
#define CARDS_PER_MONTH    4
#define JOKERS             0
#define NUM_CARDS          (MONTHS * CARDS_PER_MONTH + JOKERS)

#include "raylib.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "Hwatu_April_Kasu_1.h"
#include "Hwatu_April_Kasu_2.h"
#include "Hwatu_April_Tane.h"
#include "Hwatu_April_Tanzaku.h"
#include "Hwatu_August_Hikari.h"
#include "Hwatu_August_Kasu_1.h"
#include "Hwatu_August_Kasu_2.h"
#include "Hwatu_August_Tane.h"
#include "Hwatu_December_Hikari.h"
#include "Hwatu_December_Kasu.h"
#include "Hwatu_December_Tane.h"
#include "Hwatu_December_Tanzaku.h"
#include "Hwatu_February_Kasu_1.h"
#include "Hwatu_February_Kasu_2.h"
#include "Hwatu_February_Tane.h"
#include "Hwatu_February_Tanzaku.h"
#include "Hwatu_January_Hikari.h"
#include "Hwatu_January_Kasu_1.h"
#include "Hwatu_January_Kasu_2.h"
#include "Hwatu_January_Tanzaku.h"
#include "Hwatu_July_Kasu_1.h"
#include "Hwatu_July_Kasu_2.h"
#include "Hwatu_July_Tane.h"
#include "Hwatu_July_Tanzaku.h"
#include "Hwatu_June_Kasu_1.h"
#include "Hwatu_June_Kasu_2.h"
#include "Hwatu_June_Tane.h"
#include "Hwatu_June_Tanzaku.h"
#include "Hwatu_March_Hikari.h"
#include "Hwatu_March_Kasu_1.h"
#include "Hwatu_March_Kasu_2.h"
#include "Hwatu_March_Tanzaku.h"
#include "Hwatu_May_Kasu_1.h"
#include "Hwatu_May_Kasu_2.h"
#include "Hwatu_May_Tane.h"
#include "Hwatu_May_Tanzaku.h"
#include "Hwatu_November_Hikari.h"
#include "Hwatu_November_Kasu_1.h"
#include "Hwatu_November_Kasu_2.h"
#include "Hwatu_November_Kasu_3.h"
#include "Hwatu_October_Kasu_1.h"
#include "Hwatu_October_Kasu_2.h"
#include "Hwatu_October_Tane.h"
#include "Hwatu_October_Tanzaku.h"
#include "Hwatu_September_Kasu_1.h"
#include "Hwatu_September_Kasu_2.h"
#include "Hwatu_September_Tane.h"
#include "Hwatu_September_Tanzaku.h"
#include "shadow.h"

#define GET_BIT(number, n) (((number) >> (n)) & 0x01)
#define SET_BIT(number, n) ( (number) |= (0x01 << (n)))

#define GET_BIT_4(number, n) (((number) >> (n)) & 0x0F)
#define SET_BIT_4(number, val, n) ( (number) |= (((val) & 0x0F) << (n)))

#define GET_BIT_6(number, n) (((number) >> (n)) & 0x3F)
#define SET_BIT_6(number, val, n) ( (number) |= (((val) & 0x3F) << (n)))

#define GET_ANIMAL(number)      GET_BIT((number),   13)
#define GET_BRIGHT(number)      GET_BIT((number),   12)
#define GET_DOUBLE_JUNK(number) GET_BIT((number),   11)
#define GET_INDEX(number)       GET_BIT_6((number),  0)
#define GET_JOKER(number)       GET_BIT((number),   15)
#define GET_JUNK(number)        GET_BIT((number),   10)
#define GET_RIBBON(number)      GET_BIT((number),   14)
#define GET_SUIT(number)        GET_BIT_4((number),  6)

#define SET_ANIMAL(number)      SET_BIT((number),   13)
#define SET_BRIGHT(number)      SET_BIT((number),   12)
#define SET_DOUBLE_JUNK(number) SET_BIT((number),   11)
#define SET_INDEX(number, val)  SET_BIT_6((number), (val), 0)
#define SET_JOKER(number)       SET_BIT((number),   15)
#define SET_JUNK(number)        SET_BIT((number),   10)
#define SET_RIBBON(number)      SET_BIT((number),   14)
#define SET_SUIT(number,  val)  SET_BIT_4((number), (val), 6)

#define HWATU_JANUARY_HIKARI       ((unsigned int) 0x1040)
#define HWATU_JANUARY_KASU_1       ((unsigned int) 0x0441)
#define HWATU_JANUARY_KASU_2       ((unsigned int) 0x0442)
#define HWATU_JANUARY_TANZAKU      ((unsigned int) 0x4043)
#define HWATU_FEBRUARY_KASU_1      ((unsigned int) 0x0484)
#define HWATU_FEBRUARY_KASU_2      ((unsigned int) 0x0485)
#define HWATU_FEBRUARY_TANE        ((unsigned int) 0x2086)
#define HWATU_FEBRUARY_TANZAKU     ((unsigned int) 0x4087)
#define HWATU_MARCH_HIKARI         ((unsigned int) 0x10C8)
#define HWATU_MARCH_KASU_1         ((unsigned int) 0x04C9)
#define HWATU_MARCH_KASU_2         ((unsigned int) 0x04CA)
#define HWATU_MARCH_TANZAKU        ((unsigned int) 0x40CB)
#define HWATU_APRIL_KASU_1         ((unsigned int) 0x050C)
#define HWATU_APRIL_KASU_2         ((unsigned int) 0x050D)
#define HWATU_APRIL_TANE           ((unsigned int) 0x210E)
#define HWATU_APRIL_TANZAKU        ((unsigned int) 0x410F)
#define HWATU_MAY_TANZAKU          ((unsigned int) 0x4150)
#define HWATU_MAY_KASU_1           ((unsigned int) 0x0551)
#define HWATU_MAY_KASU_2           ((unsigned int) 0x0552)
#define HWATU_MAY_TANE             ((unsigned int) 0x0953)
#define HWATU_JUNE_KASU_1          ((unsigned int) 0x0594)
#define HWATU_JUNE_KASU_2          ((unsigned int) 0x0595)
#define HWATU_JUNE_TANE            ((unsigned int) 0x2196)
#define HWATU_JUNE_TANZAKU         ((unsigned int) 0x4197)
#define HWATU_JULY_KASU_1          ((unsigned int) 0x05D8)
#define HWATU_JULY_KASU_2          ((unsigned int) 0x05D9)
#define HWATU_JULY_TANE            ((unsigned int) 0x21DA)
#define HWATU_JULY_TANZAKU         ((unsigned int) 0x41DB)
#define HWATU_AUGUST_HIKARI        ((unsigned int) 0x121C)
#define HWATU_AUGUST_KASU_1        ((unsigned int) 0x061D)
#define HWATU_AUGUST_KASU_2        ((unsigned int) 0x061E)
#define HWATU_AUGUST_TANE          ((unsigned int) 0x221F)
#define HWATU_SEPTEMBER_KASU_1     ((unsigned int) 0x0660)
#define HWATU_SEPTEMBER_KASU_2     ((unsigned int) 0x0661)
#define HWATU_SEPTEMBER_TANE       ((unsigned int) 0x0A62)
#define HWATU_SEPTEMBER_TANZAKU    ((unsigned int) 0x4263)
#define HWATU_OCTOBER_KASU_1       ((unsigned int) 0x06A4)
#define HWATU_OCTOBER_KASU_2       ((unsigned int) 0x06A5)
#define HWATU_OCTOBER_TANE         ((unsigned int) 0x22A6)
#define HWATU_OCTOBER_TANZAKU      ((unsigned int) 0x42A7)
#define HWATU_NOVEMBER_HIKARI      ((unsigned int) 0x12E8)
#define HWATU_NOVEMBER_KASU_1      ((unsigned int) 0x06E9)
#define HWATU_NOVEMBER_KASU_2      ((unsigned int) 0x0AEA)
#define HWATU_NOVEMBER_KASU_3      ((unsigned int) 0x06EB)
#define HWATU_DECEMBER_HIKARI      ((unsigned int) 0x132C)
#define HWATU_DECEMBER_KASU        ((unsigned int) 0x0B2D)
#define HWATU_DECEMBER_TANE        ((unsigned int) 0x232E)
#define HWATU_DECEMBER_TANZAKU     ((unsigned int) 0x432F)

#define SUIT_ANY                   (0x0F)

typedef int (* match_fn)(unsigned int, unsigned int);

typedef struct CardStyle {
        bool  draw_highlight;
        bool  draw_shadow;
        bool  draw_card;
        Color highlight_color;
        float shadow_opacity;
        float r;
        float theta;
        float scale;
} CardStyle;

void init();
void cleanup();
int except_suit(unsigned int suit, unsigned int card);
int and_match(unsigned int mask, unsigned int card);
int or_match(unsigned int mask, unsigned int card);
unsigned int* find_images(unsigned int mask, match_fn match, int *length);
void shuffle(int *array, size_t n);
void draw_card(unsigned int card, CardStyle style, float center_x, float center_y);

static const unsigned int CARDS[NUM_CARDS] = {
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

static const Image IMAGE_DECK[NUM_CARDS] = {
    {
        .data    = HWATU_JANUARY_HIKARI_DATA,
        .width   = HWATU_JANUARY_HIKARI_WIDTH,
        .height  = HWATU_JANUARY_HIKARI_HEIGHT,
        .format  = HWATU_JANUARY_HIKARI_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_JANUARY_KASU_1_DATA,
        .width   = HWATU_JANUARY_KASU_1_WIDTH,
        .height  = HWATU_JANUARY_KASU_1_HEIGHT,
        .format  = HWATU_JANUARY_KASU_1_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_JANUARY_KASU_2_DATA,
        .width   = HWATU_JANUARY_KASU_2_WIDTH,
        .height  = HWATU_JANUARY_KASU_2_HEIGHT,
        .format  = HWATU_JANUARY_KASU_2_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_JANUARY_TANZAKU_DATA,
        .width   = HWATU_JANUARY_TANZAKU_WIDTH,
        .height  = HWATU_JANUARY_TANZAKU_HEIGHT,
        .format  = HWATU_JANUARY_TANZAKU_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_FEBRUARY_KASU_1_DATA,
        .width   = HWATU_FEBRUARY_KASU_1_WIDTH,
        .height  = HWATU_FEBRUARY_KASU_1_HEIGHT,
        .format  = HWATU_FEBRUARY_KASU_1_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_FEBRUARY_KASU_2_DATA,
        .width   = HWATU_FEBRUARY_KASU_2_WIDTH,
        .height  = HWATU_FEBRUARY_KASU_2_HEIGHT,
        .format  = HWATU_FEBRUARY_KASU_2_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_FEBRUARY_TANE_DATA,
        .width   = HWATU_FEBRUARY_TANE_WIDTH,
        .height  = HWATU_FEBRUARY_TANE_HEIGHT,
        .format  = HWATU_FEBRUARY_TANE_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_FEBRUARY_TANZAKU_DATA,
        .width   = HWATU_FEBRUARY_TANZAKU_WIDTH,
        .height  = HWATU_FEBRUARY_TANZAKU_HEIGHT,
        .format  = HWATU_FEBRUARY_TANZAKU_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_MARCH_HIKARI_DATA,
        .width   = HWATU_MARCH_HIKARI_WIDTH,
        .height  = HWATU_MARCH_HIKARI_HEIGHT,
        .format  = HWATU_MARCH_HIKARI_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_MARCH_KASU_1_DATA,
        .width   = HWATU_MARCH_KASU_1_WIDTH,
        .height  = HWATU_MARCH_KASU_1_HEIGHT,
        .format  = HWATU_MARCH_KASU_1_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_MARCH_KASU_2_DATA,
        .width   = HWATU_MARCH_KASU_2_WIDTH,
        .height  = HWATU_MARCH_KASU_2_HEIGHT,
        .format  = HWATU_MARCH_KASU_2_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_MARCH_TANZAKU_DATA,
        .width   = HWATU_MARCH_TANZAKU_WIDTH,
        .height  = HWATU_MARCH_TANZAKU_HEIGHT,
        .format  = HWATU_MARCH_TANZAKU_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_APRIL_KASU_1_DATA,
        .width   = HWATU_APRIL_KASU_1_WIDTH,
        .height  = HWATU_APRIL_KASU_1_HEIGHT,
        .format  = HWATU_APRIL_KASU_1_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_APRIL_KASU_2_DATA,
        .width   = HWATU_APRIL_KASU_2_WIDTH,
        .height  = HWATU_APRIL_KASU_2_HEIGHT,
        .format  = HWATU_APRIL_KASU_2_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_APRIL_TANE_DATA,
        .width   = HWATU_APRIL_TANE_WIDTH,
        .height  = HWATU_APRIL_TANE_HEIGHT,
        .format  = HWATU_APRIL_TANE_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_APRIL_TANZAKU_DATA,
        .width   = HWATU_APRIL_TANZAKU_WIDTH,
        .height  = HWATU_APRIL_TANZAKU_HEIGHT,
        .format  = HWATU_APRIL_TANZAKU_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_MAY_TANZAKU_DATA,
        .width   = HWATU_MAY_TANZAKU_WIDTH,
        .height  = HWATU_MAY_TANZAKU_HEIGHT,
        .format  = HWATU_MAY_TANZAKU_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_MAY_KASU_1_DATA,
        .width   = HWATU_MAY_KASU_1_WIDTH,
        .height  = HWATU_MAY_KASU_1_HEIGHT,
        .format  = HWATU_MAY_KASU_1_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_MAY_KASU_2_DATA,
        .width   = HWATU_MAY_KASU_2_WIDTH,
        .height  = HWATU_MAY_KASU_2_HEIGHT,
        .format  = HWATU_MAY_KASU_2_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_MAY_TANE_DATA,
        .width   = HWATU_MAY_TANE_WIDTH,
        .height  = HWATU_MAY_TANE_HEIGHT,
        .format  = HWATU_MAY_TANE_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_JUNE_KASU_1_DATA,
        .width   = HWATU_JUNE_KASU_1_WIDTH,
        .height  = HWATU_JUNE_KASU_1_HEIGHT,
        .format  = HWATU_JUNE_KASU_1_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_JUNE_KASU_2_DATA,
        .width   = HWATU_JUNE_KASU_2_WIDTH,
        .height  = HWATU_JUNE_KASU_2_HEIGHT,
        .format  = HWATU_JUNE_KASU_2_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_JUNE_TANE_DATA,
        .width   = HWATU_JUNE_TANE_WIDTH,
        .height  = HWATU_JUNE_TANE_HEIGHT,
        .format  = HWATU_JUNE_TANE_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_JUNE_TANZAKU_DATA,
        .width   = HWATU_JUNE_TANZAKU_WIDTH,
        .height  = HWATU_JUNE_TANZAKU_HEIGHT,
        .format  = HWATU_JUNE_TANZAKU_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_JULY_KASU_1_DATA,
        .width   = HWATU_JULY_KASU_1_WIDTH,
        .height  = HWATU_JULY_KASU_1_HEIGHT,
        .format  = HWATU_JULY_KASU_1_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_JULY_KASU_2_DATA,
        .width   = HWATU_JULY_KASU_2_WIDTH,
        .height  = HWATU_JULY_KASU_2_HEIGHT,
        .format  = HWATU_JULY_KASU_2_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_JULY_TANE_DATA,
        .width   = HWATU_JULY_TANE_WIDTH,
        .height  = HWATU_JULY_TANE_HEIGHT,
        .format  = HWATU_JULY_TANE_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_JULY_TANZAKU_DATA,
        .width   = HWATU_JULY_TANZAKU_WIDTH,
        .height  = HWATU_JULY_TANZAKU_HEIGHT,
        .format  = HWATU_JULY_TANZAKU_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_AUGUST_HIKARI_DATA,
        .width   = HWATU_AUGUST_HIKARI_WIDTH,
        .height  = HWATU_AUGUST_HIKARI_HEIGHT,
        .format  = HWATU_AUGUST_HIKARI_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_AUGUST_KASU_1_DATA,
        .width   = HWATU_AUGUST_KASU_1_WIDTH,
        .height  = HWATU_AUGUST_KASU_1_HEIGHT,
        .format  = HWATU_AUGUST_KASU_1_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_AUGUST_KASU_2_DATA,
        .width   = HWATU_AUGUST_KASU_2_WIDTH,
        .height  = HWATU_AUGUST_KASU_2_HEIGHT,
        .format  = HWATU_AUGUST_KASU_2_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_AUGUST_TANE_DATA,
        .width   = HWATU_AUGUST_TANE_WIDTH,
        .height  = HWATU_AUGUST_TANE_HEIGHT,
        .format  = HWATU_AUGUST_TANE_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_SEPTEMBER_KASU_1_DATA,
        .width   = HWATU_SEPTEMBER_KASU_1_WIDTH,
        .height  = HWATU_SEPTEMBER_KASU_1_HEIGHT,
        .format  = HWATU_SEPTEMBER_KASU_1_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_SEPTEMBER_KASU_2_DATA,
        .width   = HWATU_SEPTEMBER_KASU_2_WIDTH,
        .height  = HWATU_SEPTEMBER_KASU_2_HEIGHT,
        .format  = HWATU_SEPTEMBER_KASU_2_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_SEPTEMBER_TANE_DATA,
        .width   = HWATU_SEPTEMBER_TANE_WIDTH,
        .height  = HWATU_SEPTEMBER_TANE_HEIGHT,
        .format  = HWATU_SEPTEMBER_TANE_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_SEPTEMBER_TANZAKU_DATA,
        .width   = HWATU_SEPTEMBER_TANZAKU_WIDTH,
        .height  = HWATU_SEPTEMBER_TANZAKU_HEIGHT,
        .format  = HWATU_SEPTEMBER_TANZAKU_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_OCTOBER_KASU_1_DATA,
        .width   = HWATU_OCTOBER_KASU_1_WIDTH,
        .height  = HWATU_OCTOBER_KASU_1_HEIGHT,
        .format  = HWATU_OCTOBER_KASU_1_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_OCTOBER_KASU_2_DATA,
        .width   = HWATU_OCTOBER_KASU_2_WIDTH,
        .height  = HWATU_OCTOBER_KASU_2_HEIGHT,
        .format  = HWATU_OCTOBER_KASU_2_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_OCTOBER_TANE_DATA,
        .width   = HWATU_OCTOBER_TANE_WIDTH,
        .height  = HWATU_OCTOBER_TANE_HEIGHT,
        .format  = HWATU_OCTOBER_TANE_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_OCTOBER_TANZAKU_DATA,
        .width   = HWATU_OCTOBER_TANZAKU_WIDTH,
        .height  = HWATU_OCTOBER_TANZAKU_HEIGHT,
        .format  = HWATU_OCTOBER_TANZAKU_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_NOVEMBER_HIKARI_DATA,
        .width   = HWATU_NOVEMBER_HIKARI_WIDTH,
        .height  = HWATU_NOVEMBER_HIKARI_HEIGHT,
        .format  = HWATU_NOVEMBER_HIKARI_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_NOVEMBER_KASU_1_DATA,
        .width   = HWATU_NOVEMBER_KASU_1_WIDTH,
        .height  = HWATU_NOVEMBER_KASU_1_HEIGHT,
        .format  = HWATU_NOVEMBER_KASU_1_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_NOVEMBER_KASU_2_DATA,
        .width   = HWATU_NOVEMBER_KASU_2_WIDTH,
        .height  = HWATU_NOVEMBER_KASU_2_HEIGHT,
        .format  = HWATU_NOVEMBER_KASU_2_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_NOVEMBER_KASU_3_DATA,
        .width   = HWATU_NOVEMBER_KASU_3_WIDTH,
        .height  = HWATU_NOVEMBER_KASU_3_HEIGHT,
        .format  = HWATU_NOVEMBER_KASU_3_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_DECEMBER_HIKARI_DATA,
        .width   = HWATU_DECEMBER_HIKARI_WIDTH,
        .height  = HWATU_DECEMBER_HIKARI_HEIGHT,
        .format  = HWATU_DECEMBER_HIKARI_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_DECEMBER_KASU_DATA,
        .width   = HWATU_DECEMBER_KASU_WIDTH,
        .height  = HWATU_DECEMBER_KASU_HEIGHT,
        .format  = HWATU_DECEMBER_KASU_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_DECEMBER_TANE_DATA,
        .width   = HWATU_DECEMBER_TANE_WIDTH,
        .height  = HWATU_DECEMBER_TANE_HEIGHT,
        .format  = HWATU_DECEMBER_TANE_FORMAT,
        .mipmaps = 1
    },
    {
        .data    = HWATU_DECEMBER_TANZAKU_DATA,
        .width   = HWATU_DECEMBER_TANZAKU_WIDTH,
        .height  = HWATU_DECEMBER_TANZAKU_HEIGHT,
        .format  = HWATU_DECEMBER_TANZAKU_FORMAT,
        .mipmaps = 1
    }
};

static const Image SHADOW_IMG = {
        .data    = SHADOW_DATA,
        .width   = SHADOW_WIDTH,
        .height  = SHADOW_HEIGHT,
        .format  = SHADOW_FORMAT,
        .mipmaps = 1
};

#endif /* CARDS_H */
