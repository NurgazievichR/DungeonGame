#ifndef SOUNDS_H
#define SOUNDS_H

#include "globals.h"
#include "raylib.h"



void load_sounds(){
    coin_sound = LoadSound("data/sounds/coin.wav");
    exit_sound = LoadSound("data/sounds/exit.wav");
    swordHit_sound = LoadSound("data/sounds/sword.wav");
    explosion_sound = LoadSound("data/sounds/explosion.wav");
}


void unload_sounds() {
    UnloadSound(coin_sound);
    UnloadSound(exit_sound);
    UnloadSound(swordHit_sound);
    UnloadSound(explosion_sound);
}


#endif //SOUNDS_H
