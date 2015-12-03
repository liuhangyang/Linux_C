/************************************************************************
*   作者:yang        创建日期:2015年 07月 21日 星期二 20:28:54 CST    	*
*									*
*   程序名:processimage1.c						*
*   文件描述:exe函数族函数的使用练习;					*
*									*
*									*
************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
extern char **environ;
int main()
{
	pid_t pid;
	int stat_val;
	char *argv[]={"ls","-al","/",NULL};
	printf("exec函数族实例:\n");
	//printf("exec函数实例:");
	pid=fork();
	switch(pid) {
    	case -1:
		perror("进程创建失败!\n");
		exit(1);
	case 0:
		printf("子进程正在运行!\n");
		printf("我的ID=%d,父亲的ID=%d\n",getpid(),getppid());	
		//execve("/bin/ls",argv,environ);
		//execv("/bin/ls",argv);
		//execvp("ls",argv);
		//execl("/bin/ls","ls","-al","/",NULL);
//		execlp("ls","ls","-al","/",NULL);
		execvp("ls",argv);
		printf("如果exec函数调用成功,这一句不会被执行!\n");
		exit(0);
	default:
		
		printf("父进程正在运行!\n");
		break;
	}	
     	wait(&stat_val);

	return 0;
}
