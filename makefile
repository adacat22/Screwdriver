CC = gcc
CFLAGS = -Wall -g -std=c99
LDFLAGS = -lraylib -lGL -lm -pthread -ldl -lrt -lX11

SRCS = main.c camera.c globals.c render.c screwdriver.c
OBJS = $(SRCS:.c=.o)

screwdriver: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o screwdriver

