typedef struct StackNode
{
    SELemType data;
    struct StackNode* next;
}StackNode, *LinkStackPtr;


typedef struct
{
    LinkStackPtr top;
    int count;
}LinkStack;



Status Push(LinkStack* S, SELemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof StackNode);
    s->data=e;
    s->next=S->top;
    S->top=s;
    S->count++;
    return OK;
}

Status Pop(LinkStack* S, SELemType* e)
{
    if(StackEmpty(*S)) return ERROR;
    *e=S->top->data;
    LinkStackPtr p=S->top;
    S->top=S->top->next;
    free(p);
    S->count--;
    return OK;
}