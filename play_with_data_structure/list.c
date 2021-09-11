

//线性表定义
#define MAXSIZE 20
typedef int ElemTpye;
typedef struct
{
    ElemTpye data[MAXSIZE];
    int length;
}SqList;


#define OK 1
#define ERROR 0
typedef int Status;


//获取元素操作
Status GetElem(SqList L, int i, ElemTpye* e)
{
    if(L.length==0||i<1||i>L.length)
        return ERROR;
    *e=L.data[i-1];
    return OK;
}



//插入操作
Status ListInsert(SqList* L, int i, ElemType e)
{
    if(L->length==MAXSIZE || i<1 || i>L->length+1)
        return ERROR;
    if(i<=L->length)
    {
        for(int j=L->length-1;j>=i-1;j--)
            L->data[j+1]=L->data[j];
    }
    L->data[i-1]=e;
    L->length++;
    return OK;
}

//删除操作
Status ListDelete(SqList* L, int i, ElemType* e)
{
    if(L->length==0 || i<1 || i>L->length) return ERROR;
    *e=L->data[i-1];
    if(i<L->length)
    {
        for(int j=i-1;j<L->length-1;j++)
            L->data[j]=L->data[j+1];
    }
    L->length--;
    return OK;
}


//线性表的单链表存储结构
typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node;

typedef struct Node* LinkList;

//单链表的查询
//初始条件：链式线性表L已经存在，1<= i <= ListLength(L)
//操作结果：用e返回L中的第i个元素

Status GetElem(LinkList L, int i, ElemType* e)
{
    //L为头指针
    //p=L为头指针
    while(i--)
    {
        L=L->next;
        if(!L) return ERROR;
    }
    *e=L->data;
    return OK;
}

//单链表的插入
//初始条件：链表L已经存在，1<= i <=ListLength(L);
//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListInsert(LinkList L, int i, ElemType e)
{
    LinkList s=(LinkList)malloc(sizeof Node);
    while((i-1)--)
    {
        L=L->next;
        if(!L) return ERROR;
    }
    s->data=e;
    s->next=L->next;
    L->next=s;
    return OK;
}

//单链表的删除
//初始条件：链表L已经存在，1<= i <=ListLength(L);
//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1；
Status ListDelete(LinkList L, int i, ElemType* e)
{
    while(i--)
    {
        L=L->next;
        if(!L) return ERROR;
    }
    *e=L->data;
    LinkList q=L;
    L=L->next;
    free(q);
    return OK;
}


srand(time(0));
//单链表的整表创建
//随机长生n个元素的值，建立带表头的单链表（头插法）
LinkList L=(Linklist)malloc(sizeof Node);
L->next=NULL;
L->data=0;
void CreateListHead(LinkList L, int n)
{
    while(n--)
    {
        LinkList p=(Linklist)malloc(sizeof Node);
        p->data=rand()%100+1;
        p->next=L->next;
        L->next=p;
    }
}


//随机长生n个元素的值，建立带表头的单链表（尾插法）
void CreateListTail(LinkList L, int n)
{
    LinkList r=L;
    while(n--)
    {
        LinkList p=(Linklist)malloc(sizeof Node);
        p->data=rand()%100+1;
        p->next=NULL;
        r->next=p;
        r=p;
    }
}

//链表的整表删除
//初始条件：链表L已经存在；操作结果：将L重制为空表；

Status ClearList(LinkList L)
{
    LinkList p=L->next,q;
    while(p)
    {
        q=p->next;
        free(q);
        p=q;
    }
    L->next=NULL;
    return OK;
}