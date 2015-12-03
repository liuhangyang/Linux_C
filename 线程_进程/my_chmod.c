/**Copyright(c):杨龙飞;
  * All right reserved;
  *程序名:改变文件的权限;
  *程序描述:利用chmod函数实现自己的chmod函数;
  *创建日期:2015年 06月 02日 星期二 19:16:07 CST
  */
  
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	int mode; //权限;
	int mode_u;//所有者权限;
	int mode_g;//所属组权限;
	int mode_o;//其他用户的权限;
	char *path;
/*检查参数个数的合法性*/
if(argc < 3)
{
	printf("%s <mode num> <target file>\n",argv[0]);
	exit(0);
}
/*获取命令行参数*/
if(strcmp(argv[1],"u+w")==0)
{
       chmod(argv[2],S_IWUSR);
	exit(0);
}
mode=atoi(argv[1]);
mode_u=mode / 100;
mode_g=(mode - mode_u*100) / 10;
mode_o=mode % 10;
mode=(mode_u*8*8+mode_g*8+mode_o);//八进制转换;
path=argv[2];
if(chmod(path,mode)==-1)
{
	perror("chmod error");
	exit(1);
}
}
