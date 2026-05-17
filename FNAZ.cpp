#include <raylib.h>
#include <iostream>

enum class GameState {
    MENU,
    GAMEPLAY,
    PAUSE,
    GAME_OVER
};

GameState gameState = GameState::MENU;

void updateGame() {
    // nothing here yet
}

void drawGame() {
    BeginDrawing();
    switch (gameState) {
        case GameState::MENU:
        ClearBackground(BLACK);
        const char* title = "Five Nights at ZSI's";
        const char* subtitle = "Press Enter to start new game.";
        const char* credit = "Developed by MaruDE\nSoundTrack and SFX by Mati FL Studio\n3D Modeling by Kreatynka\nVoice Acting by JohnyPendrive";
        const char* version = "0.0.0v";
        DrawText(title, 1280 / 2 - MeasureText(title, 50) / 2, 720 / 2 - 50, 50, WHITE);
        DrawText(subtitle, 1280 / 2 - MeasureText(subtitle, 20) / 2, 720 / 2 + 50, 20, WHITE);
        DrawText(credit, 10, 720 - 100, 20, WHITE);
        DrawText(version, 10, 10, 20, WHITE);
        break;
    }
    EndDrawing();
}

int main() {
    InitWindow(1280, 720, "Five Nights at ZSI's");
    SetTargetFPS(165);
    std::cout << "#LoveAngelika" << std::endl;
    while (!WindowShouldClose()) {
        updateGame();
        drawGame();
    }
    CloseWindow();
    return 0;
}