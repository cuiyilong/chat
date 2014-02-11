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
    stChatSock[0].u.addr_v4.sin_port = htons(CHAT_CONTROL_UDP_PORT);
    stChatSock[0].u.addr_v4.sin_addr.s_addr = inet_addr(addr);
    
    if(TRUE != chat_sock_init(&stChatSock[0]))
    {
        LOG(LOG_ERROR," socket init fail!");
        return FALSE;
    }


    stChatSock[1].domain = AF_INET;
    stChatSock[1].type = SOCK_STREAM;
    stChatSock[1].protocol = 0;
    stChatSock[1].u.addr_v4.sin_family = AF_INET;
    stChatSock[1].u.addr_v4.sin_port = htons(CHAT_CONTROL_TCP_PORT);
    stChatSock[1].u.addr_v4.sin_addr.s_addr = inet_addr(addr);

    if(TRUE != chat_sock_init(&stChatSock[1]))
    {
       LOG(LOG_ERROR," socket init fail!");
       return FALSE;
    }

    
   
    return TRUE;
}


INT32 chat_client_comm_check_udp(void)
{
    /*use sendto*/
    #if 1
    INT32 result = 0;
    MSG stMsg;
    LOG(LOG_OFF," input your name :");
    fgets(stMsg.name,NAME_LEN,stdin);
    stMsg.type = 'L';
    LOG(LOG_OFF,"name is %s ",stMsg.name);
    result = sendto(stChatSock[0].sock_fd,&stMsg,sizeof(MSG),0,&stChatSock[0].u.addr,sizeof(struct sockaddr));
    if(result == -1)
    {
        LOG(LOG_OFF,"login fail !");
    }
    LOG(LOG_OFF,"login success !");
    return result;
    #else
    /*use sendmsg*/

    struct msghdr stMsgHdr;
    struct iovec iov;
    MSG stMsg;
    INT32 result = 0;
    LOG(LOG_OFF," input your name :");
    fgets(stMsg.name,NAME_LEN,stdin);
    stMsg.type = 'L';
    LOG(LOG_OFF,"name is %s ",stMsg.name);
    iov.iov_base = (void *)&stMsg;
    iov.iov_len = sizeof(MSG);
    
    memset(&stMsgHdr, 0, sizeof(stMsgHdr));
    stMsgHdr.msg_name = &stChatSock[0].u.addr;
    stMsgHdr.msg_namelen = sizeof(struct sockaddr_in);
    stMsgHdr.msg_iov = &iov;
    stMsgHdr.msg_iovlen = 1;
    
    result = sendmsg(stChatSock[0].sock_fd,&stMsgHdr,0);

    if(result == -1)
    {
        LOG(LOG_OFF,"login fail !");
    }
    LOG(LOG_OFF,"login success !");
    return result;
    #endif
}


INT32 chat_client_comm_check_tcp(void)
{
    struct msghdr stMsgHdr;
    struct iovec iov;
    MSG stMsg;
    INT32 result = 0;

    
    LOG(LOG_OFF," start connect to tcp server ");
    if(0 != connect(stChatSock[1].sock_fd,&stChatSock[1].u.addr,sizeof(struct sockaddr)))
    {
        LOG(LOG_ERROR," connect fail error %s ",strerror(errno));
        return FALSE;
    }
    LOG(LOG_OFF," success connect to tcp server ");
    LOG(LOG_OFF," input your name :");
    fgets(stMsg.name,NAME_LEN,stdin);
    stMsg.type = 'L';
    LOG(LOG_OFF,"name is %s ",stMsg.name);
    iov.iov_base = (void *)&stMsg;
    iov.iov_len = sizeof(MSG);
    
    memset(&stMsgHdr, 0, sizeof(stMsgHdr));
    stMsgHdr.msg_name = &stChatSock[1].u.addr;
    stMsgHdr.msg_namelen = sizeof(struct sockaddr);
    stMsgHdr.msg_iov = &iov;
    stMsgHdr.msg_iovlen = 1;
    
    result = sendmsg(stChatSock[1].sock_fd,&stMsgHdr,0);

    if(result == -1)
    {
        LOG(LOG_OFF,"login fail !");
    }
    LOG(LOG_OFF,"login success !");
    return result;
}


