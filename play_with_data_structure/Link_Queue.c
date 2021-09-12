//链队列的结构

typedef int QElemType;
typedef struct QNode
{
    QElemType data;
    struct Qnode* next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front,rear;
}LinkQueue;


//入队
Status EnQueue(LinkQueue* Q, QElemType e)
{
    QueuePtr s=(QueuePtr)malloc(sizeof QNode);
    if(!s) exit(OVERFLOW);

    s->data=e;
    s->next=NULL;
    Q->rear->next=s;
    Q->rear=s;
    return OK;
}

//出队
Status Dequeue(LinkQueue* Q, QElemType* e)
{
    if(Q->front==Q->rear) return ERROR;
    QueuePtr p=Q->front->next;
    if(Q->rear==p) Q->rear=Q->front;
    *e=p->data;
    Q->front->next=p->next;
    free(p);
    return OK;
}