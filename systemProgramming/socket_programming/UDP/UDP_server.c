/* program to establish connection between 2 systems using UDP 
 *
 * server side code */
#include<stdio_ext.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#define PORT 7101
void main()
{

	int servSock, ret;
	char buffer[200];
	struct sockaddr_in serv, client;

	servSock = socket(AF_INET, SOCK_DGRAM, 0);
	if(servSock < 0)
	{
		printf("socket creation failed\n");
		exit(1);
	}

	memset(&serv, 0, sizeof(serv));
	memset(&client, 0, sizeof(client));

	//Filling server info
	serv.sin_family = AF_INET; //IPv4
	serv.sin_addr.s_addr = INADDR_ANY;
	serv.sin_port = htons(PORT);
	
	//Binding socket with server address
	ret = bind(servSock, (struct sockaddr *)&serv, sizeof(serv));
	if(ret < 0)
	{
		printf("failed to bind\n");
		exit(1);
	}

	int clisize = sizeof(client);
	ret = recvfrom(servSock,buffer, 200, MSG_WAITALL, (struct sockaddr *)&client, &clisize);
	write(1, buffer, ret);


	

}
