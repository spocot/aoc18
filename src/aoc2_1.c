#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_remove(char *s, char c)
{
    int num = 0;
    char *curr;
    char *buffer = s;
    for (curr = s; *curr != '\0'; curr++) {
        *buffer = *curr;
        if (*curr != c) {
            ++buffer;
        }else{
            ++num;
        }
    }
    *buffer = '\0';
    return num;
}

int main(int argc, char **argv)
{

    int num2 = 0, num3 = 0;

    char *line = NULL;
    size_t size = 0;
    while (getline(&line, &size, stdin) != -1) {
        int found2 = 0, found3 = 0;
        while (*line != '\0'){
            int counted = count_remove(line, *line);
            if (counted == 2 && !found2) {
                ++num2;
                found2 = 1;
            } else if (counted == 3 && !found3) {
                ++num3;
                found3 = 1;
            }
        }

        free(line);
        line = NULL;
    }
    printf("Checksum: %d\n", num2 * num3);
}
