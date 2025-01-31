#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "protomove.h"
#define taille 24

// Définition de la fonction pour la phase de vol
void flyingPhase(char board[], char pionActuel, char *nomJoueurActuel) {
    int currentPosition, newPosition;

    // Demander la position actuelle du pion à déplacer
    printf("%s (%c), vous êtes en phase de vol. Vous pouvez déplacer n'importe quel pion.\n", nomJoueurActuel, pionActuel);
    printf("Entrez la position actuelle du pion à déplacer (0-%d) : ", taille - 1);
    if (scanf("%d", &currentPosition) != 1 || currentPosition < 0 || currentPosition >= taille) {
        printf("Position invalide. Veuillez entrer un nombre entre 0 et %d.\n", taille - 1);
        while (getchar() != '\n'); // Vider le buffer d'entrée
        return;
    }

    // Vérifier si la position actuelle contient un pion du joueur
    if (board[currentPosition] != pionActuel) {
        printf("La position actuelle ne contient pas votre pion. Veuillez réessayer.\n");
        return;
    }

    // Demander la nouvelle position
    printf("Entrez la nouvelle position (0-%d) : ", taille - 1);
    if (scanf("%d", &newPosition) != 1 || newPosition < 0 || newPosition >= taille) {
        printf("Position invalide. Veuillez entrer un nombre entre 0 et %d.\n", taille - 1);
        while (getchar() != '\n'); // Vider le buffer d'entrée
        return;
    }

    // Vérifier si la nouvelle position est vide
    if (board[newPosition] != '*') {
        printf("La nouvelle position est déjà occupée. Veuillez choisir une autre position.\n");
        return;
    }

    // Déplacer le pion
    board[currentPosition] = '*'; // Libérer l'ancienne position
    board[newPosition] = pionActuel; // Placer le pion à la nouvelle position

    printf("Pion déplacé de la position %d à la position %d.\n", currentPosition, newPosition);
}