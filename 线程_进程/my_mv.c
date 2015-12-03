#include <stdio.h>
int main(int argc,char **argv)
{
	/*检查参数的个数*/
	if(argc<3)
	{
		printf("my_mv <old file> <new file>\n");
		exit(0);
	}
	if(rename(argv[1],argv[2])<0)
	{
		perror("rename");
	}
	return 0;
}

