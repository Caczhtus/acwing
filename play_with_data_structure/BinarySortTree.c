//二叉树的二叉链表的结点结构定义
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


#define Status int
#define FALSE -1;
#define TRUE 0;

Status SearchBST(BiTree T, int key, BiTree f, BiTree p)
{//递归查找二叉排序树T中是否存在key
    if(!T) //若查找不成功，指针p指向查找路径上访问的最后一个结点并返回FALSE
    {
        p=f;
        return FALSE;
    }
    else if(key==T->data)
    {
        p=T;
        return TRUE;
    }
    else if(key<T->data)
        return SearchBST(T->lchild, key, T, p);
    else
        return SearchBST(T->rchild, key, T, p);
}


Status InsertBST(BiTree T, int key)
{
    BiTree p,s;
    if(!SearchBST(T, key, NULL, p))
    {
        s=(BiTree)malloc(sizeof(BiTNode));
        s->data=key;
        s->lchild=s->rchild=NULL;
        if(!p) T=s;
        else if(key<p->data) p->lchild=s;
        else p->rchild=s;
        return TRUE;
    }
    else
        return FALSE;
}



Status DeleteBST(BiTree T, int key)
{
    if(!T) return FALSE;
    else
    {
        if(key==T->data) return Delete(T);
        else if(key<T->data) return DeleteBST(T->lchild, key);
        else return DeleteBST(T->rchild, key);
    }
}

Status Delete(BiTree p)
{//从BST当中删除结点p，并且重接它的左或右子树
    BiTree q,s;
    if(p->rchild==NULL)
    {
        q=p;
        p=p->lchild;
        free(q);
    }
    else if(p->lchild==NULL)
    {
        q=p;
        p=p->rchild;
        free(p);
    }
    else
    {
        q=p;
        s=p->lchild;
        while(s->rchild)
        {
            q=s;
            s=s->rchild;
        }
        p->data=s->data;
        if(q!=p) q->rchild=s->lchild;
        else q->lchild=s->rchild;
        free(s);
    }
    return TRUE;
}