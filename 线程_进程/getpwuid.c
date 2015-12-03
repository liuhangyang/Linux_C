#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
void my_err(const char *err_string,int line)
{
	fprintf(stderr,"line:%d",line);
	perror(err_string);
	exit(1);
}
int main(int argc,char *argv[])
{
	struct stat buf;
	struct passwd  *my_info;
	struct  group  *grp;
	if(stat(argv[1],&buf)==-1)
	     my_err("stat",__LINE__);
	my_info=getpwuid(buf.st_uid);
	grp=getgrgid(buf.st_gid);
	printf("文件所有者的信息");
	printf( "my name = [%s]\n", my_info->pw_name );
	printf( "my passwd = [%s]\n", my_info->pw_passwd );
	printf( "my uid = [%d]\n", my_info->pw_uid );
	printf( "my gid = [%d]\n", my_info->pw_gid );
	printf( "my gecos = [%s]\n", my_info->pw_gecos);
	printf( "my dir = [%s]\n", my_info->pw_dir );
	printf( "my shell = [%s]\n", my_info->pw_shell );
	printf("文件所属组的信息:");
	printf("group name =[%s]\n",grp->gr_name);
	printf("group passwd = [%s]\n",grp->gr_passwd);
	printf("组识别码 = [%d]\n",grp->gr_gid);
	printf("组成员账号 = [%s]\n",*(grp->gr_mem));
}
