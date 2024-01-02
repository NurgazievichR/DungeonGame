#include "raylib.h"

#include "globals.h"
#include "levels.h"
#include "graphics.h"
#include "images.h"

void update_game(){

}

void draw_game(){
    draw_level();
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
