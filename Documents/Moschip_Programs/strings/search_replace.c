int search_string(char *src, char *dst, int m, int n);
int string_compare(char *src,char *dst,int n);
void string_copy(char *dst, char *src, int s);
void search_replace(char *ptr, char* dst,char *replace);
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{

	int n, m, i,stack = 0,ret;
	char *str1;

	str1 = (char *) malloc(101 * sizeof(char));
			//printf("old length: %d\n",strlen(str1));
	printf("%p\n",str1); // starting address

	printf("Enter the string\n");

	scanf("%[^\n]s",str1);
	printf("old length: %d\n",strlen(str1));

	char dst[100];

	printf("Enter the string\n");
	scanf("%s",dst);


	n = strlen(dst);

	m = strlen(str1);

	char replace[20];

	ret = search_string(str1, dst, m, n);
	printf("ret:%d\n",ret);
	if(ret >= 1)
	{
		printf("Enter string to be replaced: ");

		scanf("%s",replace);
		str1 = (char *) realloc( str1,  ( (strlen(replace) * ret) + m )  * sizeof(char)  );
		str1[m] = ' ';
		for(i = m + 1; i < (m + (strlen(replace)*ret) ); i++ )
		{
			str1[i] = ' ';
		}
		str1[i] = '\0';	
		printf("New length: %d\n",strlen(str1));
		
		search_replace(str1,dst,replace);
		//str1[(m + strlen(replace))] = '\0';
			
		printf("after replacing:\n %s\n",str1);
	}
	else
		printf("string not replaced:%s\n",str1);

}



int search_string(char *src, char *dst, int m, int n)
{
	
	int i,c = 0, stack = 0;

	for(i = 0; i <= (m-n); )
	{
		stack = string_compare(&src[i],dst,n);

		if(stack == 0)
		{
			c++;
			i = i + n;
		}
		else
		i++;
	}
	if(c >= 1)
	{
		printf("string is found\n");
		printf("count:%d\n",c);
	}
	else 
		printf("string not found\n");
	return c;	
}

int string_compare(char *s1,char *s2,int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		if(s1[i] != s2[i] )
			return 1;
	}
	return 0;
}



void search_replace(char *ptr, char *src, char *replace)
{
		int i,c = 0, stack = 0;
		int l = strlen(ptr);
		int n = strlen(src);
		int k = strlen(replace);
	for(i = 0; i <= (l-k); )
	{
		stack = string_compare(&ptr[i],src,n);
	
		if(stack == 0)
		{
			printf("%p\n",&ptr[i]); // ith address
			string_copy(&ptr[i], replace, l);
			i = i + n;
		}
		else
		i++;
	}
}
void string_copy(char *dst, char *src, int s)
{

	int i;

	for(i = 0; i < s; i++)
	{
		dst[i] = src[i];

	}
	

}
