int x = 39;// global variable
#include<stdio.h>
int main()
{
	x = 4;                                    // global variable gets updated
	printf("%d---\n",x);
        printf("address of func x: %p\n",&x);     	//global variable gets printed
	int x = 89;
	{
		printf("-- %d--\n",x);       
	   	printf("adrr of fun x:%p\n",&x);				// function variable gets printed
		int x = 45;                       // new block variable created
		printf("%d---\n",x);          
	    printf("adress of block: %p\n",x);	// block variable prints
	}
	x++;                                     // fucntion variable increments
	printf("--%d--\n",x);                    // incremented function var prints
	return 0;
}
		


