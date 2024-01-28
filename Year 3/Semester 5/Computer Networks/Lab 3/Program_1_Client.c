// Path: Lab%203/Program_2_Client.c
/*Write a UDP client-server program where the client sends rows of a matrix, and the
servercombines them together as a matrix.
*/
//Client side
//UDP client-server program
//combine rows of a matrix sent by client and print the resultant matrix
//send the number of rows and columns of the matrix to the server
//send the rows of the matrix to the server
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#define PORTNO 10200
int main()
{
int sockfd,portno,clilen,n=1,i,j,k;
struct sockaddr_in seraddr,cliaddr;
int a[10][10],b[10][10],c[10][10],m,n1;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
perror("error in socket\n");
exit(0);
}
bzero((char*)&seraddr,sizeof(seraddr));
seraddr.sin_family=AF_INET;
seraddr.sin_port=htons(PORTNO);
seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
clilen=sizeof(seraddr);
printf("enter the number of rows\n");
scanf("%d",&m);
printf("enter the number of columns\n");
scanf("%d",&n1);
sendto(sockfd,&m,sizeof(m),0,(struct sockaddr*)&seraddr,clilen);
sendto(sockfd,&n1,sizeof(n1),0,(struct sockaddr*)&seraddr,clilen);
printf("enter the elements of the matrix\n");
for(i=0;i<m;i++)
{
for(j=0;j<n1;j++)
{
scanf("%d",&a[i][j]);
}
}
for(i=0;i<m;i++)
{
sendto(sockfd,&a[i],sizeof(a[i]),0,(struct sockaddr*)&seraddr,clilen);
}
printf("matrix sent to server\n");
return 0;
}
