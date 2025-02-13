#include <stdio.h>
#include <string.h>
#include <unistd.h>
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
#include "playmusic.c"
#define taille 24
#include "regles.c"
#include "Explicationsaisie.c"

int main() {
    int choix;
    int secondchoix;
    char start[6];
    char teststart[] = "Start";
    char board[taille];
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";   
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 

    // Démarrer la musique

    while (1) {
        menu_jeu();
        menu();
        printf(bleu);
        printf("Entrez votre choix svp :\n");
        printf(reset);
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                startmoulin();
                AfficheGrille();
                sleep(2);
                Start();
                printf(bleu);
                printf("Entrez Start pour continuer :\n ");
                printf(reset);
                scanf("%s", start);
                printf("\n");
                sleep(2);
                if (strcmp(start, teststart) == 0) {
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
                scanf("%d", &secondchoix);
                switch (secondchoix) {
                    case 1:
                        getposition();
                        break;
                    case 2:
                        getmachine();
                        break;
                    case 3:
                        getmachineAI();
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                printf(rouge);
                printf("Vous avez quitté !!\n");
                printf(reset);
                return 0;
            case 3:
                sleep(2);
                regles();
                break;
            default:
                printf("Choix invalide, veuillez réessayer.\n");
                break;
        }

        // Demander à l'utilisateur s'il souhaite revenir au menu principal
        printf(bleu);
        printf("Voulez-vous revenir au menu principal ? (1: Oui, 0: Non)\n");
        printf(reset);
        int retour;
        scanf("%d", &retour);
        if (retour == 0) {
            printf(rouge);
            printf("Vous avez quitté !!\n");
            printf(reset);
            return 0;
        }
    }

    return 0;
}



