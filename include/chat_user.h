#ifndef __CHAT_USER_H__
#define __CHAT_USER_H__

#define PASSWD_LEN 16


typedef struct __user_base_info{

    INT8 username[NAME_LEN];
    INT8 userpasswd[PASSWD_LEN];
    INT32 userstate;

}user_base_info;






#endif
