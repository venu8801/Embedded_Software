/* project server side code */
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

	int opt, cli_size, ret;
	ret = init_db();
	if(ret == 0)
		printf("data base initialized\n");
	else
		printf("db_error");

	int servSock, clientSock;
	struct sockaddr_in serv, client;

	memset(&serv, 0, sizeof(serv));

	char buf[256];

	struct profile_user usr;

	servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	printf("servSock: %d\n", servSock); // server socket fd
	if(servSock < 0)
	{	
		printf("failed to create socket\n");


	}

	memset(&serv, 0, sizeof(serv));

	//initializing server side structure
	serv.sin_family = AF_INET;
	serv.sin_port = htons(5000);
	serv.sin_addr.s_addr = INADDR_ANY;


	//binding socket with server
	ret = bind(servSock, (struct sockaddr *)&serv, sizeof(serv));
	printf("bind: %d\n",ret);
	if(ret < 0)
	{
		printf("bind failed\n");
		exit(1);
	}
	else
		printf("bind successful\n");

	//listening for any clients


	ret = listen(servSock, 5); //max of 5 clients
	if(ret < 0)
	{
		printf("listen failed\n");
		exit(1);
	}
	else
		printf("listen successful\n");

	cli_size = sizeof(client);
	while(1)
	{
		printf("waiting for client connection------\n");
		clientSock = accept(servSock, (struct sockaddr *)&serv, &cli_size);
		if(clientSock < 0)
			printf("accept failed\n");
		else
			printf("clinet connected --\n");
		while(1)
		{
			printf("------>waiting for client message<-------\n");
			ret = read(clientSock, buf,256 );
			
			memcpy(&usr, buf, sizeof(usr) );
				//	printf("usr.u_name: %s\n",usr.u_name);
				

			printf("client side option: %d\n",usr.opt);
			switch(usr.opt)
			{

				case 0:
					printf("client disconnected\n");
					close(clientSock);

					break;

	
				case 1:
					//memcpy(&usr, buf, sizeof(usr) );
					printf("usr.u_name: %s\n",usr.u_name);
					printf("opt: %d\n",usr.opt);
					ret = create_user(usr);
					//lseek(clientSock, SEEK_SET, 0);
					if(ret == 0)
						write(clientSock, "added user\n", strlen("added user\n"));
					else
						write(clientSock, "failed to add\n", strlen("failed to add\n"));
					break;
			}
			if(usr.opt == 0)
				break;


		}

	}
		close(servSock);

}













int init_db() // function which initializes database 
{
	// directory to maintain database
	int ret;

	ret = mkdir("/home/engineer/bank_db", 0700);

	ret = chdir("/home/engineer/bank_db"); //changes current directory to database
	if(ret < 0)
	{
		printf("failed to create database directory\n");
		return -1;
	}

	return 0;

}


int create_user(struct profile_user usr)
{
	int ret;

	ret = mkdir(usr.u_name, 0700);
	if(ret < 0)
	{
		printf("failed to create user_id directory\n");
		return -1;
	}
	ret = chdir(usr.u_name); //changes current directory to database
	if(ret < 0)
	{
		printf("failed to create database directory\n");
		return -1;
	}





	int fd = open(usr.u_name, O_CREAT | O_RDWR, 0700);
	if(fd < 0)
	{	
		printf("failed to create file\n");
		return -1;
	}	

	ret = write(fd, &usr, sizeof(usr));
	if(ret < 0)
	{
		printf("failed to write file\n");
		exit(1);

	}
	else
		printf("created file successfully\n");

	ret = chdir(".."); //changes current directory to database
	if(ret < 0)
	{
		printf("failed to create database directory\n");
		return -1;
	}
	return 0;



}


