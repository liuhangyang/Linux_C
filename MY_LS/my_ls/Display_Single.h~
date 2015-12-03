/*
 *Author:yang
 *
 *Disply_Single.h
 *
 *Created on:2015年 07月 23日 星期四 10:07:16 CST
 */
#ifndef Display_H_
#define Display_H_
#define MAXROWLEN	80
 //int g_leave_len=MAXROWLEN;	//一行剩余长度,用于输出对齐
  int g_maxlen;	//存放在某目录下最长文件名的长度
/*在没有使用-l选项,打印一个文件名,打印上下行对齐*/
void display_single(char *name);
/*在使用-i选项时,打印名字,打印节点*/
void display_ino_t(struct stat buf,char *name);
#endif
