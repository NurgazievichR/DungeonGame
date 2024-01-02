#include "raylib.h"

#include "globals.h"
// TODO

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
    InitWindow(1024, 480, "Dungeon");
    SetTargetFPS(60);

    // TODO

    while (!WindowShouldClose()) {
        BeginDrawing();

        // TODO

        EndDrawing();
    }
    CloseWindow();

    // TODO

    return 0;
}
