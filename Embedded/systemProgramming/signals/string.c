#include<stdio.h>
#include<string.h>
char *getstring()
{
	char src[] = "hello miss";
	char *ptr = src;
	return ptr;


}

char *putstring()
{
	char buf[] = "baby";

}

void main()
{
	char *str = getstring();
	char *ptr1 = putstring();
	printf("%s",str);


}
