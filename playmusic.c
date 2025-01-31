#include "grille.h"


void playMusic() {
    #ifdef _WIN32
        // Sous Windows
        system("start wmplayer music.mp3 &");
    #else
        // Sous Linux ou macOS
        system("mpg123 -q music.mp3 &");
    #endif
}


void stopMusic() {
    #ifdef _WIN32
        // Sous Windows
        system("taskkill /IM wmplayer.exe /F");
    #else
        // Sous Linux ou macOS
        system("pkill mpg123");
    #endif
}