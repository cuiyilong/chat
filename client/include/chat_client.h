#ifndef __CHAT_CLIENT_H__
#define __CHAT_CLIENT_H__
#include "chat_public.h"
#include "chat_sock.h"

INT32 chat_client_comm_init(INT8 *addr);
INT32 chat_client_comm_check_udp(void);
INT32 chat_client_comm_check_tcp(void);


#endif
