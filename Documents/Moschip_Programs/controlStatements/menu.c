#include<stdio.h>
void main()
{	unsigned long int start, totalend,u,half;
	unsigned long  int B,kB,MB,GB;
	B = 1;
	kB = 1024 * B;
	MB = 1024 * kB;
	GB = 1024 * MB;
	printf("Enter Total Size: in GB\n");
	scanf("%ld",&u)
	half=u/2;
	start = 0x0;
	printf("Start Adress: 0x%x \t End Address: 0x%x \n",start,u*GB);


	printf("----------------------\n");

	printf("Partition 1 Size:%dMb\n",half);

	printf("Partition 1 Start Address:0x%x \t Partition 1 End: 0x%x\n",start,half*MB);

	printf("Start Adress: 0x%x \t End Address: 0x%x \n",s`tart,u*GB);

	printf("----------------------\n");

	printf("Partition 1 Size:%dMb\n",half);

	printf("Partition 1 Start Address:0x%x \t Partition 1 End: 0x%x\n",start,half*MB);

}
