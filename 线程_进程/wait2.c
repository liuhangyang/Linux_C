/*
 *Author:yang
 *程序名:wait2.c
 *程序描述:wait函数实例
 *创建日期:2015年 07月 22日 星期三 08:43:01 CST
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	pid_t pid,pc;
	int status;
	printf("wait实例:\n");
	pid=fork();
	if(pid<0)//创建出错,
		printf("error ocurred!\n");
	else if(pid == 0)   //如果是子进程
	{
		printf("我是子进程的ID=%d\n",getpid());
		sleep(10);  //睡眠10秒
		exit(7);
	}
	else  //父进程
	{
//	    pc=waitpid(pid,&status,WNOHANG);  //等待子进程结束;
		pc=wait(&status);
	    if(WIFEXITED(status))
	    if(WIFEXITED(status))
	    {
	        printf("我是父进程,我等待的子进程的id号=%d\n",pc);
		printf("退出码是%d\n",WEXITSTATUS(status));
	    }
	    else
	    {
		printf("子进程退出异常!\n");
	    }
	}
	exit(0);
}	
		
 
