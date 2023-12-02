#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_ROW_COUNT 1200
#define FILE_COLUMN 3

int main(int argc, char *argv[]) {
    int row = 0, sum = 0;
    char c;
    char **table = malloc(MAX_FILE_ROW_COUNT * sizeof(char *));
    if (!table) {
        fprintf(stderr, "Failed to allocate memory for table\n");
        return 1;
    }

    for (int i = 0; i < MAX_FILE_ROW_COUNT; i++) {
        table[i] = malloc(FILE_COLUMN * sizeof(char));
        // Check if malloc failed
        if (table[i] == NULL) {
            fprintf(stderr, "Failed to allocate memory for row %d\n", i);
            for (int j = 0; j < i; j++) {
                free(table[j]);
            }
            free(table);
            return 1;
        }
    }

    c = getchar();
    bool is_last_digit = false;
    while (c != EOF && row < MAX_FILE_ROW_COUNT) {
        if (c == '\n') {
            table[row][2] = '\0';
            is_last_digit = false;
            if (++row >= MAX_FILE_ROW_COUNT) break;

        } else if (isdigit(c)) {
            if (is_last_digit) {
                table[row][1] = c;
            } else {
                table[row][0] = c;
                table[row][1] = c;
                is_last_digit = true;
            }
        }
        c = getchar();
    }

    for (int i = 0; i < row; i++) {
        printf("%s\n", table[i]);
        sum += atoi(table[i]);
    }

    printf("Sum is: %d\n", sum);

    for (int i = 0; i < MAX_FILE_ROW_COUNT; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}
