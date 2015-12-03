#include <stdio.h>
int main(int argc,char *argv[],char **envp)
{
	int i;
	printf("Ardument:\n");
	for(i=0;i<argc;i++)
	{
		printf("argv[%d] is %s\n",i,argv[i]);
	}
	printf("Enviroment:\n");
	printf("%d\n",**envp);
}
