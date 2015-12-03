/*
 *Author:yang
 *
 *Diaplay_attribute.c
 *
 *Created on:2015年 07月 23日 星期四 09:58:02 CST
 */
 #include "command.h"
#include "Display_Flag.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
/*获取文件属性并打印*/
void display_attribute(struct stat buf,char * name,int a,int b)
{
	char buf_time[32];
	struct passwd   *psd;  //从该结构体中获取文件所有者的用户名
	struct group    *grp;	//从该结构体中获取文件所属组的组名
/*获取并打印文件类型*/
if(b==1)
{
	printf("%7d  ",(int)buf.st_ino);
}	
if(S_ISLNK(buf.st_mode))	
{
	printf("l");
}
else if(S_ISREG(buf.st_mode))
{
	printf("_");
}
else if(S_ISDIR(buf.st_mode))
{
	printf("d");
}
else if(S_ISCHR(buf.st_mode))
{
	printf("c");
}
else if(S_ISBLK(buf.st_mode))
{
	printf("b");
}
else if(S_ISFIFO(buf.st_mode))
{
	printf("f");
}
else if(S_ISSOCK(buf.st_mode))
{
	printf("s");
}
/*获取并打印文件所有者的权限*/
if(buf.st_mode & S_IRUSR)
{
	printf("r");
}
else
{
	printf("-");
}
if(buf.st_mode & S_IWUSR)
{
	printf("w");
}
else
{
	printf("-");
}
if(buf.st_mode & S_IXUSR)
{	
	printf("x");
}
else
{
	printf("-");
}
/*获取并打印文件所有者同组的用户对该文件的操作权限*/
if(buf.st_mode & S_IRGRP)
{
	printf("r");
}
else
{
	printf("-");
}
if(buf.st_mode & S_IWGRP)
{
	printf("w");
}
else
{
	printf("-");
}
if(buf.st_mode & S_IXGRP)
{
	printf("x");
}
else
{
	printf("-");
}
/*获取并打印其它用户对该文件的操作权限*/
if(buf.st_mode & S_IROTH)
{
	printf("r");
}
else
{
	printf("-");
}
if(buf.st_mode & S_IWOTH)
{
	printf("w");
}
else
{			
	printf("-");
}
if(buf.st_mode & S_IXOTH)
{
	printf("x");
}
else
{
	printf("-");
}

printf("   ");
/*根据uid和gid获取所有者的用户与组名*/
psd=getpwuid(buf.st_uid);
grp=getgrgid(buf.st_gid);
printf("%4d ",(int)buf.st_nlink);	//打印文件的链接数
printf("%-8s",psd->pw_name);
if(a==1)
{
 printf("%-8s",grp->gr_name);
}

printf("%6d",(int)buf.st_size);	//打印文件的大小
strcpy(buf_time,ctime(&buf.st_mtime));
buf_time[strlen(buf_time)-1]='\0'; //去掉换行符
printf(" %s ",buf_time);			//打印文件的时间信息
}
