#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int freq = 0;
    char *line = NULL;
    size_t size = 0;
    while (getline(&line, &size, stdin) != -1) {
        int val = atoi(line);
        freq += val;

        free(line);
        line = NULL;
    }
    printf("%d\n", freq);
}
