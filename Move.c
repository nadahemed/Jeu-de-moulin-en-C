#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "grille.h"
#define taille 24

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
int getposition(){
    int position;
    char pion,quitt;
    const char *rouge = "\033[1;31m"; 
    const char *reset = "\033[0m"; 
    int Jeu_index=0;
    char board[taille]; 
         for (int i=0;i<taille;i++){
            board[i]='*';
         }
    printf("La grille initiale est : \n");
    Board(board);
    printf("\n");
    sleep(2);
    while(Jeu_index<taille){
    
    printf("\n");
    scanf("%d",&position); 
    printf("\n");
    scanf("%c",&pion);
    pion=toupper(pion);
    board[position]=pion;
    Board(board); 
    Jeu_index+=1;
    printf("\n");
    printf(rouge);
    printf(reset);
    


}

}



    
    









    


   
    




    



    
    


