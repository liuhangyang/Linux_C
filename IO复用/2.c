/*************************************************************************
	> File Name: 2.c
	> Author:yanglongfei 
	> Mail:yanglongfei@xiyoulinux.org 
	> Created Time: 2016年04月12日 星期二 21时31分15秒
 ************************************************************************/
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    int fd;
    fd=open("1.txt",O_CREAT);
    printf("%d\n",fd);
}
