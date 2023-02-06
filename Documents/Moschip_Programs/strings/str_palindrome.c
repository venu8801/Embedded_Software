// verify a given string is palindrome or not

char* reverse_string(char *str);
int string_compare(char *str1, char *str2);
char* string_copy(char *, char *);

#include<stdio.h>
void main()
{

	char str[100];
	char tmp[100];
	printf("Enter the string: ");
	scanf("%s",str);
	printf("entered string: %s\n",str);
	//	prntf("tmp = %s\n",tmp);
	string_copy(tmp,str);
	printf("after copy --> tmp = %s\n",tmp);
	reverse_string(tmp);
	printf("reversed string: %s\n",tmp);
	int cmp_result = string_compare(str,tmp);
	if(cmp_result == 0)
	{
		printf("The string is a palindrome\n");
	}
	else
		printf("Not a palindrome string\n");





}








char* reverse_string(char *str)
{
	//printf("entered into reverse\n");
	int i,j,len;
	char temp;
	for(len = 0; str[len] != '\0'; len++); // to find length of string

	for(i = 0, j = len - 1; i < j ; i++, j--)
	{
		//printf("entered in for loop\n");
		if(str[i] != str[j])
		{
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
		}
	}
	//printf("in reverse()%s\n",str);
	return str;
}


int string_compare(char *str1, char *str2)
{
	//	printf("entered into compare\n");
	int i = 0;

	if(str1 == NULL || str2 == NULL)
		return -1;
	for( i = 0; ( str1[i] != '\0' || str2[i] != '\0') ; i++)
	{
		if( str1[i] != str2[i] )
		{
			return -1;
		}

	}
	return 0;
}

char* string_copy(char *dst, char *src)
{
	//	printf("entered into copy\n");
	int i = 0;
	for( i = 0; src[i] != '\0'; i++)
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	}
	return dst;
}

