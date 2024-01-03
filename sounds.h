#ifndef SOUNDS_H
#define SOUNDS_H

#include "globals.h"
#include "raylib.h"



void load_sounds(){
    coin_sound = LoadSound("data/sounds/coin.wav");
    exit_sound = LoadSound("data/sounds/exit.wav");
}


void unload_sounds() {
    UnloadSound(coin_sound);
    UnloadSound(exit_sound);
}


#endif //SOUNDS_H
