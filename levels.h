#ifndef LEVELS_H
#define LEVELS_H

#include "globals.h"
#include "graphics.h"
#include "enemy.h"



void load_next_level(){

    level_index++;
    enemy_index++;
    if (level_index==LEVEL_COUNT){
        game_state = VICTORY_STATE;
        level_index =0;
        create_victory_menu_background();
        player_score =0;
    }
    level = LEVELS[level_index];
    enemy = ENEMYES[enemy_index];
    for (size_t row = 0; row < level.rows; ++row){
        for (size_t column = 0; column<level.columns; ++column){
            char cell = level.data[row*level.columns + column];
            if (cell == ENTRANCE){
                player_row = row;
                player_column = column;
            }
        }
    }
    derive_graphics_metrics_from_loaded_level();
    enemy_update();
}


#endif //LEVELS_H
