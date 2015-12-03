#include <stdio.h>
#include <unistd.h>
int main(void)
{
	int i=0;
	printf("I son/pid ppid fpid\n");
	//ppid指当前进程的父进程pid
	//pid指当前进程的pid
	//fpid指fork返回给当前进程的值
	for(i=0;i<2;i++)
	{
		pid_t fpid=fork();
		if(fpid==0)
			printf("%d child %d %d %d\n",i,getpid(),getppid(),fpid);
		else
			printf("%d parent %d %d %d\n",i,getpid(),getppid(),fpid);
	}
	return 0;
}
