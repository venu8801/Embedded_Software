#include<stdio.h>
int main()
{
	int sum=0,rem,temp,x,prog,num,count,i=1;
	printf("Enter the program number\n 1-Reverse\n 2-Sum of digits\n 3-Count\n 4-Palindrome\n 5-Binary\n 6-Even or Odd\n   ");
	scanf("%d",&prog);
	switch(prog)
	{
		case 1:
			printf("Enter the value to be reversed: ");
			scanf("%d",&num);
			sum=0;
			temp=num;
			while(temp!=0)
			{
				rem=temp%10;
				sum=(sum*10)+rem;
				temp=temp/10;
			}
			printf("The Reversed number:%d",sum);
			break;


		case 2:
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
				printf("The Count of digits is: %d",count);
			}
			else
				count++;
			        printf("The Count of digits is: %d",count);

			break;


		case 3:
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
			break;


		default:
			printf("nothing");
	}
}


