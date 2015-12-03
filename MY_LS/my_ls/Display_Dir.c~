/*
 *Author:yang
 * 
 *Created on:\2015年 07月 23日 星期四 10:18:28 CST
 *
 *Disply_Dir.c
 */
 #include "Display_Dir.h"
#include "command.h"
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include "Display_Flag.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void display_dir(int flag_param,char *path)
{
	DIR	*dir;
	struct dirent	*ptr;
	int count=0;
	char filenames[256][PATH_MAX+1],temp[PATH_MAX+1];
	//获取该目录下的文件总数和最长的文件名
	dir=opendir(path);
	if(dir == NULL)
	{
		my_err("opendir",__LINE__);
	}
	while((ptr=readdir(dir))!=NULL)
	{
		if(g_maxlen< strlen(ptr->d_name))
			g_maxlen=strlen(ptr->d_name);
		count++;
	}
	closedir(dir);
	if(count>256)
	{
		my_err("too many file under this dir",__LINE__);
	}
	int i,j,len=strlen(path);
	//获取目录下的所有文件名
	dir=opendir(path);
	for(i=0;i<count;i++)
	{
		ptr=readdir(dir);
		if(ptr==NULL)
		{
			my_err("readdir",__LINE__);
		}
		strncpy(filenames[i],path,len);
		filenames[i][len]='\0';
		strcat(filenames[i],ptr->d_name);
		filenames[i][len+strlen(ptr->d_name)] ='\0';
	}
	//使用冒泡排序法对文件名进行排序,排序后按字母顺序存储于filename
	for(i=0;i<count-1;i++)
		for(j=0;j<count-1-i;j++)
		{
			if(strcmp(filenames[j],filenames[j+1])>0)
			{
				strcpy(temp,filenames[j+1]);
				temp[strlen(filenames[j+1])]=='\0';
				strcpy(filenames[j+1],filenames[j]);
				filenames[j+1][strlen(filenames[j])]='\0';
				strcpy(filenames[j],temp);
				filenames[j][strlen(temp)]='\0';
			}
		}
	if((flag_param & PARAM_R)==0)		//如果命令中没有-r选项，
	{
	  for(i=0;i<count;i++)
	  {
		display(flag_param,filenames[i]);
	 }
	}
	else
	{
		for(i=count-1;i>=0;i--)
		{
		    display(flag_param,filenames[i]);
		}
	}
	closedir(dir);
	//如果命令行中没有-l选项,打印一个换行符
	if((flag_param & PARAM_L)==0)
		printf("\n");
}
