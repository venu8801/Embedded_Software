/* program to swap content of two files */
/* */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
void main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("invalid arguements please use -h to know usage\n");
		exit(2);
	}
	if(argc <= 2)
	{
		if( (argv[1][0] == '-') && (argv[1][1] == 'h'))
		{
			printf("usage---\n");
			printf("swap   <source_filename_with_path>  <destination file name with path> ");
			exit(0);
		}
		printf("invalid arguements please use -h to know usage\n");
		exit(2);
	}

	//creating a buffer size same as filesize
	char *nptr1, *nptr2;
	char *ptr = (char *)malloc(1024 * sizeof(char));
	char *ptr2 = (char *)malloc(1024 * sizeof(char));
	if(ptr == NULL || ptr2 == NULL)
	{
		printf("failed to allocate memory in heap\n");
		exit(1);
	}

	int fd1, fd2, ret;
	int buff_size1, buff_size2;
	fd1 = open(argv[1],  O_RDWR);
	fd2 = open(argv[2], O_RDWR);
	if( (fd1< 0) || (fd2 < 0) ) 
	{
		printf("failed to open %s file\n",argv[1]);
		exit(1);
	}
	buff_size1 = lseek(fd1, 0, SEEK_END);  //gets the size of the file but also modifies f_cursor to EOF
	printf("buff_size1 = %d\n",buff_size1);
	lseek(fd1, 0, SEEK_SET); //setting the cursor back to 0
	nptr1 = (char *)realloc(ptr, buff_size1); // increaseing the buffer size to file size
	if(nptr1 == NULL)
	{
		printf("failed to re-allocate memory in heap\n");
		exit(1);

	}
	ret = read(fd1, nptr1, buff_size1);  // using nptr because if buffer size is large enough then a new address is taken instead of old address
					    // increasing
	printf("no. of bytes read: %d\n",ret);
	if(ret == 0)
		printf("copied to buffer from %s\n",argv[1]);

	


	/*---------------------------------*/

	buff_size2 = lseek(fd2, 0, SEEK_END);  //gets the size of the file but also modifies f_cursor to EOF
	printf("buff_size2 = %d\n",buff_size2);
	lseek(fd2, 0, SEEK_SET); //setting the cursor back to 0
	nptr2 = (char *)realloc(ptr2, buff_size2); // increaseing the buffer size to file size
	if(nptr2 == NULL)
	{
		printf("failed to re-allocate memory in heap\n");
		exit(1);

	}
	ret = read(fd2, nptr2, buff_size2);  // using nptr because if buffer size is large enough then a new address is taken instead of old address
	printf("no. of bytes read: %d\n",ret);
					    // increasing
	if(ret == 0)
		printf("copied to buffer from %s\n",argv[2]);

	close(fd1);
	close(fd2);
	fd1 = open(argv[1], O_TRUNC | O_RDWR);

	fd2 = open(argv[2], O_TRUNC | O_RDWR);

	ret = write(fd1, nptr2, buff_size2);
	
	printf("%d bytes wrote to %s\n",ret, argv[1]);

	ret = write(fd2, nptr1, buff_size1);
	printf("%d bytes wrote to %s\n",ret, argv[2]);
	

	

	
}
