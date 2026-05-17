#include <raylib.h>
#include <iostream>

void updateGame() {
    // nothing here yet
}

void drawGame() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
}

int main() {
    InitWindow(1280, 720, "Five Nights on ZSI");
    SetTargetFPS(165);
    std::cout << "#LoveAngelika" << std::endl;
    while (!WindowShouldClose()) {
        updateGame();
        drawGame();
    }
    CloseWindow();
    return 0;
}