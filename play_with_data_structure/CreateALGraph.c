typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
    int adjvex;
    EdgeType info;
    struct EdgeNode* next;
}EdgeNode;


typedef struct VertexNode
{
    VertexType data;
    EdgeNode* firstedge;
}VertexNode, AdjList[MAXVEX];


typedef struct
{
    AdjList adjList;
    int numNodes, numEdges;
}GraphAdjList;

void CreateALGraph(GraphAdjList* G)
{
    EdgeNode* e;
    printf("输入顶点数和边数:\n");
    scanf("%d, %d", &G->numNodes, &G->numEdges);
    for(int i=0;i<G->numNodes;i++)
    {
        scanf(&G->adjList[i].data);
        G->adjList[i].firstedge=NULL;
    }
    for(int k=0;k<G->numEdges;k++)
    {
        printf("输入边(vi,vj)上的顶点序号");
        scanf("%d,%d", &i, &j);
        e=(EdgeNode*)malloc(sizeof EdgeNode);
        e->adjvex=j;
        e->next=G->adjList[i].firstedge;
        G->adjList[i].firstedge=e;
        e=(EdgeNode*)malloc(sizeof EdgeNode);
        e->adjvex=i;
        e->next=G->next[j].firstedge;
        G->adjList[j].firstedge=e
    }
}