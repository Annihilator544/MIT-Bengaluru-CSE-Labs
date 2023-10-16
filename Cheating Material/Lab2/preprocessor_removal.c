/* Open, Read and close a file: reading string by string */

# include <stdio.h>
int main( )
{
         FILE *fp ;
         char data[50] ;
         printf( "Opening the file test.c in read mode" ) ;
         fp = fopen( "randomtext.txt", "r" ) ;
         if ( fp == NULL )
         {
                 printf( "Could not open file test.c" ) ;
                 return 1;
         }
         printf( "Reading the file test.c" ) ;
         while( fgets ( data, 50, fp ) != NULL ){
             if (data[0] == '#'){
                    continue;
             }

             printf( "%s" , data ) ;
         }
         printf("Closing the file test.c") ;
         fclose(fp) ;
         return 0;
}
