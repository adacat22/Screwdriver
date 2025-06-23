#ifndef SCREWDRIVER_H
#define SCREWDRIVER_H

#include "raylib.h"
#include <stdbool.h>

typedef enum { MODE_NORMAL, MODE_VIEW, MODE_RUNTIME } InputMode;
typedef enum { VIEW_3D, VIEW_2D_GRID } ViewMode;

extern int targetFps;
extern bool running;
extern bool showFps;
extern float fontSize;
extern Font customFont;
extern Color backgroundColor;
extern bool backgroundEnable;
extern InputMode mode;
extern ViewMode viewMode;
extern Camera3D camera;

void print_bar(const char *text, char fill);
void green(const char *text);
void draw_scene(void);
void update_camera(void);
void *console_thread(void *arg);

#endif

