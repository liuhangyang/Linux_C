/*
 *Author:yang 
 *
 *Created on:2015年 07月 23日 星期四 10:21:23 CST
 *
 *Disply_Dir.h
 */
#ifndef Display_Dir_H_
#define Display_Dir_H_
#define PARAM_NONE	0	//无参数
#define PARAM_A	1	//-a;显示所有文件
#define PARAM_L 2	//-l;一行只显示一个文件的详细信息 
#define PARAM_I 4       //-i:显示i节点
#define PARAM_G 8	//-i:显示文件信息，去掉
#define PARAM_R 20	//按字母排序的逆序输出
#define PARAM_T  33	//按修改时间排序
int g_maxlen;	
void display_dir(int flag_param,char *path);
#endif

