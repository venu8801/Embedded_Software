#include<stdio.h>
#include<stdlib.h> // to use exit function
#include<stdio_ext.h> // to use fpurge function
#include"venus.h"  // header file in current directory containing all the function declarations called in the main function
void main()
{
	int opt,ret = 0,num,temp,b1,b2,x,y,k,bit;
	char sub_opt,ascii;
	while(1)
	{
				printf("#-------------------------#\n");
		printf("Select a option\n0.exit\n1.Bitwise Operators\n2.Mathematical Operators\n3.Swap Content in variables\n4.ascii conversion\n5.Fibanocci series\n");
		scanf("%d",&opt);

		__fpurge(stdin);
		switch(opt){
			case EXIT: exit(0);

			case 1: 
				printf("#-------------------------#\n");
				printf("Select Options\na.Count No. zeroes\nb.Print Binary\nc.Swap Bits\nd.replace 101 with 111\ne.Set a bit\nf.Clear a bit\n");
				scanf("%c",&sub_opt);
				switch(sub_opt){


					case 'a':

						printf("Enter a number to count zeroes: ");
						__fpurge(stdin);
						scanf("%x",&num);
						ret = count_zeroes(num);
						printf("The num of zeroes in 4 byte value: %d\n",ret);
						break;

					case 'b':
						ret = 0;
						printf("Enter a number to print its binary: ");
						__fpurge(stdin);
						scanf("%x",&num);
						print_bin(num);
						break;

					case 'c':
						printf("Enter a number to swap its bits: ");
						__fpurge(stdin);
						scanf("%x",&num);
						__fpurge(stdin);
						printf("Enter values of b1,b2");
						scanf("%d,%d",&b1,&b2);
						ret = swap_bits(num,b1,b2);

						printf("After swapping:%d\n",ret);
						break;
					case 'd': 
						temp = 0;
						printf("Enter a num to replace 101 with 111: ");
						__fpurge(stdin);
						scanf("%x",&num);			
						ret =  replace_one(num);
						printf("After replacing: 0x%x\n",ret);
						break;
					case 'e':
						printf("Enter a number to set its bit: ");
						__fpurge(stdin);
						scanf("%x",&num);
						printf("Enter the bit value: ");
						__fpurge(stdin);
						scanf("%d",&bit);
						ret = set_bit(num,bit);
						printf("after setting the bit: 0x%x\n",ret);
						break;
					case 'f':
						printf("Enter a number to clear a bit: ");
						__fpurge(stdin);
						scanf("%x",&num);
						printf("Enter the bit to be cleared: ");
						__fpurge(stdin);
						scanf("%d",&bit);
						ret = clear_bit(num,bit);
						printf("after clearing the bit: 0x%x\n",ret);
						break;
					

					default: printf("Invalid option\n");
				}
				break; // case 1 break
			case 2:
				printf("#-------------------------#\n");
				printf("Select from the options\na.Reverse\nb.Sum of Digits\nc.Count\nd.Palindrome\ne.Even or Odd\n");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt){
					case 'a':// number reversing
						printf("Enter number to be reversed");
						__fpurge(stdin);
						scanf("%d",&num);
						ret = reverse(num);
						printf("The Reversed number:%d\n",ret);
						break;

					case 'b':// checking sum of digits
						printf("Enter the number: ");
						__fpurge(stdin);
						scanf("%d",&num);

						ret = sum_digits(num);
						printf("The sum of digits is: %d\n",ret);
						break;
					case 'c':
						//count digits
						printf("Enter the number: ");
						__fpurge(stdin);
						scanf("%d",&num);
						ret = count_digits(num);
						printf("The num of digits: %d\n",ret);
						break;
					case 'd':
						// checking palindrome
						printf("Enter the number: ");
						__fpurge(stdin);
						scanf("%d",&num);
						ret = palindrome(num);
						if(ret == num) printf("The number is a palindrome\n");
						else printf("Number is not a palindrome\n");
						break;

					case 'e':// checking even or odd
						printf("Enter values of X and Y in x,y");
						__fpurge(stdin);
						scanf("%d,%d",&x,&y);		
						printf("Enter the number:");
						__fpurge(stdin);
						scanf("%d",&num);
						even_odd(num);
						break;



					default: printf("Invalid option\n"); // case2 nested default
				}
				break; // case 2 break
			case 3:
				printf("#-------------------------#\n");
				printf("Select an option\na.Swap using third variable\nb.Swap without 3rd variable\nc.Swap using bitwise\n");
				__fpurge(stdin);
				scanf("%c",&sub_opt);

				switch(sub_opt){
					case 'a':printf("Enter values of X and Y in x,y");
						 __fpurge(stdin);
						 scanf("%d,%d",&x,&y);
						 swap_third_var(x,y);
						 break;

					case 'b':printf("Enter values of X and Y in x,y");
						 __fpurge(stdin);
						 scanf("%d,%d",&x,&y);
						 swap_nothird_var(x,y);
						 break;	
					case 'c':
						 printf("Enter values of X and Y in x,y");
						 __fpurge(stdin);
						 scanf("%d,%d",&x,&y);
						 printf("Before swapping x=%d and y=%d\n",x,y);	
						 swap_bitwise(x,y);
						 break;	


					default: printf("Invalid option\n");	
				}
				break; // case 3 break

			case 4:
				printf("#-------------------------#\n");
				printf("Select options\na.Upper case to lower case\nb.Integer ascii to Integer constant\n");
				scanf("%c",&sub_opt);
				switch(sub_opt){

					case 'a':
						printf("Enter Upper or Lower Case letter:");
						__fpurge(stdin);
						scanf("%c",&ascii);
						ret = upper_lower(ascii);
						if(ret == -1)
							printf("Not an alphabet\n");
						else if(ret == -2)
							printf("Not an alphabet\n");
						else 
							printf("char: %c\n",ret);

						break;

					case 'b':
						ascii = 0;
						printf("Enter an ascii Integer: ");
						__fpurge(stdin);
						scanf("%c",&ascii);
						ret = 	integer_ascii(ascii);
						if (ret == -1)
							printf("Not an ascii integer\n");
						else
							printf("%d\n",ascii - 48);
						break;

					default: printf("Invalid option\n");
				}
				break; // case 4 break	
			case 5:
				printf("#-------------------------#\n");
				printf("Enter num1 and num2 in num1,num2 format");
				__fpurge(stdin);
				scanf("%d,%d",&x,&y);	
				printf("max range ?: ");
				__fpurge(stdin);
				scanf("%d",&k);
				febanocci(x,y,k);
				break;


			default: (" Invalid option selected\n");
		}
	}
}
