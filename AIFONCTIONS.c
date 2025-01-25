#include "protomove.h"
#include "grille.h"
#include  <stdio.h>
#include  <stdlib.h>
#include  <stdbool.h>
#include  <ctype.h>
#define taille 24


void retirePionmch(char board[], char pionAdverse) {
    for (int i = 0; i < taille; i++) {
        if (board[i] == pionAdverse && !estMoulin(board, i, pionAdverse)) {
            board[i] = '*';  // Retire le pion
            printf("Pion adverse retiré à la position %d.\n", i);
            return;
        }
    }
    printf("Aucun pion à retirer.\n");
}


int estMoulinmch(char board[], int position, char pion) {
    
    if (position == 0) {
        return (board[1] == pion && board[2] == pion);  
    }
    if (position == 3) {
        return (board[4] == pion && board[5] == pion);  
    }
   
    return 0;
}


int evaluer_plateau(char board[], char pionMachine, char pionAdverse) {
    int score = 0;
    int i;
    for (i=0;i<taille;i++){
        if (estMoulin(board, i, pionMachine)){
            score+=10;
        }

    }

    for (i=0;i<taille;i++){
        if (estMoulin(board, i, pionAdverse)){
            score+=10;
        }

    }

    return score;

    
}

int minMax(char board[], int profondeur, bool maximiser, char pionActuel, char pionAdverse) {
    if (profondeur == 0) return evaluer_plateau(board, pionActuel, pionAdverse);

    if (maximiser) {
        int meilleurScore = -10000;
        for (int i = 0; i < taille; i++) {
            if (board[i] == '*') {
                board[i] = pionActuel;
                int score = minMax(board, profondeur - 1, false, pionActuel, pionAdverse);
                board[i] = '*';
                meilleurScore = (score > meilleurScore) ? score : meilleurScore;
            }
        }
        return meilleurScore;
    } else {
        int meilleurScore = 10000;
        for (int i = 0; i < taille; i++) {
            if (board[i] == '*') {
                board[i] = pionAdverse;
                int score = minMax(board, profondeur - 1, true, pionActuel, pionAdverse);
                board[i] = '*';
                meilleurScore = (score < meilleurScore) ? score : meilleurScore;
            }
        }
        return meilleurScore;
    }
}


int trouverMeilleurCoup(char board[], char pionActuel, char pionAdverse) {
    int meilleurCoup = -1;
    int meilleurScore = -10000;

    for (int i = 0; i < taille; i++) {
        if (board[i] == '*') {
            board[i] = pionActuel;
            int score = minMax(board, 3, false, pionActuel, pionAdverse);
            board[i] = '*';

            if (score > meilleurScore) {
                meilleurScore = score;
                meilleurCoup = i;
            }
        }
    }

    return meilleurCoup;
}
