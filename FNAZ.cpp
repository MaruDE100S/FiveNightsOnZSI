#include <raylib.h>
#include <iostream>
#include <string>

enum class GameState {
    MENU,
    // GAMEPLAY,
    // PAUSE,
    // GAME_OVER
};

GameState gameState = GameState::MENU;

const std::string musicPath = "assets/audio/music/";
const std::string sfxPath = "assets/audio/sfx/";
const std::string texturePath = "assets/textures/";

struct gameAssets {
    Texture2D noiseTexture;
    Music mainMenuMusic;
};

struct GameContext {
    GameState state = GameState::MENU;
};

void loadAssets(gameAssets& assets) {
    // noise texture
    Image noiseImage = GenImageWhiteNoise(1280, 720, 0.5f);
    assets.noiseTexture = LoadTextureFromImage(noiseImage);
    UnloadImage(noiseImage);
    // music
    assets.mainMenuMusic = LoadMusicStream((musicPath + "MainMenu_FNAZ.mp3").c_str());
}

void unloadAssets(gameAssets& assets) {
    UnloadTexture(assets.noiseTexture);
    UnloadMusicStream(assets.mainMenuMusic);
    CloseAudioDevice();
}

void drawNoise(const gameAssets& assets) {
    float alpha = (float)GetRandomValue(5,15) / 100.0f;
    DrawTextureEx(assets.noiseTexture, {(float)GetRandomValue(-5,5), 
        (float)GetRandomValue(-5,5)}, 0, 1.0f, ColorAlpha(WHITE, alpha));
    if (GetRandomValue(0, 100) > 95) {
        DrawRectangle(0, GetRandomValue(0, 720), 1280, GetRandomValue(1, 4), 
        ColorAlpha(BLACK, 0.3f));
    }
}

void updateGame(GameContext& context, gameAssets& assets) {
    UpdateMusicStream(assets.mainMenuMusic);
    
    if (context.state == GameState::MENU && IsKeyPressed(KEY_ENTER)) {
        // context.state = GameState::GAMEPLAY; 
        // tommorow
    }
}

void drawGame(const GameContext& context, const gameAssets& assets) {
    BeginDrawing();
    switch (context.state) {
        case GameState::MENU:
            ClearBackground(BLACK);
            const char* title = "Five Nights at ZSI's";
            const char* subtitle = "Press Enter to start new game.";
            const char* credit = "Developed by MaruDE\nSoundTrack and SFX by Mati FL Studio\n3D Modeling by Kreatynka\nVoice Acting by JohnyPendrive";
            const char* version = "v0.0.0";
            DrawText(title, 1280 / 2 - MeasureText(title, 50) / 2, 720 / 2 - 50, 50, WHITE);
            DrawText(subtitle, 1280 / 2 - MeasureText(subtitle, 20) / 2, 720 / 2 + 50, 20, WHITE);
            DrawText(credit, 10, 720 - 100, 20, WHITE);
            DrawText(version, 10, 10, 20, WHITE);
            drawNoise(assets);
        break;
    }
    EndDrawing();
}

int main() {
    InitWindow(1280, 720, "Five Nights at ZSI's");
    SetTargetFPS(165);
    InitAudioDevice();
    gameAssets assets;
    loadAssets(assets);
    GameContext context;
    
    std::cout << "#LoveAngelika" << std::endl;
    PlayMusicStream(assets.mainMenuMusic);
    while (!WindowShouldClose()) {
        updateGame(context, assets);
        drawGame(context, assets);
    }
    unloadAssets(assets);
    CloseWindow();
    return 0;
}