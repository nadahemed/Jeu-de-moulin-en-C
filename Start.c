#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "grille.h"




void Start(){
    const char *reset = "\033[0m";
    const char *violet = "\033[0;35m"; 
    const char *rouge = "\033[1;31m"; 
    const char *vert = "\033[1;32m";
    const char *bleu = "\033[1;34m";  
    const char *rose = "\033[1;35m";  
    printf(bleu);
    printf("_________________________        ________________        ________________        _________________        ________________ \n");
    sleep(0.3);
    printf("|                        |       |               |       |               |       |                |       |               |\n");
    sleep(0.3);
    printf("|  ______________________|       |______   ______|       |  __________   |       |  ___________   |       |______   ______| \n");
    sleep(0.3);
    printf("|  |                                    |  |             |  |         |  |       |  |          |  |              |  |       \n");
    sleep(0.3);
    printf("|  |                                    |  |             |  |         |  |       |  |          |  |              |  |       \n");
    sleep(0.3);
    printf("|  |                                    |  |             |  |         |  |       |  |          |  |              |  |       \n");
    sleep(0.3);
    printf("|  |______________________              |  |             |  |         |  |       |  |    ______|  |              |  |       \n");
    sleep(0.3);
    printf("|                        |              |  |             |  |         |  |       |  |    |        |              |  |       \n");
    sleep(0.3);
    printf("|______________________  |              |  |             |  |         |  |       |  |    |        |              |  |       \n");
    sleep(0.3);
    printf("                      |  |              |  |             |  |         |  |       |  |    |  ______|              |  |       \n");
    sleep(0.3);
    printf("                      |  |              |  |             |  |         |  |       |  |    |  |                    |  |       \n");
    sleep(0.3);
    printf("                      |  |              |  |             |  |         |  |       |  |    |  |                    |  |       \n");
    sleep(0.3);
    printf("                      |  |              |  |             |  |         |  |       |  |    |  |                    |  |       \n");
    sleep(0.3);
    printf("______________________|  |              |  |             |  |         |  |       |  |    |  |                    |  |       \n");
    sleep(0.3);
    printf("|                        |              |  |             |  |         |  |       |  |    |  |                    |  |       \n");
    sleep(0.3);
    printf("|________________________|              |__|             |__|         |__|       |__|    |__|                    |__|       \n");

    
}



