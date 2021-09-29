//二叉树的二叉链表的结点结构定义
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


#define Status int

Status SearchBST(BiTree T, int key, BiTree f, BiTree p)
{
    
}