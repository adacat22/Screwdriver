#include "screwdriver.h"

int targetFps = 120;
bool running = true;
bool showFps = true;
float fontSize = 20.0f;
Font customFont;
Color backgroundColor = BLACK;
bool backgroundEnable = true;
InputMode mode = MODE_NORMAL;
ViewMode viewMode = VIEW_3D;
Camera3D camera;

