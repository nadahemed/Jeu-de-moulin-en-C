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
    
    int lignes[16][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11},
        {12, 13, 14}, {15, 16, 17}, {18, 19, 20}, {21, 22, 23},
        {0, 9, 21}, {3, 10, 18}, {6, 11, 15}, {1, 4, 7},
        {16, 19, 22}, {8, 12, 17}, {5, 13, 20}, {2, 14, 23}
    };

    for (int i = 0; i < 16; i++) {
        if (lignes[i][0] == position || lignes[i][1] == position || lignes[i][2] == position) {
            if (board[lignes[i][0]] == pion && board[lignes[i][1]] == pion && board[lignes[i][2]] == pion) {
                return 1;  
            }
        }
    }
    return 0;  
}


int evaluer_position(int position, char pion) {
    
    int positions_centrales[] = {11, 12, 13, 14, 15};  
    for (int i = 0; i < 5; i++) {
        if (position == positions_centrales[i]) {
            return 5;  
        }
    }
    return 1;  
}

int minMaxAlphaBeta(char board[], int profondeur, bool maximiser, char pionActuel, char pionAdverse, int alpha, int beta) {
    if (profondeur == 0) return evaluer_plateau(board, pionActuel, pionAdverse);

    if (maximiser) {
        int meilleurScore = -10000;
        for (int i = 0; i < taille; i++) {
            if (board[i] == '*') {
                board[i] = pionActuel;
                int score = minMaxAlphaBeta(board, profondeur - 1, false, pionActuel, pionAdverse, alpha, beta);
                board[i] = '*';
                meilleurScore = (score > meilleurScore) ? score : meilleurScore;
                alpha = (alpha > meilleurScore) ? alpha : meilleurScore;
                if (beta <= alpha) {
                    break;  // Pruning
                }
            }
        }
        return meilleurScore;
    } else {
        int meilleurScore = 10000;
        for (int i = 0; i < taille; i++) {
            if (board[i] == '*') {
                board[i] = pionAdverse;
                int score = minMaxAlphaBeta(board, profondeur - 1, true, pionActuel, pionAdverse, alpha, beta);
                board[i] = '*';
                meilleurScore = (score < meilleurScore) ? score : meilleurScore;
                beta = (beta < meilleurScore) ? beta : meilleurScore;
                if (beta <= alpha) {
                    break;  // Pruning
                }
            }
        }
        return meilleurScore;
    }
}

int estMoulinPotentiel(char board[], int position, char pion) {
    int lignes[16][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11},
        {12, 13, 14}, {15, 16, 17}, {18, 19, 20}, {21, 22, 23},
        {0, 9, 21}, {3, 10, 18}, {6, 11, 15}, {1, 4, 7},
        {16, 19, 22}, {8, 12, 17}, {5, 13, 20}, {2, 14, 23}
    };

    for (int i = 0; i < 16; i++) {
        if (lignes[i][0] == position || lignes[i][1] == position || lignes[i][2] == position) {
            int count = 0;
            int empty = -1;
            for (int j = 0; j < 3; j++) {
                if (board[lignes[i][j]] == pion) {
                    count++;
                } else if (board[lignes[i][j]] == '*') {
                    empty = lignes[i][j];
                }
            }
            if (count == 2 && empty != -1) {
                return empty;  
            }
        }
    }
    return -1;  
}

int evaluer_plateau(char board[], char pionMachine, char pionAdverse) {
    int score = 0;
    int i;

    for (i = 0; i < taille; i++) {
        if (estMoulin(board, i, pionMachine)) {
            score += 20;  // Bonus pour un moulin complet
        }
        if (estMoulin(board, i, pionAdverse)) {
            score -= 20;  // Pénalité pour un moulin adverse
        }

        int moulinPotentielMachine = estMoulinPotentiel(board, i, pionMachine);
        if (moulinPotentielMachine != -1) {
            score += 10;  // Bonus pour un moulin potentiel
        }

        int moulinPotentielAdverse = estMoulinPotentiel(board, i, pionAdverse);
        if (moulinPotentielAdverse != -1) {
            score -= 10;  // Pénalité pour un moulin potentiel adverse
        }
    }

    for (i = 0; i < taille; i++) {
        if (board[i] == pionMachine) {
            score += evaluer_position(i, pionMachine);  
        } else if (board[i] == pionAdverse) {
            score -= evaluer_position(i, pionAdverse);  
        }
    }

    return score;
}


int trouverMeilleurCoup(char board[], char pionActuel, char pionAdverse) {
    int meilleurCoup = -1;
    int meilleurScore = -10000;

    for (int i = 0; i < taille; i++) {
        if (board[i] == '*') {
            board[i] = pionActuel;
            int score = minMaxAlphaBeta(board, 3, false, pionActuel, pionAdverse, -10000, 10000);
            board[i] = '*';

            // Prioriser les coups qui forment un moulin ou bloquent un moulin adverse
            int moulinPotentiel = estMoulinPotentiel(board, i, pionActuel);
            if (moulinPotentiel != -1) {
                score += 15;  // Bonus pour un coup qui forme un moulin
            }

            int moulinPotentielAdverse = estMoulinPotentiel(board, i, pionAdverse);
            if (moulinPotentielAdverse != -1) {
                score += 10;  // Bonus pour un coup qui bloque un moulin adverse
            }

            if (score > meilleurScore) {
                meilleurScore = score;
                meilleurCoup = i;
            }
        }
    }

    return meilleurCoup;
}






