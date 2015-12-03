/*
 *Author:yang
 *
 *Created on:2015年 07月 23日 星期四 10:11:21 CST
 *
 *Display_Flag.c
 */
#include "Display_Flag.h"
#include "command.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*
 *根据命令行参数的完整路径显示目标文件
 *参数flag:命令行参数
 *参数pathname:包含了文件的路径名
 */
void display(int flag,char *pathname)
{
	int i,j;
	struct stat  buf;
	char name[NAME_MAX + 1];
	/*从路径中解析出文件名*/
	for(i=0,j=0;i<strlen(pathname);i++)
	{
		if(pathname[i]=='/')
		{
			j=0;
			continue;
		}
		name[j++] =pathname[i];
	}
	name[j++]='\0';
	//printf("\n\n\n\%s\n\n\n\n",name);
/*用lstat而不是stat以方便解析链接文件*/
if(lstat(pathname,&buf)==-1)
{
	my_err("stat",__LINE__);
}
switch(flag)
{
	case PARAM_NONE:  //没有选项
		if(name[0]!='.')
		{
			display_single(name);
		}
			break;
	case PARAM_A: //-a:显示包括隐藏文件在内的所有文件
		display_single(name);
		break;
	case PARAM_L:	//-l:每个文件单独占一行,显示文件的详细属性信息
		if(name[0]!='.')
		{
		   display_attribute(buf,name,1,0);
		   printf(" %-s\n",name);
		 }
		break;
	case PARAM_I: //-i:显示文件的i节点
		if(name[0]!='.')
		{
			display_ino_t(buf,name);
			printf("%s\t",name);
		}
		break;
	case PARAM_G:
		if(name[0]!='.')
		{
			display_attribute(buf,name,0,0);
			printf("%-s\n",name);
		}
		break;
	case PARAM_R:
		if(name[0]!='.')
		{
			display_single(name);
		}
		break;	
	case PARAM_R + PARAM_L:			//同时有r和l的情况
		if(name[0]!='.')	
		{
			display_attribute(buf,name,1,0);
			printf(" %-s\n",name);
		}
		break;
	case PARAM_A + PARAM_R:			//同时有a和r的情况
			display_attribute(buf,name,1,0);
			printf(" %-s\n",name);
			break;
	case PARAM_R + PARAM_G:			//同时有r和g的情况
		if(name[0]!='.')
		{
			display_attribute(buf,name,0,0);
			printf(" %-s\n",name);
		}
			break;
	case PARAM_R + PARAM_I:		//同时有r和i的情况
		if(name[0]!='.')
		{
			display_ino_t(buf,name);
			printf("%s\n",name);
		}
		break;
	case PARAM_I + PARAM_L: //同时有ｉ和l的情况
		if(name[0]!='.')
		{
			display_attribute(buf,name,1,1);
			printf("%-s\n",name);
		}
		break;
	case PARAM_I +PARAM_L +PARAM_A:			//同时有i和l和a的情况
			display_attribute(buf,name,1,1);
			printf("%-s\n",name);
			break;
	case PARAM_I + PARAM_G:		//同时有i和Ｇ的情况
		if(name[0]!='.')
		{
			display_attribute(buf,name,0,1);
			printf("%-s\n",name);
		}
		break;
	case PARAM_I + PARAM_G + PARAM_A:		//同时有i,g,a的情况
			display_attribute(buf,name,0,1);
			printf("%-s\n",name);
			break;		
	case PARAM_A+PARAM_L: //同时有-a和-l选项的情况
		display_attribute(buf,name,1,0);
		printf(" %-s\n",name);
		break;
	default:
		break;
	}
}
