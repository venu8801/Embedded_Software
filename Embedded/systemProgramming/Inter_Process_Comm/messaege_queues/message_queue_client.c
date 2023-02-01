/* message queue client side code */
#include<stdio_ext.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
struct msg
{	
	long msgtype;
	long pid;
	char buff[200];
};
#define MSG_TYPE 1
#define KEY 0x1998860
void main()
{
	int msqid;
	struct msg message;
	msqid = msgget(KEY, 0);  //opening message inside message queue
	if(msqid < 0)
	{
		printf("failed to open message queue\n");
		exit(1);
	}

	message.msgtype = MSG_TYPE;
	message.pid = getpid();
	strcpy(message.buff, "hello from client");

	msgsnd(msqid, &message,sizeof(message),0 );

	msgctl(msqid, IPC_RMID, 0);
}
