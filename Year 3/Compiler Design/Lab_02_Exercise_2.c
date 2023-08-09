#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *fptr1, *fptr2;
    char filename[100], c;
    int count = 0;
    int count1 = 0;
    // printf("Enter the filename to open for reading \n");
    // scanf("%s", filename);
    fptr1 = fopen("Lab_01_Exercise_1.c", "r");
    if (fptr1 == NULL){
        printf("Cannot open file %s \n", filename);
        exit(0);
    }
    for (c = getc(fptr1); c != EOF; c = getc(fptr1)){
        if (c == '\n') // Increment count if this character is newline
            count1 = count1 + 1;
        if(c=='#'){
            while(c!='\n'){
                c = getc(fptr1);
            }
        }
        printf("%c",c);
        count++;
    }    
    printf("number of characters = %d\n", count);
    printf("number of lines = %d\n", count1);
    fclose(fptr1);
    return 0;
}