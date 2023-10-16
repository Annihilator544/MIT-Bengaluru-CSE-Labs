#include <stdio.h>

void main(){
	FILE *source, *target;
	char ch;
	char filename[100];
	printf("Enter filename to access: " );
	scanf("%s", filename);
	printf("input recieved");
	source = fopen(filename, "r");
	target = fopen("result.txt", "w");
	
	if(source == NULL){
		printf("Invalid source file");
		return;
	}
	
		
	do{
		char c = fgetc(source);
		printf("%c", c);
		if(feof(source))
			break;
		if(c == '\t' || c == ' '){
			continue;
		}
		fputc(c, target);
	} while(1);
	fclose(source);
	fclose(target);
}
