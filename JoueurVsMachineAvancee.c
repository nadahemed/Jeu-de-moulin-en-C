#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "protomove.h"
#include "grille.h"
#include "sauvmachine.c"
#include "meilleurcoupvol.c"
#include <stdbool.h>
#include <time.h>
#define taille 24
#define MAX_PIONS 9
#define FICHIER_SAUVEGARDE1 "fichierAI.txt"
#define TIME_LIMIT 30 // Temps limite en secondes

int getmachineAI() {
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";   
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 
    int position;
    char board[taille];
    int joueurActuel = 1; // 1 pour le joueur humain, 2 pour la machine
    int PionRestX = MAX_PIONS;
    int PionRestO = MAX_PIONS;
    int movesX = 0;
    int movesO = 0;
    int moulinsX = 0;
    int moulinsO = 0;
    char nomJoueur[50]; // Nom du joueur humain
    bool quitter = false; // Drapeau pour indiquer si le joueur a quitté
    bool enableDisplacement = false; // Mode de déplacement activé ou désactivé

    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));

    // Demander le mode de jeu
    printf("Choisissez le mode de jeu :\n");
    printf(bleu);
    printf("1. Mode Match Nul (pas de déplacement après placement des pions)\n");
    printf(reset);
    printf(rouge);
    printf("2. Mode Déplacement (déplacement des pions après placement)\n");
    printf(reset);
    printf("Votre choix (1 ou 2) : ");
    printf(reset);
    int choixMode;
    scanf("%d", &choixMode);
    if (choixMode == 2) {
        enableDisplacement = true;
        printf(bleu);
        printf("Mode Déplacement activé.\n");
        printf(reset);
    } else {
        printf(rouge);
        printf("Mode Match Nul activé.\n");
        printf(reset);
    }

    // Demander si le joueur veut charger une sauvegarde
    printf(rouge);
    printf("Voulez-vous charger la partie sauvegardée ? (o/n) : ");
    printf(reset);
    char choix;
    scanf(" %c", &choix);

    if (choix == 'o' || choix == 'O') {
        if (!chargerJeumch(board, &joueurActuel, &PionRestX, &PionRestO, &movesX, &movesO, &moulinsX, &moulinsO, nomJoueur)) {
            // Si le chargement échoue, initialiser une nouvelle partie
            printf(rouge);
            printf("Démarrage d'une nouvelle partie.\n");
            printf(reset);
            for (int i = 0; i < taille; i++) {
                board[i] = '*';
            }
            printf(rouge);
            printf("Entrez votre nom : ");
            printf(reset);
            scanf("%s", nomJoueur);
        }
    } else {
        // Initialisation d'une nouvelle partie
        for (int i = 0; i < taille; i++) {
            board[i] = '*';
        }
        printf(bleu);
        printf("Entrez votre nom : ");
        printf(reset);
        scanf("%s", nomJoueur);

        // Demander si le joueur veut choisir aléatoirement qui commence
        printf(bleu);
        printf("Voulez-vous que le premier joueur soit choisi aléatoirement ? (o/n) : ");
        printf(reset);
        char choixCommence;
        scanf(" %c", &choixCommence);

        if (choixCommence == 'o' || choixCommence == 'O') {
            // Choisir aléatoirement qui commence
            joueurActuel = (rand() % 2) + 1; // 1 ou 2
            printf(rouge);
            printf("Le joueur %d (%s) commence.\n", joueurActuel, (joueurActuel == 1) ? nomJoueur : "la machine");
            printf(reset);
        } else {
            // Par défaut, le joueur humain commence
            joueurActuel = 1;
            printf(rouge);
            printf("Vous commencez la partie.\n");
            printf(reset);
        }
    }

    // Afficher la grille initiale
    printf(bleu);
    printf("La grille initiale est : \n");
    printf(reset);
    Board(board);
    printf("\n");

    while (!quitter) {
        char pionActuel = (joueurActuel == 1) ? 'X' : 'O';
        char pionAdverse = (joueurActuel == 1) ? 'O' : 'X';
        int *PionRestAdverse = (joueurActuel == 1) ? &PionRestO : &PionRestX;
        int *currentMoves = (joueurActuel == 1) ? &movesX : &movesO;

        // Afficher les pions restants
        printf(bleu);
        printf("%s (X) : %d pions restants\n", nomJoueur, PionRestX);
        printf(reset);
        printf(rouge);
        printf("Machine (O) : %d pions restants\n", PionRestO);
        printf(reset);

        // Vérification si tous les pions ont été placés
        bool isPlacementPhase = (movesX < MAX_PIONS || movesO < MAX_PIONS);

        // Tour du joueur humain
        if (joueurActuel == 1) {
            if (isPlacementPhase) {
                // Phase de placement
                printf(bleu);
                printf("%s (%c), entrez une position (0-%d) ou -1 pour quitter : ", nomJoueur, pionActuel, taille - 1);
                printf(reset);

                // Mesurer le temps
                time_t debut = time(NULL);
                int result = scanf("%d", &position);
                time_t fin = time(NULL);

                // Vérifier si le temps est dépassé
                if (difftime(fin, debut) > TIME_LIMIT) {
                    printf(rouge);
                    printf("Temps écoulé ! Vous avez dépassé le temps limite de %d secondes.\n", TIME_LIMIT);
                    printf(reset);
                    joueurActuel = 3 - joueurActuel; // Passer au tour de la machine
                    continue;
                }

                if (result != 1 || position < -1 || position >= taille) {
                    printf(rouge);
                    printf("Position invalide. Veuillez entrer un nombre entre 0 et %d, ou -1 pour quitter.\n", taille - 1);
                    printf(reset);
                    while (getchar() != '\n');
                    continue;
                }

                if (position == -1) {
                    printf(rouge);
                    printf("%s (%c) a décidé de quitter le jeu. Merci d'avoir joué !\n", nomJoueur, pionActuel);
                    printf(reset);
                    quitter = true;
                    break;
                }

                // Vérifier si la position est libre
                if (board[position] != '*') {
                    printf(rouge);
                    printf("La position est déjà occupée. Veuillez choisir une autre position.\n");
                    printf(reset);
                    continue;
                }

                // Placer le pion
                board[position] = pionActuel;
                (*currentMoves)++;
                PionRestX--;
            } else if (enableDisplacement) {
                // Phase de déplacement
                printf(bleu);
                printf("%s (%c), vous pouvez déplacer un pion. Entrez la position actuelle du pion à déplacer (0-%d) ou -1 pour quitter : ", nomJoueur, pionActuel, taille - 1);
                printf(reset);

                // Mesurer le temps
                time_t debut = time(NULL);
                int result = scanf("%d", &position);
                time_t fin = time(NULL);

                // Vérifier si le temps est dépassé
                if (difftime(fin, debut) > TIME_LIMIT) {
                    printf(rouge);
                    printf("Temps écoulé ! Vous avez dépassé le temps limite de %d secondes.\n", TIME_LIMIT);
                    printf(reset);
                    joueurActuel = 3 - joueurActuel; // Passer au tour de la machine
                    continue;
                }

                if (result != 1 || position < -1 || position >= taille) {
                    printf(rouge);
                    printf("Position invalide. Veuillez entrer un nombre entre 0 et %d, ou -1 pour quitter.\n", taille - 1);
                    printf(reset);
                    while (getchar() != '\n');
                    continue;
                }

                if (position == -1) {
                    printf(rouge);
                    printf("%s (%c) a décidé de quitter le jeu. Merci d'avoir joué !\n", nomJoueur, pionActuel);
                    printf(reset);
                    quitter = true;
                    break;
                }

                // Vérifier si la position actuelle contient un pion du joueur
                if (board[position] != pionActuel) {
                    printf(rouge);
                    printf("La position actuelle ne contient pas votre pion. Veuillez réessayer.\n");
                    printf(reset);
                    continue;
                }

                // Demander la nouvelle position
                printf(bleu);
                printf("Entrez la nouvelle position (0-%d) : ", taille - 1);
                printf(reset);

                // Mesurer le temps
                debut = time(NULL);
                result = scanf("%d", &position);
                fin = time(NULL);

                // Vérifier si le temps est dépassé
                if (difftime(fin, debut) > TIME_LIMIT) {
                    printf(rouge);
                    printf("Temps écoulé ! Vous avez dépassé le temps limite de %d secondes.\n", TIME_LIMIT);
                    printf(reset);
                    joueurActuel = 3 - joueurActuel; // Passer au tour de la machine
                    continue;
                }

                if (result != 1 || position < 0 || position >= taille) {
                    printf(rouge);
                    printf("Position invalide. Veuillez entrer un nombre entre 0 et %d.\n", taille - 1);
                    printf(reset);
                    while (getchar() != '\n');
                    continue;
                }

                // Vérifier si la nouvelle position est vide
                if (board[position] != '*') {
                    printf(rouge);
                    printf("La nouvelle position est déjà occupée. Veuillez choisir une autre position.\n");
                    printf(reset);
                    continue;
                }

                // Déplacer le pion
                board[position] = pionActuel;
            } else {
                // Mode Match Nul : aucun déplacement possible
                printf(bleu);
                printf("%s (%c), vous ne pouvez pas déplacer de pion. Attendez la fin de la partie.\n", nomJoueur, pionActuel);
                printf(reset);
            }
        }
        // Tour de la machine
        else {
            if (isPlacementPhase) {
                // Phase de placement pour la machine
                position = trouverMeilleurCoup(board, pionActuel, pionAdverse);
                printf(rouge);
                printf("La machine (%c) choisit la position %d.\n", pionActuel, position);
                printf(reset);

                // Placer le pion
                board[position] = pionActuel;
                (*currentMoves)++;
                PionRestO--;
            } else if (enableDisplacement) {
                // Phase de déplacement pour la machine
                position = trouverMeilleurCoupVol(board, pionActuel, pionAdverse);
                printf(rouge);
                printf("La machine (%c) déplace un pion vers la position %d.\n", pionActuel, position);
                printf(reset);

                // Déplacer le pion
                board[position] = pionActuel;
            } else {
                // Mode Match Nul : aucun déplacement possible
                printf(rouge);
                printf("La machine (%c) ne peut pas déplacer de pion. Attendez la fin de la partie.\n", pionActuel);
                printf(reset);
            }
        }

        // Afficher le plateau après chaque tour
        Board(board);
        printf("\n");

        // Vérifier si un moulin est formé
        if (estMoulin(board, position, pionActuel)) {
            printf(rouge);
            printf("Moulin formé par %s (%c) !\n", (joueurActuel == 1) ? nomJoueur : "La machine", pionActuel);
            printf(reset);

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
                    printf(rouge);
                    printf("Choisissez une position de la machine (%c) à retirer : ", pionAdverse);
                    printf(reset);
                    if (scanf("%d", &posAdverse) != 1 || posAdverse < 0 || posAdverse >= taille) {
                        printf(rouge);
                        printf("Position invalide. Veuillez entrer un nombre entre 0 et %d.\n", taille - 1);
                        printf(reset);
                        while (getchar() != '\n');
                        continue;
                    }

                    if (board[posAdverse] == pionAdverse) {
                        board[posAdverse] = '*';
                        printf(rouge);
                        printf("Pion de la machine retiré à la position %d.\n", posAdverse);
                        printf(reset);
                        (*PionRestAdverse)--;
                        break;
                    } else {
                        printf(rouge);
                        printf("La position choisie n'est pas occupée par un pion adverse.\n");
                        printf(reset);
                    }
                }
            } else {
                printf(rouge);
                printf("La machine (%c) retire un pion adverse.\n", pionActuel);
                printf(reset);
                retirePionmch(board, pionAdverse);
                (*PionRestAdverse)--;
            }

            // Vérifier si l'adversaire a moins de 3 pions
            if (*PionRestAdverse < 3) {
                printf(rouge);
                printf("%s (%c) a gagné !\n", (joueurActuel == 1) ? nomJoueur : "La machine", pionActuel);
                printf(reset);
                remove(FICHIER_SAUVEGARDE1); // Supprimer la sauvegarde après la fin de la partie
                return 0;
            }
        }

        // Vérifier si les deux joueurs ont épuisé leurs mouvements
        if (movesX >= MAX_PIONS && movesO >= MAX_PIONS) {
            printf(rouge);
            printf("Les deux joueurs ont épuisé leurs mouvements.\n");
            printf(reset);

            if (moulinsX > moulinsO) {
                printf(rouge);
                printf("%s (X) a gagné avec %d moulins contre %d moulins pour O.\n", nomJoueur, moulinsX, moulinsO);
                printf(reset);
            } else if (moulinsO > moulinsX) {
                printf(rouge);
                printf("La machine (O) a gagné avec %d moulins contre %d moulins pour X.\n", moulinsO, moulinsX);
                printf(reset);
            } else {
                printf(rouge);
                printf("Match nul ! Les deux joueurs ont formé %d moulins.\n", moulinsX);
                printf(reset);
            }

            remove(FICHIER_SAUVEGARDE1); // Supprimer la sauvegarde après la fin de la partie
            return 0;
        }

        // Sauvegarder l'état du jeu après chaque tour
        sauvegarderJeumch(board, joueurActuel, PionRestX, PionRestO, movesX, movesO, moulinsX, moulinsO, nomJoueur);

        // Passer au joueur suivant
        joueurActuel = 3 - joueurActuel;
    }

    return 0;
}
