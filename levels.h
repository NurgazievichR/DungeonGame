#ifndef LEVELS_H
#define LEVELS_H

#include "globals.h"
#include "graphics.h"

void load_next_level(){
    level_index++;
    if (level_index>LEVEL_COUNT){
        //To the end Screen
        level_index = 0;
    }
    level = LEVELS[level_index];

    derive_graphics_metrics_from_loaded_level();
}


#endif //LEVELS_H
