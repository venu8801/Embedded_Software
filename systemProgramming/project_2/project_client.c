/* project client side code */
/* written by  Venu Gopal A 
 * 	*/
//----------------------includes-----------------------------------//
#include<stdio_ext.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include"bank_db.h"
//-------------------------------------//


void main()
{
	int opt;
	int sockfd, ret;
	struct sockaddr_in  serv;
	char buf[256];



	struct profile_user usr;  //user profile structure variable





	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	printf("clinet side socket fd: %d\n",sockfd);
	if(sockfd < 0)
	{
		printf("failed to create socket in client side\n");
		exit(1);
	}

	//initializing server structure addr to zeroes
	bzero(&serv, sizeof(serv));

	//structure variable initialization
	serv.sin_family = AF_INET;
	serv.sin_port = htons(5000);
	serv.sin_addr.s_addr = inet_addr("127.0.0.1");


	ret = connect(sockfd, (struct sockaddr *)&serv, sizeof(serv));
	if(ret < 0)
	{
		printf("failed to connect\n");
		exit(1);

	}
	else
		printf("connection successful\n");
	while(1)
	{

		printf("-------------------client side------------------------\n");
		printf("0.Exit\n1.Register\n2.Login\n");
		printf("select an option: ");
		__fpurge(stdin);
		scanf("%d",&opt);

		switch(opt)
		{
			case 0:
				printf("exiting----n\n");
				usr.opt = opt;
				printf("option: %d\n",usr.opt);
				ret = send(sockfd, &usr, sizeof(usr), 0);
				close(sockfd);
				exit(0);
			case 2:
				printf("------------login----------");
				break;
			case 1:
				printf("----------register--------\n");
				printf("enter user name: ");
				__fpurge(stdin);
				scanf("%[^\n]",usr.u_name);
				usr.opt = opt;
				ret = send(sockfd, &usr, sizeof(usr), 0);
				
				ret = recv(sockfd, buf, 256, 0);
				buf[ret] = '\0';
				printf("ack: %s\n",buf);
				break;


		}
	}

	close(sockfd);


}
