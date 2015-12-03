/*
 *Author:yang
 *程序名:wait2.c
 *创建日期:2015年 07月 22日 星期三 09:08:47 CST
 *程序描述:waitpid函数实例:
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	pid_t pid,pc;
	pid=fork();
	int status;
	if(pid<0)
	{
		printf("创建进程失败!\n");
	}
	else if(pid==0)
	{
		printf("我是子进程,我的ID=%d\n",getpid());
		sleep(10);
		exit(0);
	}
	else
	{
	do{
	
	   pc=waitpid(pid,&status,WNOHANG);//使用了WNOHANG参数,waitpid就不会等待,直接返回.
	   // pc=waitpid(pid,&status,0);
		if(pc==0)
		{
			printf("没有收集到子进程!\n");
			sleep(1);
		}
	   }while(pc==0);//等不到,继续等,
		if(pid==pc)
			printf("等到了子进程\n");
		else
		  printf("出错了\n");
		printf("我是父进程,我要等的进程id是%d\n",pc);
	}
	exit(0);
}
	
