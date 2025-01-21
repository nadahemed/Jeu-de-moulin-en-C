#ifndef PROTOMOVE_H
#define PROTOMOVE_H
#define taille 24
#include <stdbool.h>
void retirePion(char board[], char pionAdverse);
int estMoulin(char board[], int position, char pion);
bool jeuTermine(char *board, int PionRestX, int PionRestO);

#endif

