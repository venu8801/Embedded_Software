
#include<stdio.h>
void main()
{	unsigned long int start, totalend, input;
	unsigned long  int B,kB,MB,GB;
	B = 1;
	kB = 1024 * B;
	MB = 1024 * kB;
	GB = 1024 * MB;
	start = 0x0;

	unsigned long int p1e, p1ae, p2ae;

	p1e = (512 * MB) - 1;

	p1ae = (256 *MB) - 1;

	p2ae = (768 * MB) - 1;
	
		printf("Total Size 1GB\n");
		printf("Total Memory Start Address:0x%x \t End: 0x%x\n",start,(GB) - 1);



	printf("----------------------\n");

		printf("Partition 1 Size:512MB\n");

		printf("Partition 1 Start Address:0x%x \t Partition 1 End: 0x%x\n",start,p1e);

		printf("P1 Block A Start Address: 0x%x \t P1 Block A End Address: 0x%x\n",start, p1ae );


		printf("P1 Block B Start Address: 0x%x \t P1 Block B End Address: 0x%x\n",p1ae + 1, p1e);
	
	printf("----------------------\n");

		printf("Partition 2 Size:512MB\n");

		printf("Partition 2 Start Address:0x%x \t Partition 2 End: 0x%x\n",p1e + 1,GB - 1);

		printf("P2 Block A Start Address: 0x%x \t P2 Block A End Address: 0x%x\n",p1e + 1,p2ae  );

		printf("P2 Block B Start Address: 0x%x \t P2 Block B End Address: 0x%x\n",p2ae+1 , (GB - 1));
		
	printf("----------------------\n");
		printf("Enter the address in hex:");

		scanf("%x",&input);

	printf("----------------------\n");

		if((input >= 0x0000000) && (input < GB)){
			if(input < (p1ae + 1))
				printf("Partition 1 Block A\n");
			else if ( input < (p1e + 1))
			       printf("Partition 1 Block B\n");
			else if  (input < ( p2ae + 1))
				printf("Partition 2 Block A\n");
			else 
				printf("Partition 2 Block B\n");
		}
		else printf("Not inside 1GB Memory");	

	printf("----------------------\n");

}






	


