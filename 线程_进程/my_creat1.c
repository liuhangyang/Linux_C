#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
int main()
{
	int fd;
	//if ((fd=open("example_62.c",O_CREAT | O_EXCL,S_IRUSR | S_IWUSR)) == -1)
	//{
		if((fd=creat("example_62.c",S_IRWXU))==-1)  {
		//perror("open");
		printf("open:%s  with errno:%d\n",strerror(errno),error);
		exit(1);
	}else{
		printf("creat file success\n");
	}
	close(fd);
	return 0;
}
