#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
void febanocci(int x, int y, int k); // function signature for febanocci
int count_zeroes(int num) //function for counting the 0s
{
	int i = 0,count = 0;
	int temp;
	temp = num;
	for(i = 0; i <= 31; i++)
	{
		if( (temp & (0x1 << i)) == 0) count++;
	}
	return count;
}



void print_bin(int num)// function for printing binary
{
	int i = 0;
	unsigned int temp = num;
	for(i = 31; i >= 0; i--)
	{
		if( (temp & (0x1 << i)) == 0)
			printf("0");
		else printf("1");
	}	
}


int swap_bits(int num, int b1, int b2)
{	

	unsigned int temp = num;
	if(b1 > b2)
		temp = b1,b1 = b2, b2 = temp;
	temp = ( (num & ~((0x1<<b1)|(0x1<<b2)) ) | ( ( num & (0x1 << b1)) >> (b1 -b2) ) |( ( num & (0x1 << b2)) << (b1 -b2) ) );
	return temp;
}


int replace_one(int num) // function for replacing 101 with 111
{
	int i = 0;
	unsigned int temp = num;
	for(i = 0; i < 31 - 2; i++)
	{
		if(( temp & (0x7 << i) ) == (0x5 << i))
		{
			temp = (temp | (0x7 << i));
		}

	}
	return temp;
}

int reverse(int num) // function to reverse a number
{
	int digit = 0, rev = 0, temp = num;

	while(temp!=0)
	{
		digit=temp%10;
		rev=(rev*10)+digit;
		temp=temp/10;
	}
	return rev;
}
int sum_digits(int num)// function for sum of digits
{
	int temp = num;
	int digit = 0, sum = 0;
	while(temp > 0)
	{
		digit = temp % 10;

		temp = temp / 10;

		sum = sum + digit;
	}
	return sum;
}	

int count_digits(int num)
{
	int count = 0, temp = num;	
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
	return count;
}
int palindrome(int num) // function to check palindrome
{
	int temp = num;
	int digit = 0, rev = 0;
	while(temp > 0)
	{
		digit = temp % 10;printf("Enter values of X and Y in x,y");

		temp = temp / 10;

		rev = digit + rev * 10;
	}
	return rev;
}


void even_odd(int num)	//function for checking even or odd
{
	if(num % 2 == 0)
		printf("Even number\n");
	else
		printf("Odd number\n");
}


void swap_third_var(int a, int b)
{
	int c;

	c = a;

	a = b;

	b = c;

	printf("After swapping x=%d and y=%d\n",a,b);


}

void swap_nothird_var(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	printf("After swapping x=%d and y=%d\n",a,b);
}


void swap_bitwise(int x, int y)
{
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;	

	printf("After swapping x=%d and y=%d\n",x,y);

}








char upper_lower(char ascii)
{
	if(ascii >= 65 && ascii <= 122){
		if(ascii < 91)
			return ascii +  32;
		else if(ascii < 123)
			return ascii - 32;
		else return -1;
	}
	else return -2;
}



char integer_ascii(char ascii)
{
	if(ascii >= 48 && ascii <= 57)
	{
		return ascii - 48;
	}
	else return -1;
}


















void main()
{
	int opt,ret = 0,num,temp,b1,b2,x,y,k;
	char sub_opt,ascii;
	while(1)
	{
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

					default: printf("Invalid option\n");
				}
				break; // case 1 break
			case 2:
				printf("Select from the options\na.Reverse\nb.Sum of Digits\nc.Count\nd.Palindrome\ne.Even or Odd\n");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt){
					case 'a':
						printf("Enter number to be reversed");
						__fpurge(stdin);
						scanf("%d",&num);
						ret = reverse(num);
						printf("The Reversed number:%d\n",ret);
						break;

					case 'b':
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
						// cfebanocci(int x, int y, int k)hecking palindrome
						printf("Enter the number: ");
						__fpurge(stdin);
						scanf("%d",&num);
						ret = palindrome(num);
						if(ret == num) printf("The number is a palindrome\n");
						else printf("Number is not a palindrome\n");

					case 'e':
						printf("Enter values of X and Y in x,y");
						__fpurge(stdin);
						scanf("%d,%d",&x,&y);		printf("Enter the number:");
						__fpurge(stdin);
						scanf("%d",&num);
						even_odd(num);
						break;



					default: printf("Invalid option\n"); // case nested default
				}
				break; // case 2 break
			case 3:
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
				printf("Enter num1 and num2 in num1,num2 format");
				__fpurge(stdin);
				scanf("%d,%d",&x,&y);	
				printf("max range ?: ");
				__fpurge(stdin);
				scanf("%d",&k);
				febanocci(x,y,k);


			default: (" Invalid option selected\n");
		}
	}
}




void febanocci(int x, int y, int k)
{
	int z = 0;
	printf(" %d %d ",x,y);
	while(z < k){


		x = y;
		y = z;
		z = x + y;
		if(z < k)
			printf("%d ",z);

	}
}




