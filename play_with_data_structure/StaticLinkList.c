#define MAXSIZE 1000
typedef int ElemType
typedef struct
{
    ElemType data;
    int cur;
}Component, StaticLinkList[MAXSIZE];


//静态链表data，cur，以及下标；下标0的节点存的cur是备用链表第一个节点下标；下标MAXSIZE-1的节点存的cur是链表第一个插入元素的下标，链表最后一个
//将一位数组space中各个分量链成一个备用链表，space[0].cur为头指针，"0"表示空指针
Status InitList(StaticLinkList space)
{
    for(int i=0;i<MAXSIZE-1;i++)
        space[i].cur=i+1;
    space[MAXSIZE-1].cur=0;//目前静态链表为空，最后一个元素的cur为0；
    return OK;
}

//静态链表的插入操作
//若备用空间链表非空，则返回分配的节点下标，否则返回0
int Malloc_SSL(StaticLinkList space)
{
    int i=space[0].cur;
    if(i) space[0].cur=space[i].cur;
    return i;
}

//静态链表的插入操作
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
    if(i<1 || i>ListLength(L)+1)
        return ERROR;
    int j=Malloc_SSL(L);
    if(!j) return ERROR;
    L[j].data=e;
    int k=MAXSIZE-1;
    while((i-1)--)
    {
        k=L[k].cur
    }
    L[j].cur=L[k].cur;
    L[k].cur=j;
    return OK;
}


//将下标为k的空闲节点回收到备用链表
void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur=space[0].cur;
    space[0].cur=k;
}


//删除在L中的第i个数据元素
Status ListDelete(StaticLinkList L, int i)
{
    if(i<1 || i>ListLength(L)) return ERROR;
    int k=MAXSIZE-1;
    while((i-1)--) k=L[k].cur;
    int j=L[k].cur;
    L[k].cur=L[j].cur;
    Free_SSL(L, j);
    return OK;
}


int ListLength(StaticLinkList L)
{
    int i=MAXSIZE-1, j=0;
    while(i)
    {
        i=L[i].cur;
        j++;
    }
    return j;
}