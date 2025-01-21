#include <stdbool.h>

bool jeuTermine(char *board, int PionRestX, int PionRestO) {
    return PionRestX < 3 || PionRestO < 3;
}
