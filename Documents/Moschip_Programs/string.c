#include<stdio.h>
int main()
{
	int n;
	char str[n];
	printf("enter size of string:" );
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%c",str[i]);
	}
	return 0;
}
