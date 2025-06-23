#include "screwdriver.h"

void DrawTextShadow(const char *text, int x, int y) {
    DrawTextEx(customFont, text, (Vector2){x + 2, y + 2}, fontSize, 1, BLACK);
    DrawTextEx(customFont, text, (Vector2){x, y}, fontSize, 1, WHITE);
}

void DrawTextShadowRight(const char *text, int x, int y) {
    Vector2 size = MeasureTextEx(customFont, text, fontSize, 1);
    DrawTextEx(customFont, text, (Vector2){x - size.x + 2, y + 2}, fontSize, 1, BLACK);
    DrawTextEx(customFont, text, (Vector2){x - size.x, y}, fontSize, 1, WHITE);
}

void draw_2d_grid(int gridSize, int cellSize, Color lineColor) {
    int halfGrid = gridSize / 2;
    for (int i = -halfGrid; i <= halfGrid; i++) {
        DrawLine3D((Vector3){i * cellSize, 0, -halfGrid * cellSize},
                   (Vector3){i * cellSize, 0, halfGrid * cellSize}, lineColor);
        DrawLine3D((Vector3){-halfGrid * cellSize, 0, i * cellSize},
                   (Vector3){halfGrid * cellSize, 0, i * cellSize}, lineColor);
    }
}

void draw_scene(void) {
    BeginDrawing();
    ClearBackground(backgroundEnable ? backgroundColor : BLACK);
    BeginMode3D(camera);

    if (mode == MODE_VIEW && viewMode == VIEW_2D_GRID) {
        draw_2d_grid(20, 20, GREEN);
    }

    EndMode3D();
    DrawTextShadow(mode == MODE_VIEW ? "VISUAL" : "NORMAL", 10, 10);
    if (showFps) {
        DrawTextShadowRight(TextFormat("%d", GetFPS()), GetScreenWidth() - 10, 10);
    }
    EndDrawing();
}

