#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include "AfficheGrille.c"
#include "AfficheLettre.c"
#include "Start.c"
#include "menu.c"
#include "Move.c"
#define taille 24
#include "regles.c"
#include "Explicationsaisie.c"









int main(){
    int i;
    int choix;
    char start[6];
    char teststart[]="Start";
    char board[taille];

   menu();
   printf("Entrez votre choix svp :\n");
   scanf("%d",&choix);
   if (choix!=1 && choix!=2 && choix!=3){
       printf("Entrez votre choix svp :\n");
       scanf("%d",&choix);

   }
   switch (choix)
   {
   case 1:
    AfficheGrille();
    sleep(2);
    Start();
    printf("Entrez Start pour continuer :\n ");
    scanf("%s",&start);
    printf("\n");
    sleep(2);
    if (strcmp(start,teststart)==0){
        AfficheLettres();    
        sleep(2);
    }
    sleep(1);
    printf("\n");
    Explicationsaisie();
    sleep(1);
    Board(board);
    getposition();
    break;
   case 2:
    printf("Vous avez quitte!!");
    break;
   case 3:
    sleep(2);
    regles();
    break;
   
   default:
    break;
   }
   return 0;

}


