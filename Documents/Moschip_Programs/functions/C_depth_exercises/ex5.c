#include<stdio.h>
void func(void);
void main()
{
	int i = 5;
	for(i = i + 1; i < 8; i++)
	{
		func();
	}
}
void func(void)
{
	int j;
	for(j = 1; j < 3; j++)
	{
		printf("%d\t",++j);
	}
}

