#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include "AfficheGrille.c"
#include "AfficheLettre.c"
#include "JoueurVsMachine.c"
#include "AIFONCTIONS.c"
#include "JoueurVsMachineAvancee.c"
#include "menujeu.c"
#include "Start.c"
#include "menu.c"
#include "jeutest.c"
#include "JoueurVsJoueur.c"
#define taille 24
#include "regles.c"
#include "Explicationsaisie.c"









int main(){
    int i;
    int choix;
    int secondchoix;
    char start[6];
    char teststart[]="Start";
    char board[taille];
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";   
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 


   menu_jeu();
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
    startmoulin();
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
    menu_jeu();
    printf(bleu);
    printf("Entrez votre choix :\n");
    printf("1-JoueurVsJoueur\n");
    printf("2-JoueurVsMachine\n");
    printf("3-JoueurVsMachineAI\n");
    printf(reset);
    scanf("%d",&secondchoix);
    switch (secondchoix)
    {
    case 1:
        getposition();
        break;
    case 2:
        getmachine();
    case 3:
        getmachineAI();
        
    
    default:
        break;
    }
    

    
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



