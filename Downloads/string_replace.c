


int string_compare(char *input, char *srch, int slen);
int search_string(char *input, char *srch);
int  string_copy(char *dst, char *src, int ind);
void replace_string(char *input,char *search,char *replace,char *out);

#include<stdio.h>
#include<string.h>

void main()
{
	char input[1000]; 
	char out[1000];
	printf("Enter the input:");
	scanf("%[^\n]",input);
	
	char srch[50];

	printf("Enter the string to search:");
	scanf("%s",srch);

	int cnt = search_string(input, srch);
	if(cnt >= 1)
	{
		char replace[100];
		printf("Enter the string to replace:");
		scanf("%s",replace);
		replace_string(input,srch,replace,out);
	}
	

}

int search_string(char *input, char *srch)
{
	int ilen, slen;
	int count= 0; 
	ilen = strlen(input);// length of input string
	slen = strlen(srch); // length of search string
	int i, sret; // 
	for(i = 0; i <= (ilen - slen);   )
	{	
		printf("i:%d\n",i);
		sret = string_compare(&input[i],srch,slen);
		if(sret == 0)
		{
			count++;
			printf("count:%d\n",count);
			i = i + slen;
		}
		else
			i++;
	}
printf("count:%d\n",count);
	if(count >= 1)
		printf("string is found %d times\n", count);
	else
		printf("stirng is not found\n");
	return count;
}
int string_compare(char *input, char *srch, int slen)
{
	int i;
	for(i = 0; i < slen; i++ )
	{
		if(input[i] != srch[i]);
		return 1;
	}
	return 0;
}
								

void replace_string(char *input,char *srch,char *replace,char *out)
{

	int ilen, slen, rlen;
	int count = 0; 
	ilen = strlen(input);// length of replace string
	slen = strlen(srch);
       	rlen = strlen(replace);	// length of searhc string
	int i, sret = 0; // 
	int ind = 0; // current index value of new string
	for(i = 0; i <= (ilen - slen);   )
	{
		sret = string_compare(&input[i],srch,slen);
		if(sret == 0)
		{
			ind = string_copy(out,replace,ind);
			if(input[i + slen] == ' ' )
			{	
				i = i + slen;
				ind++;
				out[ind] = ' ';
			}
			else
			{
				i = i + slen;
			}
		}
	}
}
int  string_copy(char *dst, char *src, int ind)
{

	int i;

	for(i = ind; i < ind; i++)
	{
		dst[i] = src[i];

	}
	return i;


}








