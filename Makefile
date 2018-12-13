CC=gcc
CFLAGS += -Wall

EXEC = aoc1 aoc2

all: $(EXEC)

aoc%:
	$(CC) $(CFLAGS) -o $@_1 src/$@_1.c
	$(CC) $(CFLAGS) -o $@_2 src/$@_2.c

clean:
	rm -f aoc*_*
