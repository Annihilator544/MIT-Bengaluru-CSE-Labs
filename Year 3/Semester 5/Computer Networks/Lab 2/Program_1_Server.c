/*Write a TCP concurrent client server program where server accepts integer array from
client and sorts it and returns it to the client along with process id*/
//server side
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define PORTNO 10200
int main()
{
int sockfd,newsockfd,portno,clilen,n=1;
struct sockaddr_in seraddr,cliaddr;
int i,value;
// create an unnamed socket for the server
sockfd = socket(AF_INET,SOCK_STREAM,0);
//Name the socket
seraddr.sin_family = AF_INET;
seraddr.sin_addr.s_addr = inet_addr("172.20.16.37");
seraddr.sin_port = htons(PORTNO);
bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
//Create a connection queue and wait for clients
listen(sockfd,5);
while (1) {
int ch[256],buf[256];
printf("server waiting");
//Accept a connection
clilen = sizeof(clilen);
newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
//Read and write to client on client_sockfd (Logic for problem mentioned here)
n = read(newsockfd,ch,sizeof(ch));//read the string from the client
//sorting of array
for(int i=0;i<n;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(ch[j]>ch[j+1])
{
int temp=ch[j];
ch[j]=ch[j+1];
ch[j+1]=temp;
}
}
}
printf(" \nMessage from Client \n");
for(int i=0;i<n;i++)
{
printf("%d\t",ch[i]);
}
printf("\n");
n = write(newsockfd,ch,sizeof(ch));//write the string to the client
}
}
