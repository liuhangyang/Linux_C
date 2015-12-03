/*
 *Author:yang
 *
 *Disply_Single.c
 *
 *Created on:2015年 07月 23日 星期四 10:03:01 CST
 */
  #include <sys/types.h>
#include <sys/stat.h>
 #include "Display_Single.h"
#include "Display_Flag.h"
#include "Display_attribute.h"
 #include "command.h"
 #include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*在使用-i选项时,打印名字,打印节点*/
int g_leave_len=MAXROWLEN;
void display_ino_t(struct stat buf,char *name) 
{	
	//如果本行不足打印一个文件名则换行
	printf("%7d\n",(int)buf.st_ino);
}
/*在没有使用-l选项,打印一个文件名,打印上下行对齐*/
void display_single(char *name)
{
	int i,len;
	//如果本行不足以打印一个文件名则换行
	 
	 if(g_leave_len<g_maxlen)
	{
		printf("\n");
		g_leave_len=MAXROWLEN;
	}
	len=strlen(name);
	len=g_maxlen-len;
	printf("%-s ",name);
	for(i=0;i<len;i++)
	{
		printf(" ");
	}
		printf(" ");
		//下面的2指示空两格
	g_leave_len-=(g_maxlen+2);
	
}
