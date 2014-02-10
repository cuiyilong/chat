#ifndef __CHAT_TYPES_H__
#define __CHAT_TYPES_H__

/*------------------------------ 包含文件声明 --------------------------------*/
#include <limits.h>
/*------------------------------ 外部变量引用 --------------------------------*/

/*------------------------------ 常数和类型声明 ------------------------------*/

/************************************************************/
typedef char s8;
typedef unsigned char u8;

typedef short s16;
typedef unsigned short u16;

typedef int s32;
typedef unsigned int u32;

#  if __WORDSIZE == 64
typedef long s64;
typedef unsigned long u64;
#  else
typedef long long s64;
typedef unsigned long long u64;
#  endif
/************************************************************/
typedef char INT8;
typedef char int8;
typedef unsigned char UINT8;
typedef unsigned char uint8;
typedef char CHAR;
typedef char BYTE;

typedef short INT16;
typedef short int16;
typedef unsigned short UINT16;
typedef unsigned short uint16;

typedef int INT32;
typedef int int32;
typedef unsigned int UINT32;
typedef unsigned int uint32;
typedef int WORD32;


typedef UINT16 WORD;
typedef UINT32 DWORD;

#  if __WORDSIZE == 64
typedef long INT64;
typedef long int64;
typedef unsigned long UINT64;
typedef unsigned long uint64;
#  else
typedef long long INT64;
typedef long long int64;
typedef unsigned long long UINT64;
typedef unsigned long long uint64;
#  endif
/************************************************************/
typedef void VOID;

#ifndef bool
typedef enum
{
    false,
    true,
} bool;
#endif

/*
typedef enum
{
    FALSE,
    TRUE,
} BOOL;
*/
#ifndef BOOL
#define BOOL int
#endif

#ifdef TRUE
#undef TRUE
#define TRUE 1
#else
#define TRUE 1
#endif

#ifdef FALSE
#undef FALSE
#define FALSE -1
#else
#define FALSE -1
#endif

/*--------------------------------- 头文件保护 -------------------------------*/
#endif
/*----------------------------------- 文件尾 ---------------------------------*/
