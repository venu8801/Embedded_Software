
void str_concatenate(char *str1, char *str2, char *str);
#include<stdio.h>
#include<stdio_ext.h>
void main()
{
	char arr1[100];
	char arr2[100];
//	char arr[sizeof(arr1) + sizeof(arr2)];
	char arr[200];
	printf("enter string 1");
	scanf("%[^\n]",arr1);
	__fpurge(stdin);
	printf("enter string 2");
	scanf("%[^\n]",arr2);
	printf("entered strings %s and %s\n",arr1,arr2);

	str_concatenate(arr1,arr2,arr);


}



void str_concatenate(char *str1, char *str2, char *str)
{
	int i,j;

//	for(len = 0; str1[len] != '\0'; len++);

	for(i = 0; str1[i] != '\0'; i++)
	{
		str[i] = str1[i];
	}
	printf("%c\n",str[i]);
	for(j = 0; str2[j] != '\0'; j++)
	{
		str[i++] = str2[j];
	//	i++;

	}
	str[i] = '\0';

	printf("after concatenation: %s\n",str);
}

		
