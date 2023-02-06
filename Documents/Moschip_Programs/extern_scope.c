/*#include<stdio.h>
int main()
{
	printf("number:%d\n",x);
	return 0;
}
int x = 9;*/

// this results in compilation error as there is no variable x in function main()






extern int x; // extern keyword allows us to use variable which have file scope 
#include<stdio.h>
int main()
{
	printf("number:%d\n",x);
	return 0;
}
int x = 9;
