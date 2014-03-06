#include "chat_public.h"




/*simple list*/
typedef struct Node
{
    struct Node *next;
    struct Node *prev;
    int data;
}NODE;



NODE *sLinklistInitHead(void)
{
    NODE *pHead = NULL;

    pHead = (NODE *)malloc(sizeof(NODE));
    if(!pHead)
    {
        return NULL;
    }

    pHead->next= NULL;
    pHead->prev= NULL;
    pHead->data = 0;
    
    return pHead;
}

void sLinklistInsert(NODE *pNode,NODE *pNewNode)
{
    pNewNode->next = pNode->next;
    pNode->next = pNewNode;
}



void sLinklistAddTail(NODE *pHead,NODE *pNode)
{
    
}


void sLinklistAddBrefore(NODE *pHead,NODE *pNode)
{
    
    pNode->next = pHead;
    pHead = pNode;
}


void sLinklistDelete(NODE *pHead,NODE *pNode)
{
    NODE *pCurNode;
    pCurNode = pHead;
    while(pCurNode)
    {
        
        if(pNode == pCurNode->next)
        {
            pCurNode->next = pNode->next;
            free(pNode);
            return;
        }
        pCurNode = pCurNode->next;
    }
   
}




NODE *gpHead = NULL;


void print_num(void)
{
    NODE *pNode;
    int i = 0;

    pNode = gpHead;
    while(pNode)
    {
        printf("index is %d num  is %d \n",i,pNode->data);
        pNode = pNode->next;
        i++;
    }
    printf("finish print num!\n");
}

NODE *num_sort(int v)
{
    NODE *pNode;

    pNode = gpHead;
    while(pNode)
    {
        printf("num is %d v %d \n",pNode->data,v);
        if(v < pNode->data)
        {
            return pNode;
        }
        pNode = pNode->next;
    }
    return NULL;
}


void add_num(int v)
{
    NODE *pNode = NULL;
    NODE *pNewNode;

    
    
    if(!gpHead)
    {
        gpHead = sLinklistInitHead();
        if(!gpHead)
        {
            return ;
        }
        gpHead->data = v;
        return;
    }
    pNewNode = malloc(sizeof(NODE));
    if(!pNewNode)
    {
        return;
    }
    pNewNode->data = v;
    
    
    pNode = num_sort(v);
    if(pNode == gpHead)
    {
        HERE;
        sLinklistAddBrefore(pNode,pNewNode);
    }
    else
    {
        HERE;
        sLinklistInsert(pNode,pNewNode);
    }
    
  
    return;
}

/*将用户输入的书按顺序存储*/
void testlist_main(void)
{
    int v = 0;
    printf("inut your num :\n");
    scanf("%d",&v);
    while(1)
    {
        sleep(1);
        
        add_num(v);
        print_num();
        printf("inut your num :\n");
        scanf("%d",&v);
    }

}



