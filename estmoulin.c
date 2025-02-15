#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define taille 24

int estMoulin(char board[], int position, char pion) {
    int joueur = 1; 
    int Jeu_index = 0;
    const int moulins[16][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11},
        {12, 13, 14}, {15, 16, 17}, {18, 19, 20}, {21, 22, 23},
        {0, 9, 21}, {3, 10, 18}, {6, 11, 15}, {1, 4, 7},
        {16, 19, 22}, {8, 12, 17}, {5, 13, 20}, {2, 14, 23}
    };

    for (int i = 0; i < 16; i++) {
        if (moulins[i][0] == position || moulins[i][1] == position || moulins[i][2] == position) {
            if (board[moulins[i][0]] == pion && board[moulins[i][1]] == pion && board[moulins[i][2]] == pion) {
                return 1; 
            }
        }
    }
    return 0;
}

bool estDoubleMoulin(char board[], int position, char pion) {
    int moulinsFormes = 0;
    const int moulins[16][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {9, 10, 11},
        {12, 13, 14}, {15, 16, 17}, {18, 19, 20}, {21, 22, 23},
        {0, 9, 21}, {3, 10, 18}, {6, 11, 15}, {1, 4, 7},
        {16, 19, 22}, {8, 12, 17}, {5, 13, 20}, {2, 14, 23}
    };

    for (int i = 0; i < 16; i++) {
        if (moulins[i][0] == position || moulins[i][1] == position || moulins[i][2] == position) {
            if (board[moulins[i][0]] == pion && board[moulins[i][1]] == pion && board[moulins[i][2]] == pion) {
                moulinsFormes++;
                if (moulinsFormes >= 2) {
                    return true; 
                }
            }
        }
    }
    
    return false;
}