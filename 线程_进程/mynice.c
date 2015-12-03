/* Author:yang
 * 程序名:mynice.c
 * 程序描述:mynice的实现和练习
 * 创建日期:2015年 07月 22日 星期三 14:12:20 CST
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>
int main()
{
	pid_t  pid;
	int stat_val = 0;
	int oldpri,newpri;
printf("nice实例:\n");
pid=fork();
switch(pid)
{

	case 0:
		printf("子进程正在运行,当前的ID = %d,父进程的ID = %d\n",getpid(),getppid());
	
		oldpri=getpriority(PRIO_PROCESS,getpid());
		printf("现在的优先级 = %d\n",oldpri);
		//newpri = nice(4);
		if((setpriority(PRIO_PROCESS,getpid(),4))==-1)
			printf("出错!\n");
			newpri=getpriority(PRIO_PROCESS,getpid());
		printf("改变后的新的优先级 = %d\n",newpri);
		exit(0);
	case -1:
		perror("进程创建失败!\n");
		break;
	default:
		printf("父进程正在运行,子进程的ID = %d,父进程的 ID = %d\n",pid,getpid());
		break;
}
wait(&stat_val);}
