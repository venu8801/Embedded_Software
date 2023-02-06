void print_character_count(char *str);
#include<stdio.h>
void main()
{
  char str[1000];


  printf("Enter the string:\n");
  scanf("%s",str);
  printf("------------\n");
  printf("Entered stirng: %s\n",str);



  print_character_count(str);
  printf("------------\n");
  

}



void print_character_count(char *str)
{  

  char repeated[100] = {'\0'};
        
  int i = 0, count, j,flag,ind,k = 0;
  for( i = 0; str[i] != '\0'; i++)
  {  
    count = 0, flag = 0;
    for(ind = 0; repeated[ind] != '\0' ; ind++)
    {  
      if(str[i] == repeated[ind])
      {
        flag = 1;
        break;
      }
      flag = 0;  
    }
    if(flag == 1)
    {
    
      continue;
    }
    for(j = 0; str[j] != '\0'; j++)
    {
      if(str[i] == str[j])
        count++;
        
    }

    repeated[k] = str[i];
    k++;

    printf("char: %c ----count: %d\n",str[i],count);
  }
}
