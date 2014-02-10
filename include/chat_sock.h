#include "chat_public.h"


typedef struct __chat_sock{
    INT32 sock_fd;
    INT32 domain;
    INT32 type;
    INT32 protocol;
    union
    {
        struct sockaddr addr;
        struct sockaddr_in addr_v4;
        struct sockaddr_in6 addr_v6;
    }u;
}CHAT_SOCK;

    

static inline INT32  chat_sock_init(CHAT_SOCK *pstSock)
{
    struct sockaddr *pstaddr;
    /*support ipv4,   ipv6 to be continued*/
    if(!pstSock)
    {
        LOG(LOG_ERROR,"sock null!");
        return FALSE;
    }
    if(pstSock->sock_fd > 0 )
    {   
        LOG(LOG_ERROR,"sock has open!");
        goto errorout;
    }
    if(0 >= (pstSock->sock_fd = socket(pstSock->domain,pstSock->type,pstSock->protocol)))
    {
        LOG(LOG_ERROR,"sock create error:%s ",strerror(errno));
        goto errorout;
    }
    
    pstaddr = (struct sockaddr *)&pstSock->u.addr_v4;
    if( 0 > (bind(pstSock->sock_fd,pstaddr,sizeof(struct sockaddr_in))))
    {
        LOG(LOG_ERROR,"sock bind error!");
        goto errorout;
    }
    return TRUE;
errorout:
    close(pstSock->sock_fd);
    pstSock->sock_fd = -1;
    return FALSE;
}

static inline INT32  chat_sock_recv(CHAT_SOCK *pstSock)
{
    return TRUE;
}

static inline INT32  chat_sock_send(CHAT_SOCK *pstSock)
{
    return TRUE;
}

static inline INT32  chat_sock_close(INT32 sock_fd)
{
    if(sock_fd > 0)
    {
        close(sock_fd);
    }
    return TRUE;
}






