typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100;
#define INFINITY 65535;

typedef struct
{
    VertexType vex[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numNodesm numEdges;
}MGraph;


//建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph* G)
{
    printf("输入顶点数和边数:\n");
    scanf("%d,%d", &G->numNodes, &G->numEdges);
    for(int i=0;i<G->numNodes;i++) scanf(&G->vexs[i]);
    for(int i=0;i<G->numNodes;i++)
        for(int j=0;i<numNodes;j++)
            G->arc[i][j]=INFINITY;

    for(int i=0;i<G->numEdges;i++)
    {
        printf("输入边(vi,vj)上的下标i，下标j和权w:\n");
        scanf("%d,%d,%d", &i,&j,&w);
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];
    }
}

