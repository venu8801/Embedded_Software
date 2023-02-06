
int string_compare(char *str1, char *str2); // function declaration
#include<stdio.h>
void main()
{
	char str1[100];
	char str2[100];
	
	printf("Enter string 1:");
	scanf("%s",str1);
	printf("Enter string 2:");
	scanf("%s",str2);

	int (*sptr) (char *, char *);

	sptr = string_compare;

	 int ret = sptr(str1,str2);

	 if(ret == 0)
		 printf("Same strings\n");
	else
		printf("not same\n");

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
