#define MAXSIZE 100;
typedef int QElemType;
typedef struct
{
    QElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;


循环队列：
1. 满队列：(rear+1)%MAXSIZE==front
2. 空队列：rear=front
3. 计算队列长度公式：(rear+MAXSIE-front)%MAXSIZE


//初始化一个空队列Q
Status InitQueue(SqQueue* Q)
{
    Q->front=0;
    Q->rear=0;
    return OK;
}

//循环队列求长度
int QueueLength(SqQueue Q)
{
    return (Q.rear+MAXSIZE-Q.front)%MAXSIZE;
}

//循环队列的入队操作
Status EnQueue(SqQueue* Q, QElemType e)
{
    if((Q->rear+1)%MAXSIZE == Q->front) return ERROR;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return OK;
}

//循环队列的出队操作
Status Dequeue(SqQueue* Q, QElemType* e)
{
    if(Q->rear==Q->front) return ERROR;
    *e=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return OK;
}