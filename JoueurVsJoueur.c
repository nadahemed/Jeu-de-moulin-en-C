#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "grille.h"
#include "protomove.h"
#include "flyingpahse.c"
#include "sauvegarde.c"
#include "estbloque.h"
#include "estmoulin.c"
#include "retirerpion.c"
#include "estbloque.c"
#include "jeutermine.c"
#include <stdbool.h>
#include <time.h>
#define taille 24
#define MAX_PIONS 9
#define TIME_LIMIT 30
#define FICHIER_SAUVEGARDE "sauvegarde.txt"
#define TEMPS_LIMITE 30



void Board(char board[]){
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";   
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 
    int i;
    printf(rouge);
    printf("%c",board[0]);
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
        printf("-----------------");
        
        
        
    }
    printf(reset);
    printf(rouge);
    printf("%c",board[1]);
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
         printf("-----------------");
        
    }
    printf(reset);
    printf(rouge);
    printf("%c",board[2]);
    printf(reset);
    printf("\n");
    printf(bleu);
    for (i=0;i<4;i++){
        printf("|                                                   |                                                   |\n");
        

    }
    printf(reset);
        printf(rouge);
        printf("|                             %c---------------------%c-----------------------%c                           |\n",board[3],board[4],board[5]);
        printf(reset);
        printf(bleu);
        for(i=0;i<2;i++){
            printf("|                             |                     |                       |                           |\n");

        }
        printf(rouge);
        printf("|                             |        %c------------%c-----------%c           |                           |\n",board[6],board[7],board[8]);
        printf(reset);
        printf(bleu);
        for(i=0;i<4;i++){
            printf("|                             |        |                        |           |                           |\n");

        }
        printf(rouge);
        printf("%c-----------------------------%c--------%c                        %c-----------%c---------------------------%c\n",board[9],board[10],board[11],board[12],board[13],board[14]);
        printf(reset);
        printf(bleu);
        for(i=0;i<4;i++){
            printf("|                             |        |                        |           |                           |\n");

        }
        printf(reset);
        printf(rouge);
        printf("|                             |        %c------------%c-----------%c           |                           |\n",board[15],board[16],board[17]);
        printf(reset);
        printf(bleu);
        for(i=0;i<2;i++){
            printf("|                             |                     |                       |                           |\n");

        }
        printf(reset);
        printf(rouge);
         printf("|                             %c---------------------%c-----------------------%c                           |\n",board[18],board[19],board[20]);
        printf(reset);
        printf(bleu);
         for (i=0;i<4;i++){
        printf("|                                                   |                                                   |\n");
        

    }
    printf(reset);
    printf(rouge);
    printf("%c",board[21]);
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
        printf("-----------------");
        
        
        
    }
    printf(rouge);
    printf("%c",board[22]);
    printf(reset);
    printf(bleu);
    for(i=0;i<3;i++){
        
         printf("-----------------");
        
    }
    printf(reset);
    printf(rouge);
    printf("%c",board[23]);

}



