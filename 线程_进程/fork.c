#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	int i=5;
	printf("Process Creation Study\n");
	pid=vfork();
	switch(pid)
	{
		case 0:
			printf("Child process is running,CurPid is %d,ParentPid is %d\n",pid,getppid());
			i++;
			printf("%d",i);
			break;
		case -1:
			perror("Process creation failed\n");
			break;
		default:
			printf("Parent process is runnung,ChildPid is %d,ParentPid is %d\n",pid,getpid());
			
			printf("%d",i);
			break;
	}
		exit(0);
}
