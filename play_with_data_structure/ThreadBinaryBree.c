//二叉树的二叉线索存储结构定义
typedef char TElemType;
typedef enum {Link, Thread} PointerTag;
typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode, *BiThrTree;


//线索化的过程就是在遍历的过程中修改空指针的过程
//中序遍历线索化的递归函数代码如下

BiThrTree pre;//全局变量，始终指向刚刚访问过的节点
void InThreading(BiThrTree p)//中序遍历进行中序线索化
{
    if(p)
    {
        InThreading(p->lchild);
        if(!p->lchild)
        {
            p->LTag=Thread;
            p->lchild=pre;
        }
        if(!pre->rchild)
        {
            pre->RTag=Thread;
            pre->rchild=p;
        }
        pre=p;
        InThreading(p->rchild);
    }
}

//和二叉链表一样，可以在二叉树线索链表上添加一个头节点
//T指向头节点，头节点左链lchild指向根节点，头节点右链rchild指向中序遍历的最后一个节点。中序遍历二叉线索链表表示的二叉树T

Status InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p=T->lchild;//p指向根节点;
    while(p!=T)//空树或者遍历结束的时候，p==T
    {
        while(p->LTag==Link) p=p->lchild;
        printf("%c", p->data);
        while(p->RTag==Thread && p->rchild!=T)
        {
            p=p->rchild;
            printf("%c", p->data);
        }
        p=p->rchild;
    }
    return OK;
}