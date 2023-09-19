// Compare this snippet from Lab%202/Program_1_Client.c:
// /*Write a TCP concurrent client server program where server accepts integer array from
// client and sorts it and returns it to the client along with process id*/
// //client side
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
int ch[256],buf[256];
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
printf("\nENTER ARRAY SIZE\t");
scanf("%d",&n);
printf("\nENTER ARRAY ELEMENTS\t");
for(int i=0;i<n;i++)
{
scanf("%d",&ch[i]);
}
write(sockfd,ch,sizeof(ch));//write the string to the server
printf("ARRAY SENT BACK FROM SERVER IS ..... ");
while(n){
n=read(sockfd,buf,sizeof(buf));//read the string from the server
for(int i=0;i<n;i++)
{
printf("%d\t",buf[i]);
}
}
//recieve process id from server
int pid;
n = read(sockfd,&pid,sizeof(pid));
printf("Process id recieved from server is %d\n",pid);
}