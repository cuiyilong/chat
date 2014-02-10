#ifndef __CHAT_MSG_H__
#define __CHAT_MSG_H__
/*for ipc : mgs-queue interface*/

#define MSG_LEN 1024
#define NAME_LEN 256

typedef struct __msg
{
    INT32 type;
    INT32 len;
    INT8 name[NAME_LEN];
    INT8 value[MSG_LEN];
}MSG;


#endif
