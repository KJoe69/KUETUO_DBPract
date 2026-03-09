#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 100

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char filename[MAX_LINE];
    char line[MAX_LINE];
    FILE *file;

    printf("File name: ");
    fgets(filename, MAX_LINE, stdin);
    filename[strcspn(filename, "\n")] = 0;

    file = fopen(filename, "w");
    printf("Give me the lines (end: #):\n");

    while (1) {
        fgets(line, MAX_LINE, stdin);
        if (line[0] == '#') {
            break;
        }
        fputs(line, file);
    }
    fclose(file);

    printf("\n\n");
    printf("--- File upper case text ---\n");

    file = fopen(filename, "r");
    while (fgets(line, MAX_LINE, file) != NULL) {
        line[strcspn(line, "\n")] = 0;
        toUpperCase(line);

        printf("%s\n", line);
    }
    fclose(file);

    return 0;
}
