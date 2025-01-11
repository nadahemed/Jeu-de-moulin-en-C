#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "grille.h"
#include <stdbool.h>


#define taille 24
#define MAX_PIONS 9

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
    char pion;
    char board[taille]; 
    int joueur = 1; // 1 pour Joueur 1, 2 pour Joueur 2
    int Jeu_index = 0;

    // Initialisation de la grille
    for (int i = 0; i < taille; i++) {
        board[i] = '*';
    }

    printf("La grille initiale est : \n");
    Board(board);
    printf("\n");

    // Boucle principale du jeu
    while (Jeu_index < taille) {
        printf("Joueur1 %d, entrez une position (0-23) :\n ", joueur);
        if (scanf("%d", &position) != 1 || position < 0 || position >= taille) {
            printf("Position invalide. Veuillez entrer un nombre entre 0 et 23.\n");
            while (getchar() != '\n'); // Vider le tampon
            continue;
        }

        if (board[position] != '*') {
            printf("La position est déjà occupée. Veuillez choisir une autre position.\n");
            continue;
        }

        printf("Joueur %d, entrez votre pion (X ou O) : \n", joueur);
        while (getchar() != '\n'); // Vider le tampon
        scanf("%c", &pion);
        pion = toupper(pion);

        if ((joueur == 1 && pion != 'X') || (joueur == 2 && pion != 'O')) {
            printf("Pion invalide. Joueur %d doit jouer avec %s.\n", joueur, (joueur == 1) ? "X" : "O");
            continue;
        }

        // Placer le pion sur la grille
        board[position] = pion;
        Board(board);
        printf("\n");

        // Passer au joueur suivant
        joueur = (joueur == 1) ? 2 : 1;
        Jeu_index++;
    }

    return 0;
}