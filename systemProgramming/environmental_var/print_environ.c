/* this program prints environmental variables */
#include<stdio.h>
void main(int argc, char *argv[], char *env[])
{
	printf("cmd line arguements: %d\n", argc);
	int i = 0;
	while(argv[i])
	{
		printf("%d-->\t %s\n",i,argv[i]);
		i++;
	}

	i = 0;
	while(env[i])
	{
		printf("%d-->\t %s\n",i,argv[i]);
		i++;
	}
}

