#include "raylib.h"

#include "globals.h"
#include "levels.h"
#include "graphics.h"
#include "images.h"
#include "player.h"

void update_game(){
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)){
        move_player(0, -1);
    }else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)){
        move_player(0, 1);
    } else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)){
        move_player(-1, 0);
    }else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)){
        move_player(1, 0);
    }
}

void draw_game(){
    ++game_frame;
    draw_level();
    draw_player();
    draw_player_score();
}

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
    InitWindow(1024, 480, "Dungeon");
    SetTargetFPS(60);

    // TODO
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
    return 0;
}
