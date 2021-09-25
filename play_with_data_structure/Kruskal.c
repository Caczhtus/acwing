//对面集数组Edge结构的定义
typedef struct
{
    int beginl
    int endl
    int weight;
}Edge;



void MiniSpanTree_Kruskal(MGraph G)
{
    Edge edges[MAXEDGE];
    int parent[MAXVEX];//定义一数组用来判断边与边之间是否形成环路
    //省略将邻街矩阵G转化为边集数组edges并按权由小到大排列的代码
    for(int i=0;i<G.numVertexes;i++) parent[i]=0;
    for(int i=0;i<G.numEdgees;i++)
    {
        int n=Find(parrent, edges[i].begin);
        int m=Find(parrent, edges[i.end]);
        if(n!=m)
        {
            parent[n]=m;
            printf("(%d,%d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}

//查找连线顶点的尾部下标
int Find(int* parent, int f)
{
    while(parent[f]>0) f=parent[f];
    return f;
}