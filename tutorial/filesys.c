#include <stdio.h>	/* standard input, output */
#include <stdlib.h>	/* contains exit function */
#include <unistd.h>	/* contains read and write functions */
#include <sys/types.h>	/* contains all the structure about files */
#include <sys/stat.h>	/* tells about the status of the file */
#include <fcntl.h>	/* contains all the flags useful for file operations */
#include <errno.h>	/* gines us the erron number if we get any */
#include <string.h>	/* string functions */
#include <stdint.h>	/* for uint32_t */

/* start of main function */
void main()
{
	uint32_t fd,sz;
	char buf[200] = {0};
	off_t offset;

	//fd = open("Makefile",O_RDONLY);
	//fd = open("newfile.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IROTH);
	// O_EXCL : if the file already exists, the open call will fail
	
	strcpy(buf,"This is the Sample Data\n");
	
	//fd = open("mask.c", O_WRONLY | O_TRUNC );
	
	fd = open("mask.c", O_RDWR);

	//fd = open("mask.c", O_WRONLY | O_APPEND );
	printf("discriptor = %d\n",fd);
	if (fd < 0)
	{
		printf("open() was failed - errno = (%d)\n",errno);
		perror("ERROR:");
		exit(1);
	}
	//sz = read(fd, buf, 200);
	
	read(fd, buf,10);

	//printf("call 1 - called read. fd = %d, %d bytes were read.\n",fd,sz);
	
	//buf[10] = '\0';
	
	//printf("length of buffer is (%d)\n",(uint32_t)strlen(buf));
	//sz = write(fd, buf, strlen(buf));
	//printf("write() returned %d\n",sz);
	//close(fd);
	
	printf("Read bytes are as follows: \n%s\n",buf);

	offset = lseek(fd, 5, SEEK_CUR);
	if ( offset == (off_t) -1)
	{
		perror("Error seeking to beginning");
		close(fd);
		exit(1);
	}
	
	read(fd, buf, 10);
	//buf[10] = '\0';
	printf("Next 10 bytes : %s\n",buf);

	offset = lseek(fd, -5, SEEK_END);
	if ( offset == (off_t) -1)
	{
		perror("Error seeking to beginning");
		close(fd);
		exit(1);
	}
	printf("Next 10 bytes : %s\n",buf);
	

}
