#include<stdio.h>
#include<stdlib.h>
void main()
{
	int opt,count,i,b1,b2,temp,rev,digit,sum,x,y,z,k;
	char sub_opt,ascii;
	unsigned int num;

while(1){
		printf("Select a option\n0.exit\n1.Bitwise Operators\n2.Mathematical Operators\n3.Swap Content in variables\n4.ascii conversion\n5.Fibanocci series\n");
		scanf("%d",&opt);

		__fpurge(stdin);

		switch(opt){
			case 0: exit(0);

			case 1: 
				printf("Select Options\na.Count No. zeroes\nb.Print Binary\nc.Swap Bits\nd.replace 101 with 111\n");
				scanf("%c",&sub_opt);
				switch(sub_opt){
					case 'a':
						count = 0;
						i = 0;
						printf("Enter a number to count zeroes: ");
						__fpurge(stdin);
						scanf("%x",&num);
						for(i = 0; i <= 31; i++){
							if( (num & (0x1 << i)) == 0) count++;
						}
						printf("The num of zeroes in 4 byte value: %d\n",count);
						break;
					case 'b':
						printf("Enter a number to print its binary: ");
						__fpurge(stdin);
						scanf("%x",&num);
						for(i = 31; i >= 0; i--){
							if( (num & (0x1 << i)) == 0)
								printf("0");
							else printf("1");
						}
						break;

					case 'c':
						temp = 0;
						b1 = b2 = 0;
						printf("Enter a number to swap its bits: ");
						__fpurge(stdin);
						scanf("%x",&num);
						__fpurge(stdin);
						printf("Enter values of b1,b2");
						scanf("%d,%d",&b1,&b2);
						if(b1 > b2)
							temp = b1,b1 = b2, b2 = temp;
						temp = ( (num & ~((0x1<<b1)|(0x1<<b2)) ) | ( ( num & (0x1 << b1)) >> (b1 -b2) ) |( ( num & (0x1 << b2)) << (b1 -b2) ) );

						printf("After swapping:%d\n",temp);

					case 'd': 
						temp = 0;
						printf("Enter a num to replace 101 with 111: ");
						__fpurge(stdin);
						scanf("%x",&num);
						for(i = 0; i < 31 - 2; i++){
							if(( num & (0x7 << i) ) == (0x5 << i)) {
								num = (num | (0x7 << i));
							}
						}
						printf("After replacing: 0x%x\n",num);
						break;

					default:
						printf("Invalid Input\n");
				}
				break;

			case 2:
				printf("Select from the options\na.Reverse\nb.Sum of Digits\nc.Count\nd.Palindrome\ne.Binary\nf.Even or Odd\n");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt){
					case 'a':
						num = 0;
						digit = 0;#include<stdlib.h>
						rev = 0;
						temp = 0;

						printf("Enter number to be reversed");
						__fpurge(stdin);
						scanf("%d",&num);

						temp=num;
						while(temp!=0)
						{
							digit=temp%10;
							rev=(rev*10)+digit;
							temp=temp/10;
						}
						printf("The Reversed number:%d\n",rev);
						break;
					case 'b':
						sum = 0;
						temp = 0;
						num = 0;
						printf("Enter the number: ");
						__fpurge(stdin);
						scanf("%d",&num);
						temp=num;
						while(temp > 0){
							digit = temp % 10;

							temp = temp / 10;

							sum = sum + digit;
						}
						printf("The sum of digits is: %d\n",sum);
						sum = 0;
						break;
					case 'c':
						printf("Enter the number: ");
						__fpurge(stdin);
						scanf("%d",&num);
						count=0;
						temp=num;
						if(temp!=0)
						{
							while(temp!=0)
							{
								temp=temp/10;
								count++;
							}
						}
						else
							count++;
						printf("The num of digits: %d\n",count);
						break;
					case 'd':
						printf("Enter the number: ");
						__fpurge(stdin);
                        			scanf("%d",&num);
						temp = num;
						while(temp > 0){
						digit = temp % 10;

						temp = temp / 10;

						rev = digit + rev * 10;
						}
						if(rev == num) printf("The number is a palindrome\n");
						else printf("Number is not a palindrome\n");
						break;
					case 'f':
						printf("Enter the number:");
						__fpurge(stdin);
						scanf("%d",&num);
						if(num % 2 == 0)
							printf("Even number\n");
						else
							printf("Odd number\n");
						break;
					default:
						printf("Invalid Input\n");
			
				}
				break;
			case 3:
				printf("Select an option\na.Swap using third variable\nb.Swap without 3rd variable\nc.Swap using bitwise");
				__fpurge(stdin);
				scanf("%c",&sub_opt);

				switch(sub_opt){
					case 'a':
						x=0,y=0,z=0;
						printf("Enter values of X and Y in x,y");
						__fpurge(stdin);
						scanf("%d,%d",&x,&y);
						printf("Before swapping x=%d and y=%d\n",x,y);
						z = x;

						x = y;

						y = z;

						printf("After swapping x=%d and y=%d\n",x,y);
						break;
					case 'b':
						x=0,y=0,z=0;
						printf("Enter values of X and Y in x,y");
						__fpurge(stdin);
						scanf("%d,%d",&x,&y);
						printf("Before swapping x=%d and y=%d\n",x,y);
						x = x + y;
						y = x - y;
						x = x - y;
						printf("After swapping x=%d and y=%d\n",x,y);
						break;
					case 'c':
						printf("Enter values of X and Y in x,y");
						__fpurge(stdin);
						scanf("%d,%d",&x,&y);
						printf("Before swapping x=%d and y=%d\n",x,y);
						x = x ^ y;
						y = x ^ y;
						x = x ^ y;
						printf("After swapping x=%d and y=%d\n",x,y);
						break;
					default: printf("Invalid Input\n");
						}
					break;
		

		case 4:
			printf("Select options\na.Upper case to lower case\nb.Integer ascii to Integer constant");
				scanf("%c",&sub_opt);
				switch(sub_opt){
					case 'a':
						printf("Enter Upper or Lower Case letter:");
						__fpurge(stdin);
						scanf("%c",&ascii);
						if(ascii >= 65 && ascii <= 122){
							if(ascii < 91)
								printf("%c\n",ascii +  32);
							else if(ascii < 123)
								printf("%c\n",ascii - 32);
							else printf("Not an alphabet\n");
						}
						else printf("Not an alphabet\n");
						break;
					case 'b':
						ascii = 0;
						printf("Enter an ascii Integer: ");
						__fpurge(stdin);
						scanf("%c",&ascii);
						if(ascii >= 48 && ascii <= 57)
						{
							printf("%d\n",ascii - 48);
						}
						else printf("Not an ascii integer\n");
						break;
					default:
						printf("Not a valid option\n");
				}
			break;	
			
						
		case 5:
			printf("Enter num1 and num2 in num1,num2 format");
			__fpurge(stdin);
			scanf("%d,%d",&x,&y);	
			printf("How many series: ");
			__fpurge(stdin);
			scanf("%d",&k);
			int i = 0;
			printf(" %d %d ",x,y);
			while(i < k){
				
				z = x + y;
				x = y;
				y = z;
		 	printf("%d ",z);
			i++;
			}
			break;
		default:
			printf("Invalid Input");

		}// for outer switch case
	}//while loop 
}	
