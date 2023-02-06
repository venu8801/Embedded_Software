#include<stdio.h>
void main()
{
	char alphabet = 'a';

//	char alpha = 'b';
///	char alpha1 = 'c';
	//char alpha2 = 128;

	double *cptr = NULL;

	cptr = &alphabet;

//	*cptr = 'b';

	printf("data in alphabet: %c  -- address of alphabet:%p\n",alphabet, &alphabet);
	
	printf("using pointer-> data in alphabet: %u -- address of alphabet:%p\n",*cptr, cptr);

//	printf("data in alpha: %d  -- address of alphabet:%p\n",alpha, &alpha);
//	printf("data in alpha: %d  -- address of alphabet:%p\n",alpha1, &alpha1);
//	printf("data in alpha: %d  -- address of alphabet:0x%x\n",alpha2, &alpha2);

}


