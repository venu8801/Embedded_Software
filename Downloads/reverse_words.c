
void reverse_words(char *str, char *ptr);
int word_write(char *ptr, char *word, int k);
void word_reverse(char *word);
#include<string.h>

#include<stdio.h>
void main()
{
	char str[1000];  // input string
	char dst[1000];  // output string
	printf("Enter the string: ");
	scanf("%[^\n]",str);

	reverse_words(str,dst);

	printf("%s\n",dst);



}


void reverse_words(char *str, char *ptr)
{
	char word[1000];
	int i,k = 0,j = 0;
	int n = strlen(str);
	int l;
	for(i = 0; str[i] != '\0'; i++)
	{	
		
		if(str[i] != ' ' || i == n)
		{	
			word[j++] = str[i];
			
			if(i + 1 == n)
			{
				
				word[j] = '\0';
				
				word_reverse(word);
				l = strlen(word);
				word_write(ptr, word,k);
				k = k + l+1; // +1 for null character
				ptr[k] = '\0';
			}

		}
		else
		{
		
			word[j] = '\0';
			l = strlen(word);
			word_reverse(word); // calling reverse function;		
			word_write(ptr, word,k);
			
			k = k + l+1;
			ptr[k] = '\0';
			j = 0;
		}		


	}



}
void word_reverse(char *word)
{	
	
	int len = strlen(word);
	int k , j;
	char temp;

	for(k = 0; k < len/2 ; k++)
	{
		if(word[k] != word[len - k - 1])
		{
			temp = word[k];
			word[k] = word[len - k - 1];
			word[len - k - 1] = temp;
		
		}
				
	}
	//printf("%s\n",word);

}



int word_write(char *ptr, char *word, int k)
{
	int i;
	int l = strlen(word);
	//printf("k:%d\n",k);
	for(i = 0; i <= l; i++)
	{	
		ptr[k] = word[i];
		k++;
	}
	//printf("k:%d\n",k);
	ptr[k-1] = ' ';
	ptr[k] = '\0';
	
	//printf("%s",word);
	return k;


}















