CC=gcc
ARCH=native
CFLAGS=-Wall -Wextra -pedantic -std=c99 -Ofast -march=$(ARCH) -Ithirdparty
LDFLAGS=-flto -lm
TARGET=tstbv
RM=rm
RMFLAGS=-f

all: main

main:
	$(CC) $(CFLAGS) src/main.c -o $(TARGET) $(LDFLAGS)

clean:
	$(RM) $(RMFLAGS) $(TARGET)
