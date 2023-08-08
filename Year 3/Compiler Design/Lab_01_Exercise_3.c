#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f1 = fopen("Lab_01_Exercise_1.c", "r");
    FILE *f2 = fopen("Lab_01_Exercise_2.c", "r");
    FILE *f3 = fopen("file3.txt", "w");
    char c1, c2;

    if (f1 == NULL || f2 == NULL || f3 == NULL) {
        printf("Could not open files\n");
        exit(0);
    }

    while ((c1 = fgetc(f1)) != EOF && (c2 = fgetc(f2)) != EOF) {
        if (c1 != '\n') {
            fputc(c1, f3);
        } else {
            fputc(c1, f3);
            while ((c2 = fgetc(f2)) != EOF) {
                if (c2 != '\n') {
                    fputc(c2, f3);
                } else {
                    fputc('\n', f3);
                    break;
                }
            }
        }
    }

    while ((c1 = fgetc(f1)) != EOF) {
        fputc(c1, f3);
    }

    while ((c2 = fgetc(f2)) != EOF) {
        fputc(c2, f3);
    }

    printf("Merged file1.txt and file2.txt into file3.txt\n");

    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}
