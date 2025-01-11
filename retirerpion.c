#define taille 24


void retirePion(char board[], char pionAdverse) {
    int position;
    while (1) {
        printf("Choisissez un pion adverse (%c) à retirer (0-23) : ", pionAdverse);
        if (scanf("%d", &position) != 1 || position < 0 || position >= taille) {
            printf("Position invalide. Veuillez entrer un nombre entre 0 et 23.\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (board[position] != pionAdverse) {
            printf("Aucun pion adverse à cette position. Réessayez.\n");
            continue;
        }
        board[position] = '*'; 
        Board(board);
        printf("\n");
        break;
    }
}

       