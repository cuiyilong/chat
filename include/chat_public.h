#ifndef __CHAT_PUBLIC_H__
#define __CHAT_PUBLIC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>/*ÍøÂçÌ×½Ó×Ö*/
#include <sys/select.h>/*for  interface select()*/
#include <netinet/in.h>

//#include <linux/in6.h>

#include <arpa/inet.h>/*for byteorder*/


#include "chat_types.h"



#define FD_MAX 10

#define SOCKET_MAX 10


#define CHAT_CONTROL_PORT 5678

/*print level*/
#define LOG_OFF 0
#define LOG_INFO 1
#define LOG_ERROR 2
#define LOG_DETAIL 3

extern UINT32 gcurrentprintlevel;

#define LOG(level,fmt,arg...) do{\
    if(level >= gcurrentprintlevel ) {\
        printf("File %s Fun%s Line %d"fmt"\n",__FILE__,__FUNCTION__,__LINE__,##arg);}\
}while(0)



#ifndef MAC_FMT
#define MAC_FMT "%02X:%02X:%02X:%02X:%02X:%02X"
#define MAC_ARG(x) ((UINT8*)(x))[0], ((UINT8*)(x))[1], ((UINT8*)(x))[2], \
         ((UINT8*)(x))[3], ((UINT8*)(x))[4], ((UINT8*)(x))[5]
#endif
    
#ifndef IP_FMT
#define IP_FMT	"%u.%u.%u.%u"
#define IP_ARG(x) ((UINT8*)(x))[0], ((UINT8*)(x))[1], ((UINT8*)(x))[2], ((UINT8*)(x))[3]
#endif
    
#ifndef IPV6_FMT
#define IPV6_FMT "%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x"
#define IPV6_ARG(x) ((u8*)(x))[0], ((u8*)(x))[1], ((u8*)(x))[2], ((u8*)(x))[3], \
                ((u8*)(x))[4], ((u8*)(x))[5], ((u8*)(x))[6], ((u8*)(x))[7], \
                ((u8*)(x))[8], ((u8*)(x))[9], ((u8*)(x))[10], ((u8*)(x))[11], \
                ((u8*)(x))[12], ((u8*)(x))[13], ((u8*)(x))[14], ((u8*)(x))[15]

#endif


#endif
