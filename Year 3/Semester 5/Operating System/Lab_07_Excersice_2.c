#include<stdio.h>
int main()
{
int numSecteur=10;
char secteur[1024];
FILE* disqueF=fopen("/dev/sda6","r"); 
fseek(disqueF, numSecteur *512,SEEK_SET); 
fread(secteur, 1024, 1, disqueF);
//printf("%s",se 
for (int i = 0 ;i < sizeof(secteur); i++) { 
    printf("%x", secteur[i]); 
    if ( (i + 1) % 16 == 0) 
    printf ("\n");
}
fclose(disqueF); 
return 0;
}