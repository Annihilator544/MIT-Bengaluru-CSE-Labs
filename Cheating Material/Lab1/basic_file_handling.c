#include <stdio.h>
#include <stdlib.h>

// Task 1: Count the number of lines and characters in a file
void countLinesAndCharacters(FILE *file, int *numLines, int *numChars) {
    int ch;
    *numLines = 0;
    *numChars = 0;

    while ((ch = fgetc(file)) != EOF) {
        (*numChars)++;
        if (ch == '\n') {
            (*numLines)++;
        }
    }

    // Increment line count if the file doesn't end with a newline
    if (*numChars > 0 && ch != '\n') {
        (*numLines)++;
    }
}

// Task 2: Reverse file contents and store in another file
void reverseFile(FILE *sourceFile, FILE *targetFile) {
    fseek(sourceFile, 0, SEEK_END);
    long fileSize = ftell(sourceFile);
    fseek(sourceFile, -1, SEEK_CUR); // Move back by 1 to avoid EOF

    char ch;

    while (fileSize > 0) {
        ch = fgetc(sourceFile);
        fputc(ch, targetFile);
        fseek(sourceFile, -2, SEEK_CUR); // Move back by 2 to skip the current character and read the previous one
        fileSize--;
    }
}

// Task 3: Merge lines alternatively from 2 files and store in a resultant file
void mergeLinesAlternatively(FILE *file1, FILE *file2, FILE *resultFile) {
    char line1[100];
    char line2[100];

    while (!feof(file1) || !feof(file2)) {
        if (fgets(line1, sizeof(line1), file1) != NULL) {
            fputs(line1, resultFile);
        }

        if (fgets(line2, sizeof(line2), file2) != NULL) {
            fputs(line2, resultFile);
        }
    }
}

int main() {
    FILE *file, *reversedFile, *mergedFile;
    char filename[100];
    int numLines, numChars;

    // Task 1: Count the number of lines and characters in a file
    printf("Enter the filename to count lines and characters: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    countLinesAndCharacters(file, &numLines, &numChars);
    printf("Number of lines: %d\n", numLines);
    printf("Number of characters: %d\n", numChars);

    fclose(file);

    // Task 2: Reverse the file contents and store in another file
    file = fopen(filename, "r");
    reversedFile = fopen("reversed_file.txt", "w");

    if (file == NULL || reversedFile == NULL) {
        printf("Error opening files for reversing.\n");
        return 1;
    }

    reverseFile(file, reversedFile);

    printf("File contents reversed and saved in 'reversed_file.txt'.\n");

    fclose(file);
    fclose(reversedFile);

    // Task 3: Merge lines alternatively from 2 files and store in a resultant file
    char filename2[100];
    printf("Enter another filename to merge lines alternatively: ");
    scanf("%s", filename2);

    file = fopen(filename, "r");
    FILE *file2 = fopen(filename2, "r");
    mergedFile = fopen("resultant_file.txt", "w");

    if (file == NULL || file2 == NULL || mergedFile == NULL) {
        printf("Error opening files for merging.\n");
        return 1;
    }

    mergeLinesAlternatively(file, file2, mergedFile);

    printf("Lines merged alternatively and saved in 'resultant_file.txt'.\n");

    fclose(file);
    fclose(file2);
    fclose(mergedFile);

    return 0;
}
