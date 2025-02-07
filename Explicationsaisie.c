#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "grille.h"



void Explicationsaisie(){
    const char *reset = "\033[0m"; 
    const char *bleu = "\033[1;34m"; 
    const char *rouge = "\033[1;31m"; 


printf(rouge);
printf(" _______           _______  _       _________ _______  _______ __________________ _______  _       \n");
printf("(  ____ \\|\\     /|(  ____ )( \\      \\__   __/(  ____ \\(  ___  )\\__   __/\\__   __/(  ___  )( (    /|\n");
printf("| (    \\/( \\   / )| (    )|| (         ) (   | (    \\/| (   ) |   ) (      ) (   | (   ) ||  \\  ( |\n");
printf("| (__     \\ (_) / | (____)|| |         | |   | |      | (___) |   | |      | |   | |   | ||   \\ | |\n");
printf("|  __)     ) _ (  |  _____)| |         | |   | |      |  ___  |   | |      | |   | |   | || (\\ \\) |\n");
printf(reset);
printf(bleu);
printf("| (       / ( ) \\ | (      | |         | |   | |      | (   ) |   | |      | |   | |   | || | \\   |\n");
printf("| (____/\\( /   \\ )| )      | (____/\\___) (___| (____/\\| )   ( |   | |   ___) (___| (___) || )  \\  |\n");
printf("(_______/|/     \\||/       (_______/\\_______/(_______/|/     \\|   )_(   \\_______/(_______)|/    )_)\n");
printf(reset);
printf(bleu);
printf("_________________________________________________________________________________\n");
printf(reset);
sleep(1);
printf(bleu);
printf("/                                                                                |\n");
printf("|                                                                                |\n");
printf("|                                                                                |\n");
sleep(0.5);
printf(reset);
printf(rouge);
sleep(1);
printf("|              Vous entrez le nombre entre(0-23)                                 |\n");
printf(reset);
sleep(1);
printf(rouge);
printf("|              après choisir le pion soit X soit Y                               |\n");
printf(reset);
sleep(1);
printf(bleu);
printf("|                                                                                |\n");
printf("|                                                                                |\n");
printf("|________________________________________________________________________________|\n");
printf(reset);




}