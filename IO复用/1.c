/*************************************************************************
	> File Name: 1.c
	> Author:yang 
	> Mail:yanglongfei@xiyoulinux.org
	> Created Time: 2016年03月06日 星期日 09时48分37秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
extern char **environ;
int main(int argc,char *argv[])
{
    pid_t pid;
    while(1){
        pid=fork();
        if(fork==0){
            execve("./epoll_client",environ,argv);
        }
    }
    
    return 0;
}
