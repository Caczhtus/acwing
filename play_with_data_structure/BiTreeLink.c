typedef int TELemType;


//二叉树的二叉链表结点结构定义
typedef struct BiTNode
{
    TELemType data;//结点数据
    struct BiTNode *lchild, *rchild;//左右孩子指针
}BiTNode, *BiTree;

//二叉树的前序遍历算法
//初始条件：二叉树T存在
//操作结果：前序递归遍历T
void PreOrderTraverse(BiTree T)
{
    if(T==NULL) return;
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}


//二叉树的中序遍历算法
//初始条件：二叉树T存在
//操作结果：前序递归遍历T
void InOrderTraverse(BiTree T)
{
    if(T==NULL) return;
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

//二叉树的后序遍历算法
//初始条件：二叉树T存在
//操作结果：前序递归遍历T
void PostOrderTraverse(BiTree T)
{
    if(T==NULL) return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}