/*************************************************************************
	> File Name: epoll_server.c
	> Author:yang 
	> Mail:yanglongfei@xiyoulinux.org
	> Created Time: 2016年03月05日 星期六 15时58分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<unistd.h>
#include<sys/types.h>  

#define IPADDRESS "127.0.0.1"
#define PORT 1996 
#define MAXSIZE 1024
#define LISTENQ 5 
#define FDSIZE  1000
#define EPOLLEVENTS 100  
//函数声明  
//创建套接字并进行绑定  
static int socket_bind(const char* ip,int port);
//IO多路复用epoll  
static void do_epoll(int listenfd);
//事件处理函数  
static void handle_events(int epollfd,struct epoll_event *events,int num,int listenfd,char *buf);
//处理接受到的连接  
static void handle_accept(int epollfd,int listenfd);
//读处理
static void do_read(int epollfd,int fd,char *buf);
//写处理 
static void do_write(int epollfd,int fd,char *buf);
//添加事件  
static void add_event(int epollfd,int fd,int state);
//修改事件
static void modify_evvent(int epollfd,int fd,int state);
//删除事件  
static void delete_event(int epollfd,int fd,int state);

int main(int argc,char *argv[])
{
    int listenfd;
    listenfd=socket_bind(IPADDRESS,PORT);
    listen(listenfd,LISTENQ);
    do_epoll(listenfd);
    return 0;
}
static int socket_bind(const char *ip,int port)
{
    int listenfd;
    struct sockaddr_in serveraddr;
    listenfd=socket(AF_INET,SOCK_STREAM,0);
    if(listenfd == -1){
        perror("socket error\n");
        exit(1);
    }
    bzero(&serveraddr,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    inet_pton(AF_INET,ip,&serveraddr.sin_addr);
    serveraddr.sin_port=htons(port);
    if(bind(listenfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr))==-1){
        perror("bind error\n");
        exit(1);
    }
    return listenfd;
}
static void do_epoll(int listenfd)
{
    int epollfd;
    struct epoll_event events[EPOLLEVENTS];
    int ret;
    char buf[MAXSIZE];
    memset(buf,0,sizeof(buf));
    //创建一个描述符 
    epollfd=epoll_create1(0);
    //添加监听描述符事件  
    add_event(epollfd,listenfd,EPOLLIN);
    for(; ;){
        //获取已经准备好的描述符事件
        ret=epoll_wait(epollfd,events,EPOLLEVENTS,-1);
        handle_events(epollfd,events,ret,listenfd,buf);
    }
    close(epollfd);
}
static void add_event(int epollfd,int fd,int state)
{
    struct epoll_event ev;
    ev.events=state;
    ev.data.fd=fd;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&ev);

}
static void handle_events(int epollfd,struct epoll_event*events,int num,int listenfd,char *buf)
{
    int i;
    int fd;
    //进行选好遍历
    for(i=0;i<num;i++){
        fd=events[i].data.fd;
        //根据描述符的类型和事件类型进行处理
        if((fd == listenfd) && (events[i].events & EPOLLIN)){
            handle_accept(epollfd,listenfd);
        }else if(events[i].events & EPOLLIN){
            do_read(epollfd,fd,buf);
        }else if(events[i].events & EPOLLOUT){
            do_write(epollfd,fd,buf);
        }
    }
}
int i=0;
static void  handle_accept(int epollfd,int listenfd)
{
    int clifd;
    struct sockaddr_in cliaddr;
    socklen_t cliaddrlen;
    clifd=accept(listenfd,(struct sockaddr*)&cliaddr,&cliaddrlen);
    if(clifd == -1){
        perror("sccept error\n");
    }else{
        i++;
        printf("%d ",i);
        printf("sccept a new client:%s:%d\n",inet_ntoa(cliaddr.sin_addr),cliaddr.sin_port);
        //添加一个客户描述符和事件
        add_event(epollfd,clifd,EPOLLIN);
    }
}
static void do_read(int epollfd,int fd,char *buf)
{
    int nread;
    nread=read(fd,buf,MAXSIZE);
    if(nread == -1){
        perror("read error\n");
        close(fd);
        delete_event(epollfd,fd,EPOLLIN);
    }else if(nread == 0){
        perror("client close\n");
        close(fd);
        delete_event(epollfd,fd,EPOLLIN);
    }else{
        printf("read message is:%s",buf);
        //修改描述符对应的事件,由读改为写;
        modify_evvent(epollfd,fd,EPOLLOUT);
    }
}
static void do_write(int epollfd,int fd,char *buf)
{
    int nwrite;
    nwrite=write(fd,buf,strlen(buf));
    if(nwrite == -1){
        perror("write error\n");
        close(fd);
        delete_event(epollfd,fd,EPOLLOUT);
    }else{
        modify_evvent(epollfd,fd,EPOLLIN);
        memset(buf,0,MAXSIZE);
    }
}
static void delete_event(int epollfd,int fd,int state)
{
    struct epoll_event ev;
    ev.events=state;
    ev.data.fd=fd;
    epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,&ev);
}
static void modify_evvent(int epollfd,int fd,int state)
{
    struct epoll_event ev;
    ev.events=state;
    ev.data.fd=fd;
    epoll_ctl(epollfd,EPOLL_CTL_MOD,fd,&ev);

}
/*static void delete_event(int epollfd,int fd,int state)
{
    struct epoll_event ev;
    ev.events=state;
    ev.data.fd=fd;
    epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,ev);
}*/
