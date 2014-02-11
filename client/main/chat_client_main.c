#include "chat_client.h"
UINT32 gcurrentprintlevel=0;

void main(int argc,char *argv[])
{
    if(argc != 2)
    {
        LOG(LOG_ERROR,"please input server ip!");
        return;
    }
    
    if(FALSE == chat_client_comm_init(argv[1]))
    {
        LOG(LOG_ERROR,"sock init fail");
        return;
    }
    if(FALSE ==  chat_client_comm_check_udp())
    {
        LOG(LOG_OFF,"check udp fail !");
        return;
    }

    if(FALSE ==  chat_client_comm_check_tcp())
    {
        LOG(LOG_OFF,"check tcp fail !");
        return;
    }

    return;
}
