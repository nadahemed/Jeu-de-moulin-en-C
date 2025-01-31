#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>


void afficher_resultat_dans_fenetre(const char *message) {
    GtkWidget *window;
    GtkWidget *label;

    // Initialisation de GTK
    gtk_init(NULL, NULL);

    // Création de la fenêtre principale
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Résultat du jeu");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Ajout d'un gestionnaire pour fermer la fenêtre
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Création d'un label avec du texte
    label = gtk_label_new(message);

    // Ajouter le label à la fenêtre
    gtk_container_add(GTK_CONTAINER(window), label);

    // Afficher tous les widgets dans la fenêtre
    gtk_widget_show_all(window);

    // Lancer la boucle principale de GTK
    gtk_main();
}