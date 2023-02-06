/*this program uses function pointer to call the function instead of function name*/

int str_len(char *str);

#include<stdio.h>
void main()
{

	char str[1000];

	printf("Enter string to find its size:");
	scanf("%s",str);
	
	int (*len_ptr) (char *);

	len_ptr = str_len;

	 int ret =  len_ptr(str);


	printf("the size of string is: %d\n",ret);


}


int str_len(char *str)
{
	int i = 0;

	for(i; i < str[i] != '\0'; i++);


	return i;
}

