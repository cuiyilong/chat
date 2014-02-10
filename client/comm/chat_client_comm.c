#include "chat_client.h"

#define BUFMAX 1000

INT32 comm_fd[FD_MAX] = {0};






CHAT_SOCK stChatSock[SOCKET_MAX];


/*init communication socket*/
INT32 chat_client_comm_init(INT8 *addr)
{
    
    
    INT8 aucBuf[BUFMAX] = {0};

    stChatSock[0].domain = AF_INET;
    stChatSock[0].type = SOCK_DGRAM;
    stChatSock[0].protocol = 0;
    stChatSock[0].u.addr_v4.sin_family = AF_INET;
    stChatSock[0].u.addr_v4.sin_port = htons(CHAT_CONTROL_PORT);
    stChatSock[0].u.addr_v4.sin_addr.s_addr = inet_addr(addr);
    
    if(TRUE != chat_sock_init(&stChatSock[0]))
    {
        LOG(LOG_ERROR," socket init fail!");
        return FALSE;
    }
   
    return TRUE;
}


INT32 chat_client_comm_check(void)
{
    INT32 result = 0;
    MSG stMsg;
    LOG(LOG_OFF," input your name :");
    fgets(stMsg.name,NAME_LEN,stdin);
    stMsg.type = 'L';
    LOG(LOG_OFF,"name is %s ",stMsg.name);
    result = sendto(stChatSock[0].sock_fd,&stMsg,sizeof(MSG),0,&stChatSock[0].u.addr,sizeof(struct sockaddr_in));
    if(result == -1)
    {
        LOG(LOG_OFF,"login fail !");
    }
    LOG(LOG_OFF,"login success !");
    return result;
}


