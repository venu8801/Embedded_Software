// program to find count of repeated characters in a string
void print_character_count(char *str);
#include<stdio.h>
void main()
{
  char str[1000];


  printf("Enter the string:\n");
  scanf("%s",str);
  printf("------------\n");
  printf("Entered stirng: %s\n",str);



  print_character_count(str); // calling the function
  printf("------------\n");
  

}



void print_character_count(char *str)
{  

  char repeated[100] = {'\0'};
        
  int i = 0, count, j,flag,ind,k = 0; 
  for( i = 0; str[i] != '\0'; i++)
  {  
    count = 0, flag = 0;
    for(ind = 0; repeated[ind] != '\0' ; ind++) // checking if the Kth string is already counted or not
    {  
      if(str[i] == repeated[ind])
      {
        flag = 1; // if it is already counted then flag becomes 1
        break;
      }
      flag = 0;  // if it is not found flag is 0
    }
    if(flag == 1) // if flag is 1 skip Kth iteration
    {
    
      continue;
    }
    for(j = 0; str[j] != '\0'; j++)
    {
      if(str[i] == str[j])
        count++;

    }

    repeated[k] = str[i]; // adding character that is counted
    k++;

    printf("char: %c ----count: %d\n",str[i],count);
  }
}
