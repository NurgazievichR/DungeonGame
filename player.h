#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "levels.h"
#include "iostream"

void move_player(int dx, int dy){

    int next_player_column = static_cast<int>(player_column)+dx;
    int next_player_row = static_cast<int>(player_row)+dy;

    if (!(next_player_column >= 0 && next_player_column<level.columns
    && next_player_row >=0 && next_player_row <level.rows)){
        return;
    }

    char cell = level.data[next_player_row*level.columns + next_player_column];
    if (cell != WALL){
        player_row = static_cast<size_t>(next_player_row);
        player_column = static_cast<size_t>(next_player_column);
        if (cell == COIN){
            player_score+=POINTS_FOR_COIN;
            level.data[next_player_row*level.columns + next_player_column]=FLOOR;
//            play sound?
        }else if (cell == EXIT){
            load_next_level();
        }
    }
}


#endif //PLAYER_H