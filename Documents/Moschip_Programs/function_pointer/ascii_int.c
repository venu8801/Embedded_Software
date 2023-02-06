int ascii_int(char *);

#include<stdio.h>
void main()
{
	char str[100];

	printf("Enter number: ");
	scanf("%s",str);

	int (*ptr) (char*);
	ptr = ascii_int;
	int ret = ptr(str);

	printf("num: %d\n",ret);
}


int ascii_int(char *str)
{
	int i = 0;
	int sum = 0, ascii;

	for( i = 0; str[i] != '\0'; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			ascii = str[i] -'0';
			sum  = sum*10 + ascii;
		}
	}
	return sum;
}
