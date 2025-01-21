#include <stdio.h>

int startmoulin() {
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";  
    const char *reset = "\033[0m"; 
    const char *rose = "\033[1;35m";    
    const char *violet = "\033[0;35m"; 
    printf(bleu);
    printf("   __                   _                               _ _       \n");
    printf("   \\ \\  ___ _   _    __| |_   _   _ __ ___   ___  _   _| (_)_ __  \n");
    printf("    \\ \\/ _ \\ | | |  / _` | | | | | '_ ` _ \\ / _ \\| | | | | | '_ \\ \n");
    printf(" /\\_/ /  __/ |_| | | (_| | |_| | | | | | | | (_) | |_| | | | | | |\n");
    printf(" \\___/ \\___|\\__,_|  \\__,_|\\__,_| |_| |_| |_|\\___/ \\__,_|_|_|_| |_|\n");
    printf("                                                                  \n");
    printf(reset);
    return 0;
}
