
char* string_copy(char *dst, char *src);

#include<stdio.h>
void main()
{
	char str1[100] = "raju is a student";
	char str2[100];

	printf("before copying str2: %s\n",str2);

	char * (*copy_ptr) (char *, char *);

	copy_ptr = string_copy;

	string_copy(str2, str1);
	

	printf("after copying str2: %s\n",str2);

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

	return dst;
}


