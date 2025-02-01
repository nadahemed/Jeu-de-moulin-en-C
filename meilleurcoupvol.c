#define taille 24
#include "grille.h"
#include "protomove.h"


int evaluerPosition(char board[], int position, char pionActuel, char pionAdverse) {
    int score = 0;

    // Vérifier si le déplacement actuel forme un moulin
    if (estMoulin(board, position, pionActuel)) {
        score += 100; // Bonus élevé pour former un moulin
    }

    // Vérifier si le déplacement permet à l'adversaire de former un moulin au tour suivant
    for (int i = 0; i < taille; i++) {
        if (board[i] == '*') {
            board[i] = pionAdverse;
            if (estMoulin(board, i, pionAdverse)) {
                score -= 50; // Pénalité pour permettre un moulin adverse
            }
            board[i] = '*';
        }
    }

    // Bonus pour occuper des positions stratégiques (exemple : centre du plateau)
    if (position == taille / 2) {
        score += 10; // Bonus pour occuper le centre
    }

    // Bonus pour se rapprocher des pions adverses
    for (int i = 0; i < taille; i++) {
        if (board[i] == pionAdverse) {
            // Calculer la distance entre la position actuelle et le pion adverse
            int distance = abs(position - i);
            if (distance <= 2) { // Si le pion est proche
                score += 5; // Bonus pour se rapprocher de l'adversaire
            }
        }
    }

    return score;
}



int trouverMeilleurCoupVol(char board[], char pionActuel, char pionAdverse) {
    int meilleurePosition = -1;
    int meilleurScore = -1;

    // Parcourir toutes les positions du plateau
    for (int i = 0; i < taille; i++) {
        if (board[i] == pionActuel) {
            // Trouver une position libre pour déplacer ce pion
            for (int j = 0; j < taille; j++) {
                if (board[j] == '*') {
                    // Simuler le déplacement du pion
                    board[i] = '*';
                    board[j] = pionActuel;

                    // Évaluer le score de ce déplacement
                    int score = evaluerPosition(board, j, pionActuel, pionAdverse);

                    // Si ce déplacement est meilleur, le retenir
                    if (score > meilleurScore) {
                        meilleurScore = score;
                        meilleurePosition = j;
                    }

                    // Annuler le déplacement simulé
                    board[i] = pionActuel;
                    board[j] = '*';
                }
            }
        }
    }

    // Si aucune position n'a été trouvée, choisir une position aléatoire
    if (meilleurePosition == -1) {
        do {
            meilleurePosition = rand() % taille;
        } while (board[meilleurePosition] != '*');
    }

    return meilleurePosition;
}