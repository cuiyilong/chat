#include "chat_server.h"

#define BUFMAX 1000

INT32 comm_fd[FD_MAX] = {0};


typedef enum{
    TCP_SOCK=0,
    UDP_SOCK=1,   
};



CHAT_SOCK stChatSock[SOCKET_MAX];

void * chat_server_comm_tcp(void *data)
{
    INT32 client_sock;
    struct sockaddr_in client_addr;
    MSG stMsg;
    INT32 datalen;
    socklen_t  from_len = 1;
    memset(&client_addr,0,sizeof(struct sockaddr_in));
   
    /**/
    stChatSock[TCP_SOCK].domain = AF_INET;
    stChatSock[TCP_SOCK].type = SOCK_STREAM;
    stChatSock[TCP_SOCK].protocol = 0;
    stChatSock[TCP_SOCK].u.addr_v4.sin_family = AF_INET;
    stChatSock[TCP_SOCK].u.addr_v4.sin_port = htons(CHAT_CONTROL_TCP_PORT);
    
    if(FALSE== chat_sock_init(&stChatSock[TCP_SOCK]))
    {
        LOG(LOG_ERROR,"udp socket init   fail!");
        pthread_exit((void *)0);
    }

    if(FALSE== chat_sock_bind(&stChatSock[TCP_SOCK]))
    {
        LOG(LOG_ERROR,"udp socket init   fail!");
        pthread_exit((void *)0);
    }
    if(0 > (listen(stChatSock[TCP_SOCK].sock_fd,128)))
    {
        LOG(LOG_ERROR," listen  fail :  error %s! ",strerror(errno));
        pthread_exit((void *)0);
    }
    HERE;
    while(1)
    {
        /*recv form client*/
        if((client_sock = accept(stChatSock[TCP_SOCK].sock_fd,(struct sockaddr *)&client_addr,&from_len))< 0)
        {
            LOG(LOG_ERROR," recv connect  fail :  error %s! ",strerror(errno));
            break;
        };
        LOG(LOG_INFO,"recv connect Client IP:%s  len is %d!",inet_ntoa(client_addr.sin_addr),from_len);
        
        if((datalen = recv(client_sock,&stMsg,sizeof(MSG),0))< 0)
        {
            LOG(LOG_ERROR,"tcp recv data fail :error %s! ",strerror(errno));
            close(client_sock);
            break;
        }
        else
        {
            LOG(LOG_OFF,"tcp recv data  : datalen %d msg name : %s! ",datalen,stMsg.name);
        }
        close(client_sock);
        
        
        

    }
}


void * chat_server_comm_udp(void *data)
{
    struct sockaddr_in client_addr;
    MSG stMsg;
    INT32 datalen;
    INT32 from_len;
    /**/
    stChatSock[UDP_SOCK].domain = AF_INET;
    stChatSock[UDP_SOCK].type = SOCK_DGRAM;
    stChatSock[UDP_SOCK].protocol = 0;
    stChatSock[UDP_SOCK].u.addr_v4.sin_family = AF_INET;
    stChatSock[UDP_SOCK].u.addr_v4.sin_port = htons(CHAT_CONTROL_UDP_PORT);
    
    if(FALSE== chat_sock_init(&stChatSock[UDP_SOCK]))
    {
        LOG(LOG_ERROR,"udp socket init   fail!");
        pthread_exit((void *)0);
    }

    if(FALSE== chat_sock_bind(&stChatSock[UDP_SOCK]))
    {
        LOG(LOG_ERROR,"udp socket init   fail!");
        pthread_exit((void *)0);
    }
    HERE;
    while(1)
    {
        /*recv form client*/
        if((datalen = recvfrom(stChatSock[UDP_SOCK].sock_fd,&stMsg,sizeof(MSG),0,(struct sockaddr *)&client_addr,(socklen_t *)(&from_len)))< 0)
        {
            LOG(LOG_ERROR,"udp recv data fail : datalen %d error %s! ",datalen,strerror(errno));
        };
       
        
         LOG(LOG_INFO,"recv msg from :%s Client IP:%s  len is %d!",stMsg.name,inet_ntoa(client_addr.sin_addr),from_len);
        
        

    }
}


/*init communication socket*/
INT32 chat_server_comm_init(void)
{
    INT32 iRet;
    pthread_t tcp_socket,udp_socket;
    iRet = pthread_create(&tcp_socket,NULL,chat_server_comm_tcp,NULL);
    if(iRet != 0)
    {
        return FALSE;
    }
    iRet = pthread_create(&udp_socket,NULL,chat_server_comm_udp,NULL);
    if(iRet != 0)
    {
        return FALSE;
    }
    return TRUE;
}

