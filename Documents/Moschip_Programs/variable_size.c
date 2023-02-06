#include<stdio.h>
int main()
{
	char x = -198;
	printf("%d\n",x);// prints +ve 58
	printf("%c\n",x);// prints 58s ASCII value

	 x = 198;
	printf("%d\n",x);// prints -ve 58
	printf("%c\n",x);// prints -58s ASCII value

	unsigned char  z = 198;
	printf("%d\n",z);// prints +ve 198
	printf("%c\n",z);// prints 198s 2sComps -58 eq ASCII value
	 z = -198;
	printf("%d\n",z);// prints +ve 
	printf("%c\n",z);// prints 198s 2sComps -58 eq ASCII value
	return 0;
}
