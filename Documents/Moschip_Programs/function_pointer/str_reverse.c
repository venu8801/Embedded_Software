// function pointer for our own function
// to do this we need to know the declaration of that particular function
char* str_reverse(char*);
#include<stdio.h>
#include<string.h>
void main()
{
	char string[20];
	char str2[20];
	printf("enter a string\n");

	scanf("%s",string);

	char* (*revptr) (char*);

	revptr = str_reverse;

	 revptr(string);
	printf("%s\n",string);
	


}








// our own function string reverse function
char* str_reverse(char *str)
{
	int i;
	char temp;
	int len = strlen(str);
	printf("fucntion invoked\n");
	for(i = 0; i < len/2; i++)
	{
		if(str[i] != str[len - i - 1])
		{
			temp = str[i];

			str[i] = str[len - i - 1];

			str[len - i - 1] = temp;

		}

	}

	return str;
}
