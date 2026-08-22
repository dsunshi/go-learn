
cards = [
        "hwatu_january_hikari",
        "hwatu_january_kasu_1",
        "hwatu_january_kasu_2",
        "hwatu_january_tanzaku",
        "hwatu_february_kasu_1",
        "hwatu_february_kasu_2",
        "hwatu_february_tane",
        "hwatu_february_tanzaku",
        "hwatu_march_hikari",
        "hwatu_march_kasu_1",
        "hwatu_march_kasu_2",
        "hwatu_march_tanzaku",
        "hwatu_april_kasu_1",
        "hwatu_april_kasu_2",
        "hwatu_april_tane",
        "hwatu_april_tanzaku",
        "hwatu_may_tanzaku",
        "hwatu_may_kasu_1",
        "hwatu_may_kasu_2",
        "hwatu_may_tane",
        "hwatu_june_kasu_1",
        "hwatu_june_kasu_2",
        "hwatu_june_tane",
        "hwatu_june_tanzaku",
        "hwatu_july_kasu_1",
        "hwatu_july_kasu_2",
        "hwatu_july_tane",
        "hwatu_july_tanzaku",
        "hwatu_august_hikari",
        "hwatu_august_kasu_1",
        "hwatu_august_kasu_2",
        "hwatu_august_tane",
        "hwatu_september_kasu_1",
        "hwatu_september_kasu_2",
        "hwatu_september_tane",
        "hwatu_september_tanzaku",
        "hwatu_october_kasu_1",
        "hwatu_october_kasu_2",
        "hwatu_october_tane",
        "hwatu_october_tanzaku",
        "hwatu_november_hikari",
        "hwatu_november_kasu_1",
        "hwatu_november_kasu_2",
        "hwatu_november_kasu_3",
        "hwatu_december_hikari",
        "hwatu_december_kasu",
        "hwatu_december_tane",
        "hwatu_december_tanzaku"
]

print("Image *IMAGE_DECK[NUM_CARDS] = {")
for card in cards:
        print("    {")
        print(f"        .data    = {card.upper()}_DATA,")
        print(f"        .width   = {card.upper()}_WIDTH,")
        print(f"        .height  = {card.upper()}_HEIGHT,")
        print(f"        .format  = {card.upper()}_FORMAT,")
        print(f"        .mipmaps = 1")
        print("    },")
print("};")
