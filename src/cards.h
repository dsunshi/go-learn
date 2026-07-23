#ifndef CARDS_H
#define CARDS_H

#ifndef CARD_WIDTH
#define CARD_WIDTH  103
#endif

#ifndef CARD_HEIGHT
#define CARD_HEIGHT 168
#endif

#define NUM_CARDS   (12 * 4)

#include "raylib.h"

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

typedef struct Hwatu {
        bool bright;
        bool animal;
        bool ribbon;
        bool junk;
        bool double_junk;
        bool joker;
        unsigned char suit; // Enum?
        Image image; // Pointer to actual image data?
} Hwatu;

// Tane    -> Animal
// Hikari  -> Bright
// Tanzaku -> Ribbon
// Kasu    -> Junk
// Exceptions:
// - May Tane        -> Double Junk
// - September Tane  -> Double Junk
// - November Kasu_2 -> Double Junk
// - December Kasu   -> Double Junk

// April
Hwatu hwatu_april_kasu_1 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 4,
        .image = {
                .data    = HWATU_APRIL_KASU_1_DATA,
                .width   = HWATU_APRIL_KASU_1_WIDTH,
                .height  = HWATU_APRIL_KASU_1_HEIGHT,
                .format  = HWATU_APRIL_KASU_1_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_april_kasu_2 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 4,
        .image = {
                .data    = HWATU_APRIL_KASU_2_DATA,
                .width   = HWATU_APRIL_KASU_2_WIDTH,
                .height  = HWATU_APRIL_KASU_2_HEIGHT,
                .format  = HWATU_APRIL_KASU_2_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_april_tane = {
        .bright = false,
        .animal = true,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 4,
        .image = {
                .data    = HWATU_APRIL_TANE_DATA,
                .width   = HWATU_APRIL_TANE_WIDTH,
                .height  = HWATU_APRIL_TANE_HEIGHT,
                .format  = HWATU_APRIL_TANE_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_april_tanzaku = {
        .bright = false,
        .animal = false,
        .ribbon = true,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 4,
        .image = {
                .data    = HWATU_APRIL_TANZAKU_DATA,
                .width   = HWATU_APRIL_TANZAKU_WIDTH,
                .height  = HWATU_APRIL_TANZAKU_HEIGHT,
                .format  = HWATU_APRIL_TANZAKU_FORMAT,
                .mipmaps = 1
        }
};

// February
Hwatu hwatu_february_kasu_1 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 2,
        .image = {
                .data    = HWATU_FEBRUARY_KASU_1_DATA,
                .width   = HWATU_FEBRUARY_KASU_1_WIDTH,
                .height  = HWATU_FEBRUARY_KASU_1_HEIGHT,
                .format  = HWATU_FEBRUARY_KASU_1_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_february_kasu_2 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 2,
        .image = {
                .data    = HWATU_FEBRUARY_KASU_2_DATA,
                .width   = HWATU_FEBRUARY_KASU_2_WIDTH,
                .height  = HWATU_FEBRUARY_KASU_2_HEIGHT,
                .format  = HWATU_FEBRUARY_KASU_2_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_february_tane = {
        .bright = false,
        .animal = true,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 2,
        .image = {
                .data    = HWATU_FEBRUARY_TANE_DATA,
                .width   = HWATU_FEBRUARY_TANE_WIDTH,
                .height  = HWATU_FEBRUARY_TANE_HEIGHT,
                .format  = HWATU_FEBRUARY_TANE_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_february_tanzaku = {
        .bright = false,
        .animal = false,
        .ribbon = true,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 2,
        .image = {
                .data    = HWATU_FEBRUARY_TANZAKU_DATA,
                .width   = HWATU_FEBRUARY_TANZAKU_WIDTH,
                .height  = HWATU_FEBRUARY_TANZAKU_HEIGHT,
                .format  = HWATU_FEBRUARY_TANZAKU_FORMAT,
                .mipmaps = 1
        }
};

// June
Hwatu hwatu_june_kasu_1 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 6,
        .image = {
                .data    = HWATU_JUNE_KASU_1_DATA,
                .width   = HWATU_JUNE_KASU_1_WIDTH,
                .height  = HWATU_JUNE_KASU_1_HEIGHT,
                .format  = HWATU_JUNE_KASU_1_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_june_kasu_2 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 6,
        .image = {
                .data    = HWATU_JUNE_KASU_2_DATA,
                .width   = HWATU_JUNE_KASU_2_WIDTH,
                .height  = HWATU_JUNE_KASU_2_HEIGHT,
                .format  = HWATU_JUNE_KASU_2_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_june_tane = {
        .bright = false,
        .animal = true,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 6,
        .image = {
                .data    = HWATU_JUNE_TANE_DATA,
                .width   = HWATU_JUNE_TANE_WIDTH,
                .height  = HWATU_JUNE_TANE_HEIGHT,
                .format  = HWATU_JUNE_TANE_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_june_tanzaku = {
        .bright = false,
        .animal = false,
        .ribbon = true,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 6,
        .image = {
                .data    = HWATU_JUNE_TANZAKU_DATA,
                .width   = HWATU_JUNE_TANZAKU_WIDTH,
                .height  = HWATU_JUNE_TANZAKU_HEIGHT,
                .format  = HWATU_JUNE_TANZAKU_FORMAT,
                .mipmaps = 1
        }
};

// July
Hwatu hwatu_july_kasu_1 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 7,
        .image = {
                .data    = HWATU_JULY_KASU_1_DATA,
                .width   = HWATU_JULY_KASU_1_WIDTH,
                .height  = HWATU_JULY_KASU_1_HEIGHT,
                .format  = HWATU_JULY_KASU_1_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_july_kasu_2 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 7,
        .image = {
                .data    = HWATU_JULY_KASU_2_DATA,
                .width   = HWATU_JULY_KASU_2_WIDTH,
                .height  = HWATU_JULY_KASU_2_HEIGHT,
                .format  = HWATU_JULY_KASU_2_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_july_tane = {
        .bright = false,
        .animal = true,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 7,
        .image = {
                .data    = HWATU_JULY_TANE_DATA,
                .width   = HWATU_JULY_TANE_WIDTH,
                .height  = HWATU_JULY_TANE_HEIGHT,
                .format  = HWATU_JULY_TANE_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_july_tanzaku = {
        .bright = false,
        .animal = false,
        .ribbon = true,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 7,
        .image = {
                .data    = HWATU_JULY_TANZAKU_DATA,
                .width   = HWATU_JULY_TANZAKU_WIDTH,
                .height  = HWATU_JULY_TANZAKU_HEIGHT,
                .format  = HWATU_JULY_TANZAKU_FORMAT,
                .mipmaps = 1
        }
};

// October
Hwatu hwatu_october_kasu_1 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 10,
        .image = {
                .data    = HWATU_OCTOBER_KASU_1_DATA,
                .width   = HWATU_OCTOBER_KASU_1_WIDTH,
                .height  = HWATU_OCTOBER_KASU_1_HEIGHT,
                .format  = HWATU_OCTOBER_KASU_1_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_october_kasu_2 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 10,
        .image = {
                .data    = HWATU_OCTOBER_KASU_2_DATA,
                .width   = HWATU_OCTOBER_KASU_2_WIDTH,
                .height  = HWATU_OCTOBER_KASU_2_HEIGHT,
                .format  = HWATU_OCTOBER_KASU_2_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_october_tane = {
        .bright = false,
        .animal = true,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 10,
        .image = {
                .data    = HWATU_OCTOBER_TANE_DATA,
                .width   = HWATU_OCTOBER_TANE_WIDTH,
                .height  = HWATU_OCTOBER_TANE_HEIGHT,
                .format  = HWATU_OCTOBER_TANE_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_october_tanzaku = {
        .bright = false,
        .animal = false,
        .ribbon = true,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 10,
        .image = {
                .data    = HWATU_OCTOBER_TANZAKU_DATA,
                .width   = HWATU_OCTOBER_TANZAKU_WIDTH,
                .height  = HWATU_OCTOBER_TANZAKU_HEIGHT,
                .format  = HWATU_OCTOBER_TANZAKU_FORMAT,
                .mipmaps = 1
        }
};

// January
Hwatu hwatu_january_kasu_1 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 1,
        .image = {
                .data    = HWATU_JANUARY_KASU_1_DATA,
                .width   = HWATU_JANUARY_KASU_1_WIDTH,
                .height  = HWATU_JANUARY_KASU_1_HEIGHT,
                .format  = HWATU_JANUARY_KASU_1_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_january_kasu_2 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 1,
        .image = {
                .data    = HWATU_JANUARY_KASU_2_DATA,
                .width   = HWATU_JANUARY_KASU_2_WIDTH,
                .height  = HWATU_JANUARY_KASU_2_HEIGHT,
                .format  = HWATU_JANUARY_KASU_2_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_january_hikari = {
        .bright = true,
        .animal = false,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 1,
        .image = {
                .data    = HWATU_JANUARY_HIKARI_DATA,
                .width   = HWATU_JANUARY_HIKARI_WIDTH,
                .height  = HWATU_JANUARY_HIKARI_HEIGHT,
                .format  = HWATU_JANUARY_HIKARI_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_january_tanzaku = {
        .bright = false,
        .animal = false,
        .ribbon = true,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 1,
        .image = {
                .data    = HWATU_JANUARY_TANZAKU_DATA,
                .width   = HWATU_JANUARY_TANZAKU_WIDTH,
                .height  = HWATU_JANUARY_TANZAKU_HEIGHT,
                .format  = HWATU_JANUARY_TANZAKU_FORMAT,
                .mipmaps = 1
        }
};

// March
Hwatu hwatu_march_kasu_1 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 3,
        .image = {
                .data    = HWATU_MARCH_KASU_1_DATA,
                .width   = HWATU_MARCH_KASU_1_WIDTH,
                .height  = HWATU_MARCH_KASU_1_HEIGHT,
                .format  = HWATU_MARCH_KASU_1_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_march_kasu_2 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 3,
        .image = {
                .data    = HWATU_MARCH_KASU_2_DATA,
                .width   = HWATU_MARCH_KASU_2_WIDTH,
                .height  = HWATU_MARCH_KASU_2_HEIGHT,
                .format  = HWATU_MARCH_KASU_2_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_march_hikari = {
        .bright = true,
        .animal = false,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 3,
        .image = {
                .data    = HWATU_MARCH_HIKARI_DATA,
                .width   = HWATU_MARCH_HIKARI_WIDTH,
                .height  = HWATU_MARCH_HIKARI_HEIGHT,
                .format  = HWATU_MARCH_HIKARI_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_march_tanzaku = {
        .bright = false,
        .animal = false,
        .ribbon = true,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 3,
        .image = {
                .data    = HWATU_MARCH_TANZAKU_DATA,
                .width   = HWATU_MARCH_TANZAKU_WIDTH,
                .height  = HWATU_MARCH_TANZAKU_HEIGHT,
                .format  = HWATU_MARCH_TANZAKU_FORMAT,
                .mipmaps = 1
        }
};

// August
Hwatu hwatu_august_kasu_1 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 8,
        .image = {
                .data    = HWATU_AUGUST_KASU_1_DATA,
                .width   = HWATU_AUGUST_KASU_1_WIDTH,
                .height  = HWATU_AUGUST_KASU_1_HEIGHT,
                .format  = HWATU_AUGUST_KASU_1_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_august_kasu_2 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 8,
        .image = {
                .data    = HWATU_AUGUST_KASU_2_DATA,
                .width   = HWATU_AUGUST_KASU_2_WIDTH,
                .height  = HWATU_AUGUST_KASU_2_HEIGHT,
                .format  = HWATU_AUGUST_KASU_2_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_august_hikari = {
        .bright = true,
        .animal = false,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 8,
        .image = {
                .data    = HWATU_AUGUST_HIKARI_DATA,
                .width   = HWATU_AUGUST_HIKARI_WIDTH,
                .height  = HWATU_AUGUST_HIKARI_HEIGHT,
                .format  = HWATU_AUGUST_HIKARI_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_august_tane = {
        .bright = false,
        .animal = true,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 8,
        .image = {
                .data    = HWATU_AUGUST_TANE_DATA,
                .width   = HWATU_AUGUST_TANE_WIDTH,
                .height  = HWATU_AUGUST_TANE_HEIGHT,
                .format  = HWATU_AUGUST_TANE_FORMAT,
                .mipmaps = 1
        }
};

// May
Hwatu hwatu_may_kasu_1 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 5,
        .image = {
                .data    = HWATU_MAY_KASU_1_DATA,
                .width   = HWATU_MAY_KASU_1_WIDTH,
                .height  = HWATU_MAY_KASU_1_HEIGHT,
                .format  = HWATU_MAY_KASU_1_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_may_kasu_2 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 5,
        .image = {
                .data    = HWATU_MAY_KASU_2_DATA,
                .width   = HWATU_MAY_KASU_2_WIDTH,
                .height  = HWATU_MAY_KASU_2_HEIGHT,
                .format  = HWATU_MAY_KASU_2_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_may_tane = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = false,
        .double_junk = true,
        .joker = false,
        .suit  = 5,
        .image = {
                .data    = HWATU_MAY_TANE_DATA,
                .width   = HWATU_MAY_TANE_WIDTH,
                .height  = HWATU_MAY_TANE_HEIGHT,
                .format  = HWATU_MAY_TANE_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_may_tanzaku = {
        .bright = false,
        .animal = false,
        .ribbon = true,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 5,
        .image = {
                .data    = HWATU_MAY_TANZAKU_DATA,
                .width   = HWATU_MAY_TANZAKU_WIDTH,
                .height  = HWATU_MAY_TANZAKU_HEIGHT,
                .format  = HWATU_MAY_TANZAKU_FORMAT,
                .mipmaps = 1
        }
};

// September
Hwatu hwatu_september_kasu_1 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 11,
        .image = {
                .data    = HWATU_SEPTEMBER_KASU_1_DATA,
                .width   = HWATU_SEPTEMBER_KASU_1_WIDTH,
                .height  = HWATU_SEPTEMBER_KASU_1_HEIGHT,
                .format  = HWATU_SEPTEMBER_KASU_1_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_september_kasu_2 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 11,
        .image = {
                .data    = HWATU_SEPTEMBER_KASU_2_DATA,
                .width   = HWATU_SEPTEMBER_KASU_2_WIDTH,
                .height  = HWATU_SEPTEMBER_KASU_2_HEIGHT,
                .format  = HWATU_SEPTEMBER_KASU_2_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_september_tane = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = false,
        .double_junk = true,
        .joker = false,
        .suit  = 11,
        .image = {
                .data    = HWATU_SEPTEMBER_TANE_DATA,
                .width   = HWATU_SEPTEMBER_TANE_WIDTH,
                .height  = HWATU_SEPTEMBER_TANE_HEIGHT,
                .format  = HWATU_SEPTEMBER_TANE_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_september_tanzaku = {
        .bright = false,
        .animal = false,
        .ribbon = true,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 11,
        .image = {
                .data    = HWATU_SEPTEMBER_TANZAKU_DATA,
                .width   = HWATU_SEPTEMBER_TANZAKU_WIDTH,
                .height  = HWATU_SEPTEMBER_TANZAKU_HEIGHT,
                .format  = HWATU_SEPTEMBER_TANZAKU_FORMAT,
                .mipmaps = 1
        }
};

// December
Hwatu hwatu_december_tane = {
        .bright = false,
        .animal = true,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 12,
        .image = {
                .data    = HWATU_DECEMBER_TANE_DATA,
                .width   = HWATU_DECEMBER_TANE_WIDTH,
                .height  = HWATU_DECEMBER_TANE_HEIGHT,
                .format  = HWATU_DECEMBER_TANE_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_december_tanzaku = {
        .bright = false,
        .animal = false,
        .ribbon = true,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 12,
        .image = {
                .data    = HWATU_DECEMBER_TANZAKU_DATA,
                .width   = HWATU_DECEMBER_TANZAKU_WIDTH,
                .height  = HWATU_DECEMBER_TANZAKU_HEIGHT,
                .format  = HWATU_DECEMBER_TANZAKU_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_december_kasu = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = false,
        .double_junk = true,
        .joker = false,
        .suit  = 12,
        .image = {
                .data    = HWATU_DECEMBER_KASU_DATA,
                .width   = HWATU_DECEMBER_KASU_WIDTH,
                .height  = HWATU_DECEMBER_KASU_HEIGHT,
                .format  = HWATU_DECEMBER_KASU_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_december_hikari = {
        .bright = true,
        .animal = false,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 12,
        .image = {
                .data    = HWATU_DECEMBER_HIKARI_DATA,
                .width   = HWATU_DECEMBER_HIKARI_WIDTH,
                .height  = HWATU_DECEMBER_HIKARI_HEIGHT,
                .format  = HWATU_DECEMBER_HIKARI_FORMAT,
                .mipmaps = 1
        }
};

// November
Hwatu hwatu_november_kasu_3 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 11,
        .image = {
                .data    = HWATU_NOVEMBER_KASU_3_DATA,
                .width   = HWATU_NOVEMBER_KASU_3_WIDTH,
                .height  = HWATU_NOVEMBER_KASU_3_HEIGHT,
                .format  = HWATU_NOVEMBER_KASU_3_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_november_kasu_2 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = false,
        .double_junk = true,
        .joker = false,
        .suit  = 11,
        .image = {
                .data    = HWATU_NOVEMBER_KASU_2_DATA,
                .width   = HWATU_NOVEMBER_KASU_2_WIDTH,
                .height  = HWATU_NOVEMBER_KASU_2_HEIGHT,
                .format  = HWATU_NOVEMBER_KASU_2_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_november_kasu_1 = {
        .bright = false,
        .animal = false,
        .ribbon = false,
        .junk   = true,
        .double_junk = false,
        .joker = false,
        .suit  = 11,
        .image = {
                .data    = HWATU_NOVEMBER_KASU_1_DATA,
                .width   = HWATU_NOVEMBER_KASU_1_WIDTH,
                .height  = HWATU_NOVEMBER_KASU_1_HEIGHT,
                .format  = HWATU_NOVEMBER_KASU_1_FORMAT,
                .mipmaps = 1
        }
};

Hwatu hwatu_november_hikari = {
        .bright = true,
        .animal = false,
        .ribbon = false,
        .junk   = false,
        .double_junk = false,
        .joker = false,
        .suit  = 11,
        .image = {
                .data    = HWATU_NOVEMBER_HIKARI_DATA,
                .width   = HWATU_NOVEMBER_HIKARI_WIDTH,
                .height  = HWATU_NOVEMBER_HIKARI_HEIGHT,
                .format  = HWATU_NOVEMBER_HIKARI_FORMAT,
                .mipmaps = 1
        }
};

Hwatu *FULL_DECK[NUM_CARDS] = {
        &hwatu_april_kasu_1,
        &hwatu_april_kasu_2,
        &hwatu_april_tane,
        &hwatu_april_tanzaku,
        &hwatu_august_hikari,
        &hwatu_august_kasu_1,
        &hwatu_august_kasu_2,
        &hwatu_august_tane,
        &hwatu_december_hikari,
        &hwatu_december_kasu,
        &hwatu_december_tane,
        &hwatu_december_tanzaku,
        &hwatu_february_kasu_1,
        &hwatu_february_kasu_2,
        &hwatu_february_tane,
        &hwatu_february_tanzaku,
        &hwatu_january_hikari,
        &hwatu_january_kasu_1,
        &hwatu_january_kasu_2,
        &hwatu_january_tanzaku,
        &hwatu_july_kasu_1,
        &hwatu_july_kasu_2,
        &hwatu_july_tane,
        &hwatu_july_tanzaku,
        &hwatu_june_kasu_1,
        &hwatu_june_kasu_2,
        &hwatu_june_tane,
        &hwatu_june_tanzaku,
        &hwatu_march_hikari,
        &hwatu_march_kasu_1,
        &hwatu_march_kasu_2,
        &hwatu_march_tanzaku,
        &hwatu_may_kasu_1,
        &hwatu_may_kasu_2,
        &hwatu_may_tane,
        &hwatu_may_tanzaku,
        &hwatu_november_hikari,
        &hwatu_november_kasu_1,
        &hwatu_november_kasu_2,
        &hwatu_november_kasu_3,
        &hwatu_october_kasu_1,
        &hwatu_october_kasu_2,
        &hwatu_october_tane,
        &hwatu_october_tanzaku,
        &hwatu_september_kasu_1,
        &hwatu_september_kasu_2,
        &hwatu_september_tane,
        &hwatu_september_tanzaku
};


#endif /* CARDS_H */
