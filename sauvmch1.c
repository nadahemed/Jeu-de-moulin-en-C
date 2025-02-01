#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FICHIER_SAUVEGARDE2 "fichiermch.txt"
#include "grille.h"
#include "protomove.h"
#define taille 24


bool chargerJeumch1(char board[], int *joueurActuel, int *PionRestX, int *PionRestO, int *movesX, int *movesO, int *moulinsX, int *moulinsO, char nomJoueur[]) {
    FILE *fichier = fopen(FICHIER_SAUVEGARDE2, "r");
    if (fichier == NULL) {
        printf("Aucune sauvegarde trouvée.\n");
        return false;
    }

    // Charger l'état du plateau
    for (int i = 0; i < taille; i++) {
        fscanf(fichier, " %c", &board[i]);
    }

    // Charger les autres données
    fscanf(fichier, "%d", joueurActuel);
    fscanf(fichier, "%d", PionRestX);
    fscanf(fichier, "%d", PionRestO);
    fscanf(fichier, "%d", movesX);
    fscanf(fichier, "%d", movesO);
    fscanf(fichier, "%d", moulinsX);
    fscanf(fichier, "%d", moulinsO);
    fscanf(fichier, "%s", nomJoueur);

    fclose(fichier);
    printf("Partie chargée avec succès.\n");
    return true;
}

void sauvegarderJeumch1(char board[], int joueurActuel, int PionRestX, int PionRestO, int movesX, int movesO, int moulinsX, int moulinsO, char nomJoueur[]) {
    FILE *fichier = fopen(FICHIER_SAUVEGARDE2, "w");
    if (fichier == NULL) {
        printf("Erreur lors de la sauvegarde du jeu.\n");
        return;
    }

    // Sauvegarder l'état du plateau
    for (int i = 0; i < taille; i++) {
        fprintf(fichier, "%c", board[i]);
    }
    fprintf(fichier, "\n");

    // Sauvegarder les autres données
    fprintf(fichier, "%d\n", joueurActuel);
    fprintf(fichier, "%d\n", PionRestX);
    fprintf(fichier, "%d\n", PionRestO);
    fprintf(fichier, "%d\n", movesX);
    fprintf(fichier, "%d\n", movesO);
    fprintf(fichier, "%d\n", moulinsX);
    fprintf(fichier, "%d\n", moulinsO);
    fprintf(fichier, "%s\n", nomJoueur);

    fclose(fichier);
    printf("Partie sauvegardée avec succès.\n");
}