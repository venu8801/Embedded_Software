/* client side code for UDP communication */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 7101

void main()
{
	int sockfd, ret;
	struct sockaddr_in serv;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0)
	{
		printf("failed to create socket\n");
		exit(1);
	}
	
	serv.sin_family = AF_INET;

	serv.sin_port = htons(PORT);

	serv.sin_addr.s_addr = inet_addr("127.0.0.1");


	sendto(sockfd, "hello from client\n", strlen("hello from client\n"), MSG_CONFIRM, (struct sockaddr *)&serv, sizeof(serv));





}

