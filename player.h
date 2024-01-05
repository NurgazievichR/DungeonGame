#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "levels.h"
#include "iostream"
#include "sounds.h"
#include "vector"
#include "thread"
#include "chrono"


using namespace std;

void temporarily_change_for_sword(char& cell, char NewValue){
    char originalValue = cell;
    cell = NewValue;
    this_thread::sleep_for(std::chrono::duration<double>(0.25));
    cell = originalValue;
}

void change_value_for_punch_temporarily(char& cell, char NewValue) {
    thread symbolChangeThread([&cell, NewValue]() {
        temporarily_change_for_sword(cell, NewValue);
    });

    symbolChangeThread.detach();
}



void temporarily_change_for_tree(char& cell){
    this_thread::sleep_for(std::chrono::duration<double>(0.25));
    cell = 't';
    this_thread::sleep_for(std::chrono::duration<double>(0.9));
    cell = ' ';
}

void change_value_for_tree_temporarily(char& cell) {
    thread symbolChangeThread([&cell]() {
        temporarily_change_for_tree(cell);
    });

    symbolChangeThread.detach();
}


void move_player(int dx, int dy){

    int next_player_column = static_cast<int>(player_column)+dx;
    int next_player_row = static_cast<int>(player_row)+dy;

    if (!(next_player_column >= 0 && next_player_column<level.columns
    && next_player_row >=0 && next_player_row <level.rows)){
        return;
    }

    char cell = level.data[next_player_row*level.columns + next_player_column];
    if (cell != WALL && cell!=TREE){
        player_row = static_cast<size_t>(next_player_row);
        player_column = static_cast<size_t>(next_player_column);
        if (cell == COIN){
            player_score+=POINTS_FOR_COIN;
            level.data[next_player_row*level.columns + next_player_column]=FLOOR;
            coins_copy.push_back(next_player_row*level.columns + next_player_column);
            PlaySound(coin_sound);
        }else if (cell == EXIT){
            enemy.alive=false;
            for (auto i: coins_copy){
                level.data[i] = '*';
            }
            load_next_level();
            coins_copy.clear();
            PlaySound(exit_sound);
        }
    }
}



#endif //PLAYER_H