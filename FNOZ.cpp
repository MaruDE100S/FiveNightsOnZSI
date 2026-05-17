#include <raylib.h>
#include <iostream>

int main() {
    InitWindow(800, 600, "Five Nights on ZSI");
    SetTargetFPS(60);
    std::cout << "#LoveAngelika" << std::endl;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}