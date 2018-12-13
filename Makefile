CC=gcc
CFLAGS += -Wall

MKDIR_P = mkdir -p
SRC_DIR = src

DAYS = aoc1

SRCS = $(DAYS)_1 $(DAYS)_2

all: $(SRCS)

$(SRCS): %: src/%.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(SRCS)
