/* server side code for ipv4 */
#include<stdio_ext.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	int serv_fd, cli_fd, cli_size, ret;
	char buf[256];
	struct sockaddr_in serv, client;
	
		serv_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		printf("server socket fd: %d\n",serv_fd);
		if(serv_fd < 0)
		{
			printf("failed to create socket\n");
			exit(2);
		}

		//initializing structure with zeroes
		if(memset(&serv, 0, sizeof(struct sockaddr_in)))
			printf("structure initialized\n");

		//updating members inside server structure
		serv.sin_family = AF_INET;
		serv.sin_port = htons(7000);  //port number set to 5000
		serv.sin_addr.s_addr = INADDR_ANY;

		//binding structure details to socket
		ret = bind(serv_fd,  (struct sockaddr *)&serv, sizeof(serv));
		if(ret < 0)
		{
			printf("bind failed\n");
			close(serv_fd);
			exit(1);
		}
		else
			printf("bind successful\n");

		
		//waiting for client
		printf("--waiting for client\n");
		listen(serv_fd, 3);  //a max of 3 clients can be accepted
	
		cli_size = sizeof(client);

		//accepting requests from clients
		cli_fd = accept(serv_fd, (struct sockaddr *)&client, &cli_size);   //passing size of client structures int variables address
		while(1)
		{
		ret = read(cli_fd, buf, 256);

		write(1, buf, ret);
		printf("\n[s]: ");
		scanf("%[^\n]s",buf);
		__fpurge(stdin);

		ret = write(cli_fd, buf, strlen(buf));

		//close(cli_fd);	
		}

}	


