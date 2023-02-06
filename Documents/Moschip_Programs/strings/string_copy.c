










char* string_copy(char *dst, char *src)
{
	//	printf("entered into copy\n");
	int i = 0;
	for( i = 0; src[i] != '\0'; i++)
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return dst;
}
