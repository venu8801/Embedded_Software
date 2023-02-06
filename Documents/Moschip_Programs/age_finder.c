#include<stdio.h>
void main()
{
	unsigned short int year;
	unsigned char month, date;
	unsigned short int cyear;
	unsigned char cmonth, cdate;


	printf("Enter date/month/year in dd/mm/yy format: ");

	scanf("%d/%d/%d",&date,&month,&year);

	printf("Enter current date/month/year in dd/mm/yy format: ");

	scanf("%d/%d/%d",&cdate,&cmonth,&cyear);



	printf("current age %d years, %d months and 
		%d days\n", cyear-year, cmonth-month, cdate-date);
}	

