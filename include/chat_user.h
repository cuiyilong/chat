#ifndef __CHAT_USER_H__
#define __CHAT_USER_H__

#define PASSWD_LEN 16


typedef struct __chat_user{
    INT32 userglobalid;
    INT8 username[NAME_LEN];
    INT8 userpasswd[PASSWD_LEN];
    INT32 userstate;

}chat_user;






#endif
