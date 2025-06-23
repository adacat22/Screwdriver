#include "screwdriver.h"
#include <stdio.h>
#include <pthread.h>

#define CLEAR      "\033[H\033[J"
#define DARK_GRAY  "\033[38;2;80;80;80m"
#define DARK_GREEN "\033[38;2;0;70;0m"

int main(void)
{
	printf(CLEAR);
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 600, "Screwdriver");
	SetTargetFPS(targetFps);
	SetExitKey(KEY_NULL);

	customFont = LoadFontEx("font.ttf", 64, 0, 0);
	SetTextureFilter(customFont.texture, TEXTURE_FILTER_BILINEAR);

	camera = (Camera3D){
		.position = {4.0f, 100.0f, 4.0f},
		.target = {0.0f, 0.0f, 0.0f},
		.up = {0.0f, 1.0f, 0.0f},
		.fovy = 120.0f,//		FOV
		.projection = CAMERA_PERSPECTIVE
	};

	print_bar("loading config", '=');

	pthread_t thread_id;
	pthread_create(&thread_id, NULL, console_thread, NULL);

	while (running && !WindowShouldClose())
	{
		update_camera();
		draw_scene();
	}
	
	// exiting
	running = false;
	pthread_join(thread_id, NULL);

	UnloadFont(customFont);
	CloseWindow();
	printf("Bye-bye!\n");
	return 0;
}

