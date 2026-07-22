
#include "raylib.h"

int main(int argc, char *argv[]) {
        // TODO Argument parsing/handling
        (void) (argc);

        Image image = LoadImage(argv[1]);

        if (!IsImageValid(image)) {
                // TODO Error
        }

        if (!ExportImageAsCode(image, argv[2])) {
                // TODO Error
        }

        UnloadImage(image);

        return 0;
}
