#include "raylib.h"
#include "iostream"

#include "globals.h"
#include "levels.h"
#include "graphics.h"
#include "images.h"
#include "player.h"
#include "sounds.h"

void update_game(){

    switch (game_state) {
        case GAME_STATE:
            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)){
                move_player(0, -1);
            }else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)){
                move_player(0, 1);
            } else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)){
                move_player(-1, 0);
            }else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)){
                move_player(1, 0);
            } else if (IsKeyPressed(KEY_ESCAPE)){
                game_state = PAUSED_STATE;
            } else if (IsKeyPressed(KEY_K)){
                PlaySound(swordHit_sound);
                if (level.data[(player_row*level.columns+player_column-1)]==FLOOR || level.data[(player_row*level.columns+player_column-1)]==TREE || level.data[(player_row*level.columns+player_column-1)]==ENEMY ){
                    change_value_for_punch_temporarily(level.data[(player_row*level.columns+player_column-1)], 'L');
                    if (level.data[(player_row*level.columns+player_column-1)]==TREE){
                        PlaySound(explosion_sound);
                        change_value_for_tree_temporarily(level.data[(player_row*level.columns+player_column-1)]);
                        trees_copy.push_back((player_row*level.columns+player_column-1));
                    }  else

                    if (level.data[(player_row*level.columns+player_column-1)]==ENEMY){
                        player_score+=15;
                        PlaySound(death_enemy_sound);
                        enemy.alive = false;
                        for (auto i: enemy.path){
                            level.data[i] = ' ';
                        }
                    }

                }
                if (level.data[(player_row*level.columns+player_column+1)]==FLOOR || level.data[(player_row*level.columns+player_column+1)]==TREE || level.data[(player_row*level.columns+player_column+1)]==ENEMY){
                    change_value_for_punch_temporarily(level.data[(player_row*level.columns+player_column+1)], 'R');
                    if (level.data[(player_row*level.columns+player_column+1)]==TREE){
                        PlaySound(explosion_sound);
                        change_value_for_tree_temporarily(level.data[(player_row*level.columns+player_column+1)]);
                        trees_copy.push_back((player_row*level.columns+player_column+1));
                    } else

                    if (level.data[(player_row*level.columns+player_column+1)]==ENEMY){
                        player_score+=15;
                        PlaySound(death_enemy_sound);
                        enemy.alive = false;
                        for (auto i: enemy.path){
                            level.data[i] = ' ';
                        }
                    }
                }
                if (level.data[(player_row-1)*level.columns+player_column]==FLOOR || level.data[(player_row-1)*level.columns+player_column]==TREE || level.data[(player_row-1)*level.columns+player_column]==ENEMY){
                    change_value_for_punch_temporarily(level.data[(player_row-1)*level.columns+player_column], 'U');
                    if (level.data[(player_row-1)*level.columns+player_column]==TREE){
                        PlaySound(explosion_sound);
                        change_value_for_tree_temporarily(level.data[(player_row-1)*level.columns+player_column]);
                        trees_copy.push_back((player_row-1)*level.columns+player_column);
                    } else

                    if (level.data[(player_row-1)*level.columns+player_column]==ENEMY){
                        player_score+=15;
                        PlaySound(death_enemy_sound);
                        enemy.alive = false;
                        for (auto i: enemy.path){
                            level.data[i] = ' ';
                        }
                    }
                }
                if (level.data[(player_row+1)*level.columns+player_column]==FLOOR || level.data[(player_row+1)*level.columns+player_column]==TREE || level.data[(player_row+1)*level.columns+player_column]==ENEMY){
                    change_value_for_punch_temporarily(level.data[(player_row+1)*level.columns+player_column], 'D');
                    if (level.data[(player_row+1)*level.columns+player_column]==TREE){
                        PlaySound(explosion_sound);
                        change_value_for_tree_temporarily(level.data[(player_row+1)*level.columns+player_column]);
                        trees_copy.push_back((player_row+1)*level.columns+player_column);
                    } else

                    if (level.data[(player_row+1)*level.columns+player_column]==ENEMY){
                        player_score+=15;
                            PlaySound(death_enemy_sound);
                            enemy.alive = false;
                            for (auto i: enemy.path){
                                level.data[i] = ' ';
                            }
                    }
                }
            }
            break;
        case PAUSED_STATE:
            if (IsKeyPressed(KEY_ESCAPE)){
                game_state = GAME_STATE;
            }
            break;
        case VICTORY_STATE:
            if (IsKeyPressed(KEY_ENTER)){
                game_state = MENU_STATE;
                level = LEVELS[0];
                enemy = ENEMYES[0];
            }
            break;
        case MENU_STATE:
            if (IsKeyPressed(KEY_ESCAPE)){
                CloseWindow();
            }
            if (IsKeyPressed(KEY_ENTER)){
                game_state = GAME_STATE;
            }
            break;
        case GAME_OVER_STATE:
            if (IsKeyPressed(KEY_ENTER)){
                game_state = MENU_STATE;
            }
            break;
    }



}

void draw_game(){
    ++game_frame;
    switch (game_state) {
        case GAME_STATE:
            draw_level();
            draw_player();
            draw_player_score();
            break;
        case PAUSED_STATE:
            draw_pause_menu();
            break;
        case VICTORY_STATE:
            draw_victory_menu();
            break;
        case MENU_STATE:
            draw_menu();
            break;
        case GAME_OVER_STATE:
            draw_lose_menu();
            break;
    }


}

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
    InitWindow(1024, 480, "Dungeon");
    SetTargetFPS(60);
    SetExitKey(0);
    InitAudioDevice();
    // TODO
    load_sounds();
    load_fonts();
    load_images();
    load_next_level();


    while (!WindowShouldClose()) {


        BeginDrawing();

        update_game();
        draw_game();

        EndDrawing();
    }
    CloseWindow();
    unload_fonts();
    unload_images();
    unload_sounds();
    return 0;
}
