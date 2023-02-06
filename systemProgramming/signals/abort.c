// understanding SIGABRT in gdb tool
#include<stdio.h>
#include<unistd.h>
void main()
{
	printf("hello\n");
	abort();
}
