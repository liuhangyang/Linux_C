#include "command.h"
#include <stdio.h>
#include <error.h>
#include <stdlib.h>
/*错误处理函数,打印出错误所在行的行数和错误信息*/
void my_err(const char *err_string,int line)
{
	fprintf(stderr,"line:%d ",line);
	perror(err_string);
	exit(1);
}
