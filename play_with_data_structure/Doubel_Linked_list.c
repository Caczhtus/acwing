//线性表的双向链表存储结构
typedef struct DulNode
{
    ElemType data;
    struct DulNode* prior;
    struct DulNode* next;
}DulNode, *DuLinkList;


p->next->prior==p==p->prior->next;

//双向链表的插入
s->prior=p;
s->next=p->next;
p->next->prior=s;
p->next=s;


//双向链表的删除
p->prior->next=p->next;
p->next->prior=p->prior;
free(p);
