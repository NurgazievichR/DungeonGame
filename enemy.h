#ifndef ENEMY_H
#define ENEMY_H


#include "vector"
#include "globals.h"
#include "thread"

using namespace std;





void enemy_update_function(){

    int prev = -1;
    while (enemy.alive){
        for (auto a: enemy.path){
            if (!enemy.alive){
                break;
            }
            if (prev==-1){
                level.data[a] = 'V';
                prev = a;
                this_thread::sleep_for(std::chrono::duration<double>(0.5));
                continue;
            }
            level.data[prev]=' ';
            level.data[a] = 'V';
            prev = a;
            this_thread::sleep_for(std::chrono::duration<double>(0.5));
        }
    }
    for (auto a:enemy.path){
        level.data[a]=' ';
    }
}

void enemy_update() {
    if (!enemy.alive){
        return;
    }
    thread symbolChangeThread([]() {
        enemy_update_function();
    });

    symbolChangeThread.detach();
}


#endif //ENEMY_H
