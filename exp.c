#include<stdio.h>
#include<string.h>
void main()

{

	int l,i=0,count,k=0,j=0;
	char a[10];
	char b[10];
	printf(" enter the string\n");
	scanf("%s", a);
	l = strlen(a);
	for( i =0 ; i<l ;i++)
	{
		printf("entered into the loop\n");
		if ( a[i]>= '0' && a[i]<= '9')
		{
			printf("entered into the if condition\n");

			k=0;

		    	for(j = '0' ; j<= '9' ; j++,k++)
		       	{
				printf("entered into the inner for loop\n");
			       	if(a[i] == j)
				{
					count++;
					b[k] = count;
				}
				printf("%s\n",b);
			}
		}
	}
	b[i] = '\0';
	printf("%s\t",b);
}
