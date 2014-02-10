#include "chat_server.h"

#define BUFMAX 1000

INT32 comm_fd[FD_MAX] = {0};






CHAT_SOCK stChatSock[SOCKET_MAX];


/*init communication socket*/
INT32 chat_server_comm_init(void)
{
    struct sockaddr addr;
    struct sockaddr_in client_addr;
    MSG stMsg;
    INT32 datalen;
    INT32 from_len;
    /**/
    stChatSock[0].domain = AF_INET;
    stChatSock[0].type = SOCK_DGRAM;
    stChatSock[0].protocol = 0;
    stChatSock[0].u.addr_v4.sin_family = AF_INET;
    stChatSock[0].u.addr_v4.sin_port = htons(CHAT_CONTROL_PORT);
    
    if(FALSE== chat_sock_init(&stChatSock[0]))
    {
        LOG(LOG_ERROR,"udp socket init   fail!");
        return FALSE;
    }

    if(FALSE== chat_sock_bind(&stChatSock[0]))
    {
        LOG(LOG_ERROR,"udp socket init   fail!");
        return FALSE;
    }

    while(1)
    {
        /*recv form client*/
        if((datalen = recvfrom(stChatSock[0].sock_fd,&stMsg,sizeof(MSG),0,(struct sockaddr *)&client_addr,(socklen_t *)(&from_len)))< 0)
        {
            LOG(LOG_ERROR,"udp recv data fail : datalen %d error %s! ",datalen,strerror(errno));
        };
       
        
            LOG(LOG_INFO,"recv msg from :%s Client IP:%s  len is %d!",stMsg.name,inet_ntoa(client_addr.sin_addr),from_len);
        
        

    }
}

