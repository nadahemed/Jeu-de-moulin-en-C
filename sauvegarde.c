#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grille.h"
#include "protomove.h"
#define taille 24
#define FICHIER_SAUVEGARDE "sauvegarde.txt"

// Fonction pour sauvegarder l'état du jeu
void sauvegarderJeu(char board[], int joueurActuel, int PionRestX, int PionRestO, int movesX, int movesO, int moulinsX, int moulinsO, char joueur1[], char joueur2[]) {
    FILE *fichier = fopen(FICHIER_SAUVEGARDE, "w");
    if (fichier == NULL) {
        printf("Erreur : impossible de sauvegarder la partie.\n");
        return;
    }

    // Sauvegarder la grille
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
    fprintf(fichier, "%s\n", joueur1);
    fprintf(fichier, "%s\n", joueur2);

    fclose(fichier);
    printf("Partie sauvegardée avec succès.\n");
}

// Fonction pour charger l'état du jeu
bool chargerJeu(char board[], int *joueurActuel, int *PionRestX, int *PionRestO, int *movesX, int *movesO, int *moulinsX, int *moulinsO, char joueur1[], char joueur2[]) {
    FILE *fichier = fopen(FICHIER_SAUVEGARDE, "r");
    if (fichier == NULL) {
        printf("Aucune sauvegarde trouvée.\n");
        return false;
    }

    // Charger la grille
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
    fscanf(fichier, "%s", joueur1);
    fscanf(fichier, "%s", joueur2);

    fclose(fichier);
    printf("Partie chargée avec succès.\n");
    return true;
}