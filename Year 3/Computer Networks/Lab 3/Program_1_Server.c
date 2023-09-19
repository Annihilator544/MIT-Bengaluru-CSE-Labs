/*Write a UDP client-server program where the client sends rows of a matrix, and the
servercombines them together as a matrix.
*/
//Server side
//UDP client-server program
//combine rows of a matrix sent by client and print the resultant matrix
//get the number of rows and columns of the matrix from the client
//get the rows of the matrix from the client
//combine the rows and print the resultant matrix
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#define PORTNO 10200
int main()
{
int sockfd,newsockfd,portno,clilen,n=1,i,j,k;
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
if(bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr))<0)
{
perror("error in bind\n");
exit(0);
}
clilen=sizeof(cliaddr);
printf("waiting for client request\n");
recvfrom(sockfd,&m,sizeof(m),0,(struct sockaddr*)&cliaddr,&clilen);
recvfrom(sockfd,&n1,sizeof(n1),0,(struct sockaddr*)&cliaddr,&clilen);
printf("no of rows=%d\n",m);
printf("no of columns=%d\n",n1);
for(i=0;i<m;i++)
{
recvfrom(sockfd,&a[i],sizeof(a[i]),0,(struct sockaddr*)&cliaddr,&clilen);
}
printf("matrix received from client\n");
for(i=0;i<m;i++)
{
for(j=0;j<n1;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
for(i=0;i<m;i++)
{
for(j=0;j<n1;j++)
{
c[i][j]=a[i][j];
}
}
printf("matrix after combining rows\n");
for(i=0;i<m;i++)
{
for(j=0;j<n1;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}
return 0;
}
