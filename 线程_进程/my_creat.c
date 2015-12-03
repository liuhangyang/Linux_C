/**Copyright(c):杨龙飞;
  *All right reserved;
  *程序名:实现文件的创建;
  *程序描述:使用open系统调用在当前目录创建一个test.v文件;
  *创建日期:2015年 06月 02日 星期二 19:54:00 CST
  */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main()
{        
	 int fd;
	if((fd=open("test.c",O_CREAT | O_EXCL, S_IRUSR | S_IWUSR))==-1)
	{
	   // if((fd=creat("test.c",S_IRWXU))==-1)
	//	perror("open");
		printf("open:%s  with errno:%d\n",strerror(errno),errno);
		exit(1);
	}
	else
	{
		printf("creat file success\n");
	}
close(fd);
return 0;
}
  
