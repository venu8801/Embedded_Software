
int main()
{
	unsigned int z = -0xFFFFFFFF;  // a negative number is assigned to z
	// there are not negative values in unsigned int 
	/* if we assign like this it will do 2s complement and store it
	 *  -1 in 4 bytes 2s complement is max value of unsigned int 
	 *  that is 4294967295 */ 
	printf("%d \n",z);
	if(z > 0){ // as z is 4294967295 which is greater than 0 
		// it executes statements inside if 
		printf("-----\n");
	}
	else printf("88888");
	return 0;
}