int getposition() {
    int position;
    char board[taille];
    int joueurActuel = 1;
    int PionRestX = MAX_PIONS;
    int PionRestO = MAX_PIONS;
    int movesX = 0;
    int movesO = 0;
    int moulinsX = 0; // Nombre de moulins pour X
    int moulinsO = 0; // Nombre de moulins pour O
    char joueur1[50], joueur2[50]; // Variables pour stocker les noms des joueurs

    // Demander si le joueur veut charger une sauvegarde
    printf("Voulez-vous charger la partie sauvegardée ? (o/n) : ");
    char choix;
    scanf(" %c", &choix);

    if (choix == 'o' || choix == 'O') {
        if (!chargerJeu(board, &joueurActuel, &PionRestX, &PionRestO, &movesX, &movesO, &moulinsX, &moulinsO, joueur1, joueur2)) {
            // Si le chargement échoue, initialiser une nouvelle partie
            printf("Démarrage d'une nouvelle partie.\n");
            for (int i = 0; i < taille; i++) {
                board[i] = '*';
            }
            printf("Entrez le nom du Joueur 1 (X): ");
            scanf("%s", joueur1);
            printf("Entrez le nom du Joueur 2 (O): ");
            scanf("%s", joueur2);
        }
    } else {
        // Initialisation d'une nouvelle partie
        for (int i = 0; i < taille; i++) {
            board[i] = '*';
        }
        printf("Entrez le nom du Joueur 1 (X): ");
        scanf("%s", joueur1);
        printf("Entrez le nom du Joueur 2 (O): ");
        scanf("%s", joueur2);
    }

    printf("La grille initiale est : \n");
    Board(board);
    printf("\n");

    while (true) {
        char pionActuel = (joueurActuel == 1) ? 'X' : 'O';
        char pionAdverse = (joueurActuel == 1) ? 'O' : 'X';
        int *PionRestAdverse = (joueurActuel == 1) ? &PionRestO : &PionRestX;
        int *currentMoves = (joueurActuel == 1) ? &movesX : &movesO;
        char *nomJoueurActuel = (joueurActuel == 1) ? joueur1 : joueur2;

        // Début du tour : enregistrer le temps de départ
        time_t startTime = time(NULL);

        // Vérification si le joueur est en phase de vol
        bool isFlyingPhase = (joueurActuel == 1 && PionRestX == 3) || (joueurActuel == 2 && PionRestO == 3);

        if (isFlyingPhase) {
            printf("%s (%c), vous êtes en phase de vol. Vous pouvez déplacer n'importe quel pion.\n", nomJoueurActuel, pionActuel);
            printf("Entrez la position actuelle du pion à déplacer (0-%d) : ", taille - 1);
            if (scanf("%d", &position) != 1 || position < 0 || position >= taille) {
                printf("Position invalide. Veuillez entrer un nombre entre 0 et %d.\n", taille - 1);
                while (getchar() != '\n'); // Vider le buffer d'entrée
                continue;
            }

            // Vérifier si la position actuelle contient un pion du joueur
            if (board[position] != pionActuel) {
                printf("La position actuelle ne contient pas votre pion. Veuillez réessayer.\n");
                continue;
            }

            // Demander la nouvelle position
            printf("Entrez la nouvelle position (0-%d) : ", taille - 1);
            if (scanf("%d", &position) != 1 || position < 0 || position >= taille) {
                printf("Position invalide. Veuillez entrer un nombre entre 0 et %d.\n", taille - 1);
                while (getchar() != '\n'); // Vider le buffer d'entrée
                continue;
            }

            // Vérifier si la nouvelle position est vide
            if (board[position] != '*') {
                printf("La nouvelle position est déjà occupée. Veuillez choisir une autre position.\n");
                continue;
            }

            // Déplacer le pion
            board[position] = pionActuel;
        } else {
            // Phase normale : placement d'un nouveau pion
            printf("%s (%c), entrez une position (0-%d) : ", nomJoueurActuel, pionActuel, taille - 1);
            if (scanf("%d", &position) != 1 || position < 0 || position >= taille) {
                printf("Position invalide. Veuillez entrer un nombre entre 0 et %d.\n", taille - 1);
                while (getchar() != '\n'); // Vider le buffer d'entrée
                continue;
            }

            // Vérifie si la position est occupée
            if (board[position] != '*') {
                printf("La position est déjà occupée. Veuillez choisir une autre position.\n");
                continue;
            }

            // Placement du pion
            board[position] = pionActuel;
            (*currentMoves)++;
        }

        // Vérifier si le temps est dépassé
        time_t endTime = time(NULL);
        if (difftime(endTime, startTime) > TEMPS_LIMITE) {
            printf("Temps écoulé ! Le tour passe à l'autre joueur.\n");
            joueurActuel = 3 - joueurActuel; // Passer au joueur suivant
            continue;
        }

        // Sauvegarder l'état du jeu après chaque tour
        sauvegarderJeu(board, joueurActuel, PionRestX, PionRestO, movesX, movesO, moulinsX, moulinsO, joueur1, joueur2);

        Board(board);
        printf("\n");

        // Vérifie si un moulin est formé
        if (estMoulin(board, position, pionActuel)) {
            printf("Moulin formé par %s (%c) !\n", nomJoueurActuel, pionActuel);

            // Ajoutez au compteur de moulins
            if (joueurActuel == 1) {
                moulinsX++;
            } else {
                moulinsO++;
            }

            // Retirez un pion adverse
            retirePion(board, pionAdverse);
            (*PionRestAdverse)--;

            // Vérifiez si l'adversaire a moins de 3 pions
            if (*PionRestAdverse < 3) {
                printf("%s (%c) a gagné !\n", nomJoueurActuel, pionActuel);
                remove(FICHIER_SAUVEGARDE); // Supprimer la sauvegarde après la fin de la partie
                return 0;
            }
        }

        // Vérifie si les deux joueurs ne peuvent plus jouer
        if (movesX >= MAX_PIONS && movesO >= MAX_PIONS) {
            printf("Les deux joueurs ont épuisé leurs mouvements.\n");

            if (moulinsX > moulinsO) {
                printf("%s (X) a gagné avec %d moulins contre %d moulins pour %s.\n", joueur1, moulinsX, moulinsO, joueur2);
            } else if (moulinsO > moulinsX) {
                printf("%s (O) a gagné avec %d moulins contre %d moulins pour %s.\n", joueur2, moulinsO, moulinsX, joueur1);
            } else {
                printf("Match nul ! Les deux joueurs ont formé %d moulins.\n", moulinsX);
            }

            remove(FICHIER_SAUVEGARDE); // Supprimer la sauvegarde après la fin de la partie
            return 0;
        }

        // Changement de joueur
        joueurActuel = 3 - joueurActuel; // Alterne entre 1 et 2
    }

    return 0;
}
