/*
 *Aythor:yang
 *
 *Created on:2015年 07月 23日 星期四 10:14:04 CST
 *
 *Disply_Flag.h
 */
#ifndef Dispaly_FLag_H_
#define Display_Flag_H_
#define PARAM_NONE	0	//无参数
#define PARAM_A	1	//-a;显示所有文件
#define PARAM_L 2	//-l;一行只显示一个文件的详细信息 
#define PARAM_I 4       //-i:显示i节点
#define PARAM_G 8	//-i:显示文件信息，去掉
#define PARAM_R 20	//按字母排序的逆序输出
#define PARAM_T  33	//按修改时间排序
#define MAXROWLEN	80  //一行显示的最多字符数
//int g_leave_len=MAXROWLEN;
void display(int flag,char *pathname);
#endif
