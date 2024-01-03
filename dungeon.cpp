#include "raylib.h"

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
