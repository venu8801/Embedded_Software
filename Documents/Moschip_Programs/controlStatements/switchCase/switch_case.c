#include<stdio.h>
void main()
{
	int opt, num,temp,sum = 0, digit,rev = 0,rem = 0,i,count = 0,z = 1; 
while(z!=0){
	
	printf("-------------------\n");
	printf("Select from the options\n 1.Reverse\n 2.Sum of Digits\n 3.Count\n 4.Palindrome\n 5.Binary\n 6.Even or Odd\n --ENTER 0 TO EXIT--\n");
	printf("-------------------\n");
	printf("\n");
	printf("Enter Option Number:");
	scanf("%d",&opt);
	z = opt;


	switch(opt){
		case 1:
			printf("-------------------\n");
			printf("Selected Option 1\n");
			printf("-------------------\n");
			printf("Enter the number: ");
			scanf("%d",&num);
			
			temp=num;
			while(temp!=0)
			{
				digit=temp%10;
				sum=(sum*10)+digit;
				temp=temp/10;
			}
			printf("The Reversed number:%d\n",sum);
			printf("-------------------\n");
			break;

		case 2:
			printf("-------------------\n");
			printf("Selected Option 2\n");
			printf("-------------------\n");
			printf("Enter the number: ");
			scanf("%d",&num);
			temp=num;
			while(temp > 0){
				digit = temp % 10;

				temp = temp / 10;

				sum = sum + digit;
			}
			printf("The sum of digits is: %d\n",sum);
			sum = 0;
			printf("-------------------\n");
			break;
		case 3:
			printf("-------------------\n");
			printf("Selected Option 3\n");
			printf("-------------------\n");
			printf("Enter the number: ");
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
		 printf("The Count of digits is: %d\n",count);
			printf("-------------------\n");

			break;


		case 4:
			printf("-------------------\n");
			printf("Selected Option 4\n");
			printf("-------------------\n");
			printf("Enter the number: ");
			scanf("%d",&num);
			temp = num;
			while(temp > 0){
				digit = temp % 10;

				temp = temp / 10;

				rev = digit + rev * 10;
			}
			if(rev == num) printf("The number is a palindrome\n");
			else printf("Number is not a palindrome\n");
			printf("-------------------\n");
			break;
		case 5:
			printf("-------------------\n");
			printf("Selected Option 5\n");
			printf("-------------------\n");
			printf("Enter the decimal value: ");
			scanf("%d",&num);
			sum=0;
			i=1;
			temp=num;
			while(temp!=0)
			{
				rem=temp%2;
				sum=sum+(rem*i);
				temp=temp/2;
				i=i*10;
			}
			printf("The binary number is: %d",sum);
			printf("-------------------\n");
			break;

		case 6:
			printf("-------------------\n");
			printf("Selected Option 6\n");
			printf("-------------------\n");
			printf("Enter the number: ");
			scanf("%d",&num);
			temp = num;
			if(temp % 2 == 0)
				printf("Even Number\n");
			else
				printf("Odd Number\n");

			printf("-------------------\n");
			break;
		

	
	}
}

}


