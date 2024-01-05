#ifndef SOUNDS_H
#define SOUNDS_H

#include "globals.h"
#include "raylib.h"



void load_sounds(){
    coin_sound = LoadSound("data/sounds/coin.wav");
    exit_sound = LoadSound("data/sounds/exit.wav");
    swordHit_sound = LoadSound("data/sounds/sword.wav");
    explosion_sound = LoadSound("data/sounds/explosion.wav");
    background_sound = LoadSound("data/sounds/background_song.mp3");
    death_enemy_sound = LoadSound("data/sounds/enemy_death.wav");
    player_death_sound = LoadSound("data/sounds/player_death.wav");
}


void unload_sounds() {
    UnloadSound(coin_sound);
    UnloadSound(exit_sound);
    UnloadSound(swordHit_sound);
    UnloadSound(explosion_sound);
    UnloadSound(background_sound);
    UnloadSound(death_enemy_sound);
    UnloadSound(player_death_sound);
}


#endif //SOUNDS_H
