#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
 int sockfd;
 int len;
 struct sockaddr_in address;
 int result;
 char *str = "GET /index.html HTTP/1.1\nHost: fxddtc\n\n";
 int port;
char buf[1024];
 if(argc != 2) {
	printf("./simpleclient port\n");
	exit(1);
 }
 printf("port: %s\n", argv[1]);
 port = atoi(argv[1]);
 printf("port: %d\n", port);
 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 address.sin_family = AF_INET;
 address.sin_addr.s_addr = inet_addr("127.0.0.1");
 address.sin_port = htons(port);
 len = sizeof(address);
 result = connect(sockfd, (struct sockaddr *)&address, len);

 if (result == -1)
 {
  perror("oops: client1");
  exit(1);
 }
 write(sockfd, str, strlen(str));
 read(sockfd, buf, 1024);
 printf("char from server = %s\n", buf);
 close(sockfd);
 exit(0);
}
