#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	if((pid=fork())==-1)
	{
		printf("fork error!\n");
		exit(1);
	}
	if(pid==0)
	{
		printf("getpid rerturn %d\n",getpid());
	}
	exit(0);
}
