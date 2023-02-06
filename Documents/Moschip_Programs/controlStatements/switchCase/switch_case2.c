#include<stdio.h>
void main()
{
	unsigned int opt,unum,utemp;
	int i = 0,j = 0,count = 0,b1,b2,temp,bit1,num,bit2;

	printf("Select from below options\n1.Count no. of zeroes\n2.101 Repeated\n3.Binary Value\n4.Swap the bits\n5.replacing 101 with 111\nEnter your option:");
	scanf("%d",&opt);


	switch(opt){
		case 1:
			printf("Enter the number in hex:");
			scanf("%x",&num);
			for(i = 0; i < 32; i++){
				if((num & (0x1 << i)) == 0) count++;
			}
			printf("The number of 0's %d\n",count);
			break;

		case 2:
			printf("Enter the number in hex:");
			scanf("%x",&num);
			for(i = 0; i <= 32-3; i++){
				if( (num &( 0x7 << ( i) ) ) == (0x5 << (i) ) )
						count++;
				}
			printf("The number of 101 repeatations:%d\n",count);
			break;
		case 3:
			printf("Enter the number in hex:");
			scanf("%x",&num);
			for(i = 31; i >=0; i--){
				if( (num & (0x1 << i)) == 0) printf("0");
				else 	printf("1");
				}
			break;
		case 4:

			printf("Enter the number in hex:");
			scanf("%x",&unum);
			utemp = unum;

			for(i = 0, j = 31; i < j; i++,j--){
				utemp =( (utemp & ~((0x1<<i)|(0x1<<j)) )|( (utemp & (0x1 << i))<<(j-i) )|( (utemp & (0x1<<j))>>(j-i) ) );
			}



			printf(" after swapping: 0x%x\n",utemp);
			break;

		case 5:
			printf("Enter the number in hex:");
			scanf("%x",&num);
			temp = 0;
			for(i = 0; i <= 31 - 2; i++){
				if( ( (num &( 0x7 << i) ) ) == (0x5 << i)  )
							
				temp = ( num | (0x7 << i) );
			num = temp;
			}
			
			printf("the value is:0x%x\n",temp);
			break;
				
	}

}
	
