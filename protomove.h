#ifndef PROTOMOVE_H
#define PROTOMOVE_H
#define taille 24
#include <stdbool.h>


void retirePion(char board[], char pionAdverse);
int estMoulin(char board[], int position, char pion);
bool jeuTermine(char *board, int PionRestX, int PionRestO);
int evaluer_plateau(char board[], char pionMachine, char pionAdverse);
int minMax(char board[], int profondeur, bool maximiser, char pionActuel, char pionAdverse);
int trouverMeilleurCoup(char board[], char pionActuel, char pionAdverse);
void retirePionmch(char board[], char pionAdverse);
void sauvegarderJeu(char board[], int joueurActuel, int PionRestX, int PionRestO, int movesX, int movesO, int moulinsX, int moulinsO, char joueur1[], char joueur2[]);
void flyingPhase(char board[], char pionActuel, char *nomJoueurActuel);
bool chargerJeu(char board[], int *joueurActuel, int *PionRestX, int *PionRestO, int *movesX, int *movesO, int *moulinsX, int *moulinsO, char joueur1[], char joueur2[]);
int estMoulinmch(char board[], int position, char pion);


#endif

