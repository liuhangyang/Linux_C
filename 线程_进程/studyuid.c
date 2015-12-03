/*
 *Author:yang
 *创建日期:2015年 07月 22日 星期三 10:27:24 CST
 *程序名:studyuid.c
 *程序说明:setuid,setgid练习实例;
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
extern  int errno;
void show_ids(void)
{
	printf("实际用户ID = %d\n",getuid());
	printf("实际用户组ID = %d\n",geteuid());
	printf("有效用户ID = %d\n",getgid());
	printf("有效用户组ID = %d\n",getegid());
}
int main(int argc,char *argv[])
{
	int uid,gid;
	show_ids();
	uid=atoi(argv[1]);
	gid=atoi(argv[1]);
	if(setuid(uid)<0)
	{
		printf(",没有权限,设置uid错误\n");
	}	show_ids();
	return 0;
}
