// screwdriver.c
#include "screwdriver.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DARK_GREEN "\033[38;2;0;70;0m"

void print_bar(const char *text, char fill) {
	int width = 50;
	int textLen = strlen(text);
	int sideLen = (width - textLen - 2) / 2;

	printf("\n");
	for (int i = 0; i < sideLen; i++) putchar(fill);
	printf(" %s ", text);
	for (int i = 0; i < sideLen; i++) putchar(fill);
	printf("\n");
}

void green(const char *text) {
	printf("\033[32m%s\033[0m", text);
}

void *console_thread(void *arg) {
	char line[256];

	while (running) {
		printf(DARK_GREEN "* \033[0m");
		fflush(stdout);
		if (!fgets(line, sizeof(line), stdin)) continue;

		if (strncmp(line, "exit", 4) == 0) {
			running = false;
		} else if(strncmp(line, "quit", 4) == 0)
		{	running = false;
		} else if (strncmp(line, "fps ", 4) == 0) {
			int newFps = atoi(line + 4);
			if (newFps > 0) {
				targetFps = newFps;
				SetTargetFPS(targetFps);
				printf("FPS set to %d\n", targetFps);
			}
		} else if (strncmp(line, "clear", 5) == 0) {
			printf("\033[H\033[J");
		} else if (strncmp(line, "help", 4) == 0) {
			puts("Commands: exit, fps <n>, clear, help");
		} else {
			printf("Unknown command: %s", line);
		}
	}

	return NULL;
}

