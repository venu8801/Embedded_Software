
void search_string(char *src, char *dst);
int string_compare(char *src,char *dst,int n);
#include<string.h>
#include<stdio.h>
void main()
{


	char src[100];

	printf("Enter the string\n");

	scanf("%[^\n]s",src);

	char dst[100];

	printf("Enter the string\n");
	scanf("%s",dst);



	int n, m, i,stack = 0;
	int c = 0;
	n = strlen(dst);

	m = strlen(src);

	for(i = 0; i <= (m-n); )
	{
		stack = string_compare(&src[i],dst,n);

		if(stack == 0)
		{
			c++;
			i = i + n;
		}
	
		i++;
	}
	printf("string is found\n");
	printf("count:%d\n",c);
	
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

