CC = gcc
CFLAGS = -std=c99 -Wall

main:
	$(CC) $(CFLAGS) -o $@ src/*.c src/include/*.h