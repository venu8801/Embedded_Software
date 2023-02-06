
//int string_compare(char *str1, char *str2);
void string_finder(char *, char *);
#include<stdio.h>
#include<string.h>
void main()
{
	char str1[1000] ;
	char str2[100];
	
	printf("enter statement: ");
	scanf("%[^\n]",str1);

	printf("enter string to be searched: ");
	scanf("%s",str2);

	printf("entered statement: %s\n", str1);
	printf("string to be compared:%s\n",str2);

	string_finder(str1,str2);







}

/*int string_compare(char *str1, char *str2)
	{
	//	printf("entered into compare\n");
	int i = 0;

	if(str1 == NULL || str2 == NULL)
		return -1;
	for( i = 0; ( str1[i] != '\0' || str2[i] != '\0') ; i++)
	{
		if(str1[i] == " ")
			str1 = str1[i]; 
			continue;
		if( str1[i] != str2[i] )
		{
			return -1;
		}

	}
	return 0;
}	
*/




void string_finder(char *str1, char *str2)
{/*
	int i = 0, j = 0, k;
	int temp = 0, count = 0;

	// str1 ="all the best"
	// str2 = "all"
	for( k = 0; str1[k] != '\0'; k++)  // run until end of sentence 
	{
		//for(j=0;str2[j];j++)
		//{
	//	if(str1[k] == str2[i]) // if starting character matches with str2
	//	{		
			temp =  k;
			for( j = 0; str2[j] != '\0'; j++,temp++)
			{
				if(str1[temp] == str2[j])
					count++;
			}
		
			
			if(count == strlen(str2))
			{
				printf("string is found\n");
				return;
			}
			
		//	else k = temp;
			
		//}
	}*/
	int cnt=0,j=0;
	for(int i=0;str1[i];i++)
	{
		if(str1[i]==str2[j])
		{
			cnt++;
			j++;
		}
	}
	 printf("cnt =%d\n",cnt);

		if(cnt==strlen(str2))
			printf("FOUND\n");
		else
			printf("NOT FOUND\n");
	//}
}

































