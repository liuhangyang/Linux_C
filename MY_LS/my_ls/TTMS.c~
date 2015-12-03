/*
 *Author:yang
 *
 *main_menu.c
 *
 *Created on:2015年 07月 23日 星期四 10:31:49 CST
 */
 #include "Display_Flag.h"
#include "Display_Dir.h"
#include "Display_Single.h"
 #include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc,char **argv)
{
	int i,j,k,num;
	char path[PATH_MAX+1];
	char param[32];//保存命令行参数,目标文件名不在此列
	int  flag_param=PARAM_NONE; //参数种类;
	struct  stat buf;
/*命令行参数的解析,.....*/
j=0,
num=0;
for(i=1;i<argc;i++)
{
	if(argv[i][0]=='-')
	{
		for(k=1;k<strlen(argv[i]);k++,j++)
		{
			param[j]=argv[i][k];    //获取-后面的参数保存到数组param中
		}
		num++; //保存"-"的个数
	}
}
/*只支持参数a和l,如果含有其它选项就报错*/
for(i=0;i<j;i++)
{
	if(param[i]=='a')
	{
		flag_param |= PARAM_A;
		continue;
	}
	else if(param[i]=='l')
	{
		flag_param |= PARAM_L;
		continue;
	}
	else if(param[i]=='i')
	{
		flag_param |= PARAM_I;
		continue;
	}
	else if(param[i]=='g')
	{
		flag_param |=PARAM_G;
		continue;
	}
	else if(param[i]=='r')
	{
		flag_param |= PARAM_R;
		continue;
	}
	else
	{
		printf("my_ls:invalid option -%c\n",param[i]);
		exit(1);
	}
}
param[j]='\0';
//如果没有输入文件或目录,就显示当前目录
if((num+1)==argc)
{
	strcpy(path,"./");
	path[2]='\0';
	display_dir(flag_param,path);
	return 0;
}
i=1;
do{
	//如果不是目标文件或目录,解析下一个命令行参数
	if(argv[i][0]=='-')
	{
		i++;
		continue;
	}
	else
	{
		strcpy(path,argv[i]);
		//如果不是目标文件或目录,解析下一个命令行参数
		if(stat(path,&buf)==-1)
		{
			my_err("stat",__LINE__);
		}
		if(S_ISDIR(buf.st_mode))	//argv[i]是一个目录
		// 如果目录的最后一个字符不是'/',就加上'/'
		{
			if(path[strlen(argv[i])-1]!='/')
			{
				path[strlen(argv[i])] |='/';
				path[strlen(argv[i])+1] |='\0';
			}
			else
			{
				path[strlen(argv[i])]='\0';
			}
			display_dir(flag_param,path);
			i++;
		}
		else		//argv[i]是一个文件
		{
			display(flag_param,path);
			i++;
		}
	 }
	}while(i<argc);
	return 0;
}
