#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "protomove.h"
#include "grille.h"
#include <stdbool.h>
#include "sauvmch1.c"
#include <time.h>
#define FICHIER_SAUVEGARDE2 "fichiermch.txt"
#define taille 24
#define MAX_PIONS 9

int getmachine() {
    int position;
    char board[taille];
    const char *rouge = "\033[1;31m"; // Rouge pour le joueur humain
    const char *bleu = "\033[1;34m";  // Bleu pour la machine
    const char *reset = "\033[0m";    // Réinitialisation des couleurs
    int joueurActuel = 1; // 1 pour le joueur humain, 2 pour la machine
    int PionRestX = MAX_PIONS;
    int PionRestO = MAX_PIONS;
    int movesX = 0;
    int movesO = 0;
    int moulinsX = 0;
    int moulinsO = 0;
    char nomJoueur[50]; // Nom du joueur humain
    bool quitter = false; // Drapeau pour indiquer si le joueur a quitté

    // Demander si le joueur veut charger une sauvegarde
    printf("%sVoulez-vous charger la partie sauvegardée ? (o/n) : %s", rouge, reset);
    char choix;
    scanf(" %c", &choix);

    if (choix == 'o' || choix == 'O') {
        if (!chargerJeumch1(board, &joueurActuel, &PionRestX, &PionRestO, &movesX, &movesO, &moulinsX, &moulinsO, nomJoueur)) {
            // Si le chargement échoue, initialiser une nouvelle partie
            printf("%sDémarrage d'une nouvelle partie.%s\n", rouge, reset);
            for (int i = 0; i < taille; i++) {
                board[i] = '*';
            }
            printf("%sEntrez votre nom : %s", rouge, reset);
            scanf("%s", nomJoueur);
        }
    } else {
        // Initialisation d'une nouvelle partie
        for (int i = 0; i < taille; i++) {
            board[i] = '*';
        }
        printf("%sEntrez votre nom : %s", rouge, reset);
        scanf("%s", nomJoueur);
    }

    // Afficher la grille initiale
    printf("%sLa grille initiale est : %s\n", rouge, reset);
    Board(board);
    printf("\n");

    while (!quitter) {
        char pionActuel = (joueurActuel == 1) ? 'X' : 'O';
        char pionAdverse = (joueurActuel == 1) ? 'O' : 'X';
        int *PionRestAdverse = (joueurActuel == 1) ? &PionRestO : &PionRestX;
        int *currentMoves = (joueurActuel == 1) ? &movesX : &movesO;

        // Vérifier si le joueur actuel est en phase de vol
        bool isFlyingPhase = (joueurActuel == 1 && PionRestX == 3) || (joueurActuel == 2 && PionRestO == 3);

        // Tour du joueur humain
        if (joueurActuel == 1) {
            if (isFlyingPhase) {
                printf("%s%s (%c), vous êtes en phase de vol. Vous pouvez déplacer n'importe quel pion.%s\n", rouge, nomJoueur, pionActuel, reset);
                printf("%sEntrez la position actuelle du pion à déplacer (0-%d) ou -1 pour quitter : %s", rouge, taille - 1, reset);
                if (scanf("%d", &position) != 1 || position < -1 || position >= taille) {
                    printf("%sPosition invalide. Veuillez entrer un nombre entre 0 et %d, ou -1 pour quitter.%s\n", rouge, taille - 1, reset);
                    while (getchar() != '\n');
                    continue;
                }

                if (position == -1) {
                    printf("%s%s (%c) a décidé de quitter le jeu. Merci d'avoir joué !%s\n", rouge, nomJoueur, pionActuel, reset);
                    quitter = true;
                    break;
                }

                // Vérifier si la position actuelle contient un pion du joueur
                if (board[position] != pionActuel) {
                    printf("%sLa position actuelle ne contient pas votre pion. Veuillez réessayer.%s\n", rouge, reset);
                    continue;
                }

                // Demander la nouvelle position
                printf("%sEntrez la nouvelle position (0-%d) : %s", rouge, taille - 1, reset);
                if (scanf("%d", &position) != 1 || position < 0 || position >= taille) {
                    printf("%sPosition invalide. Veuillez entrer un nombre entre 0 et %d.%s\n", rouge, taille - 1, reset);
                    while (getchar() != '\n');
                    continue;
                }

                // Vérifier si la nouvelle position est vide
                if (board[position] != '*') {
                    printf("%sLa nouvelle position est déjà occupée. Veuillez choisir une autre position.%s\n", rouge, reset);
                    continue;
                }

                // Déplacer le pion
                board[position] = pionActuel;
            } else {
                printf("%s%s (%c), entrez une position (0-%d) ou -1 pour quitter : %s", rouge, nomJoueur, pionActuel, taille - 1, reset);
                if (scanf("%d", &position) != 1 || position < -1 || position >= taille) {
                    printf("%sPosition invalide. Veuillez entrer un nombre entre 0 et %d, ou -1 pour quitter.%s\n", rouge, taille - 1, reset);
                    while (getchar() != '\n');
                    continue;
                }

                if (position == -1) {
                    printf("%s%s (%c) a décidé de quitter le jeu. Merci d'avoir joué !%s\n", rouge, nomJoueur, pionActuel, reset);
                    quitter = true;
                    break;
                }

                // Vérifier si la position est libre
                if (board[position] != '*') {
                    printf("%sLa position est déjà occupée. Veuillez choisir une autre position.%s\n", rouge, reset);
                    continue;
                }

                // Placer le pion
                board[position] = pionActuel;
                (*currentMoves)++;
            }
        }
        // Tour de la machine (joueur 2)
        else {
            if (isFlyingPhase) {
                // Phase de vol : déplacer un pion existant
                do {
                    position = rand() % taille; // Choisir une position aléatoire
                } while (board[position] != pionActuel); // Trouver un pion de la machine
                printf("%sLa machine (%c) déplace un pion de la position %d.%s\n", bleu, pionActuel, position, reset);

                int nouvellePosition;
                do {
                    nouvellePosition = rand() % taille; // Choisir une nouvelle position aléatoire
                } while (board[nouvellePosition] != '*'); // Trouver une position vide
                printf("%sLa machine (%c) déplace le pion vers la position %d.%s\n", bleu, pionActuel, nouvellePosition, reset);

                // Déplacer le pion
                board[position] = '*';
                board[nouvellePosition] = pionActuel;
            } else {
                // Phase normale : placer un nouveau pion
                do {
                    position = rand() % taille; // Choisir une position aléatoire
                } while (board[position] != '*'); // Trouver une position vide
                printf("%sLa machine (%c) choisit la position %d.%s\n", bleu, pionActuel, position, reset);

                // Placer le pion
                board[position] = pionActuel;
                (*currentMoves)++;
            }
        }

        // Afficher le plateau après chaque tour
        Board(board);
        printf("\n");

        // Vérifier si un moulin est formé
        if (estMoulin(board, position, pionActuel)) {
            printf("%sMoulin formé par %s (%c) !%s\n", (joueurActuel == 1) ? rouge : bleu, (joueurActuel == 1) ? nomJoueur : "La machine", pionActuel, reset);

            // Mettre à jour le compteur de moulins
            if (joueurActuel == 1) {
                moulinsX++;
            } else {
                moulinsO++;
            }

            // Retirer un pion adverse
            if (joueurActuel == 1) {
                int posAdverse;
                while (true) {
                    printf("%sChoisissez une position de la machine (%c) à retirer : %s", rouge, pionAdverse, reset);
                    if (scanf("%d", &posAdverse) != 1 || posAdverse < 0 || posAdverse >= taille) {
                        printf("%sPosition invalide. Veuillez entrer un nombre entre 0 et %d.%s\n", rouge, taille - 1, reset);
                        while (getchar() != '\n');
                        continue;
                    }

                    if (board[posAdverse] == pionAdverse) {
                        board[posAdverse] = '*';
                        printf("%sPion de la machine retiré à la position %d.%s\n", rouge, posAdverse, reset);
                        (*PionRestAdverse)--;
                        break;
                    } else {
                        printf("%sLa position choisie n'est pas occupée par un pion adverse.%s\n", rouge, reset);
                    }
                }
            } else {
                // La machine retire un pion adverse aléatoirement
                int posAdverse;
                do {
                    posAdverse = rand() % taille; // Choisir une position aléatoire
                } while (board[posAdverse] != pionAdverse); // Trouver un pion adverse
                printf("%sLa machine (%c) retire un pion adverse à la position %d.%s\n", bleu, pionActuel, posAdverse, reset);
                board[posAdverse] = '*';
                (*PionRestAdverse)--;
            }

            // Vérifier si l'adversaire a moins de 3 pions
            if (*PionRestAdverse < 3) {
                printf("%s%s (%c) a gagné !%s\n", (joueurActuel == 1) ? rouge : bleu, (joueurActuel == 1) ? nomJoueur : "La machine", pionActuel, reset);
                return 0;
            }
        }

        // Vérifier si les deux joueurs ont épuisé leurs mouvements
        if (movesX >= MAX_PIONS && movesO >= MAX_PIONS) {
            printf("%sLes deux joueurs ont épuisé leurs mouvements.%s\n", rouge, reset);

            if (moulinsX > moulinsO) {
                printf("%s%s (X) a gagné avec %d moulins contre %d moulins pour O.%s\n", rouge, nomJoueur, moulinsX, moulinsO, reset);
            } else if (moulinsO > moulinsX) {
                printf("%sLa machine (O) a gagné avec %d moulins contre %d moulins pour X.%s\n", bleu, moulinsO, moulinsX, reset);
            } else {
                printf("%sMatch nul ! Les deux joueurs ont formé %d moulins.%s\n", rouge, moulinsX, reset);
            }

            return 0;
        }

        // Sauvegarder l'état du jeu après chaque tour
        sauvegarderJeumch1(board, joueurActuel, PionRestX, PionRestO, movesX, movesO, moulinsX, moulinsO, nomJoueur);

        // Passer au joueur suivant
        joueurActuel = 3 - joueurActuel;
    }

    return 0;
}






