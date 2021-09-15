//树的双亲表示法节点结构定义
#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct PTNode
{
    TElemType data;
    int parent;
}PTNode;

typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int r,n;//根的位置和节点数
}PTree;

//由于跟节点没有双亲，我们约定根节点的位置域设为-1

//树的孩子表示法定义
//孩子节点
typedef struct CTNode
{
    int child;
    struct CTNode* next;
}*ChildPtr;


//表头结构
typedef struct
{
    TElemType data;
    ChildPtr firstchild;
}CTBox;

//树结构
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int r,n;//根节点的位置和节点数
}CTree;

//还有双亲孩子表示法



//孩子兄弟表示法
typedef struct CSNode
{
    TElemType data;
    struct CSNode* firstchild;
    struct CSNode* rightsib;
}CSNode, *CSTree;



