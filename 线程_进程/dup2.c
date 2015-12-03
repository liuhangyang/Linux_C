
#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include  <fcntl.h>
#include <unistd.h>

int main(int argc,char ** argv)
{
        int fd,fd1,fd2;
        fd2 = 5;
        fd = open("temp",O_CREAT|O_RDWR|O_TRUNC,0644);

        fd1 = dup(fd);
        write(fd1,"hello",5);
        if(dup2(fd,fd2)==-1)
                perror("dup2 error");
        write(fd2,"world",5);
        printf("fd = %d,fd1 = %d,fd2=%d\n",fd,fd1,fd2);
            
        return 0;
}   
