//Make the necessary includes and set up the variables
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
int main()
{
int len,result,sockfd,n=1;
struct sockaddr_in address;
char ch[256],buf[256];
//Create a socket for the client
sockfd = socket(AF_INET, SOCK_STREAM, 0);//Name the socket as agreed with the server
address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("172.20.16.37");
address.sin_port=htons(10200);
len = sizeof(address);
//Connect your socket to the server’s socket
result=connect(sockfd,(struct sockaddr *)&address,len);
if(result==-1)
{
perror("\nCLIENT ERROR");
exit(1);
}
//You can now read and write via sockfd (Logic for problem mentioned here)
printf("\nENTER STRING\t");
fgets(ch,256,stdin);
//decryption of string by increasing each character by 1
for(int i=0;i<strlen(ch);i++)
{
ch[i]=ch[i]+1;
}
ch[strlen(ch)]='\0';
write(sockfd,ch,strlen(ch));//write the string to the server
printf("STRING SENT BACK FROM SERVER IS ..... ");//read the string from the server
while(n){
n=read(sockfd,buf,sizeof(buf));//print the string
puts(buf);
}
}

