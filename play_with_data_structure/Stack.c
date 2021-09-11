#define MAXSIZE 100
typedef int SElemType
typedef struct
{
    SElemType data[MAXSIZE];
    int top;
}SqStack;


//插入元素e为新的栈顶元素
Status Push(SqStack* S, SElemType e)
{
    if(S->top==MAXSIZE-1) return ERROR;
    S->top++;
    S->data[S->top]=e;
    return OK;
}

//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
Status pop(SqStack* S, SElemType* e)
{
    if(S->top==-1) return ERROR;
    *e=S->data[S->top];
    S->top--;
    return OK;
}