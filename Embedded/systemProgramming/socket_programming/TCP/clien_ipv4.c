/* cleint side code to create a socket and recieve data from server*/
/* TCP communication */
#include<stdio_ext.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	int sockfd, ret;

	struct sockaddr_in serv;

	char buf[256] = "hello user [c]";
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	printf("client side fd: %d\n",sockfd);
	if(sockfd < 0)
	{
		printf("failed to create socket\n");
		exit(2);
	}

	memset(&serv, 0, sizeof(serv));

	serv.sin_addr.s_addr = inet_addr("127.0.0.1");   //self ip


	serv.sin_port  = htons(6000);

	serv.sin_family = AF_INET;

	connect(sockfd, (struct sockaddr *)&serv, sizeof(serv));
	while(1)
	{	
		printf("[c]: ");
		scanf("%[^\n]s",buf);
		__fpurge(stdin);
		ret = send(sockfd, buf, strlen(buf), 0);

		printf("--waiting for server\n");
		ret = recv(sockfd, buf, 300, 0);

		write(1, buf, ret);
		printf("\n");
		close(sockfd);
	}
}
