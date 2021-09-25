#define MAXVEX 100
#define INFINITY 65535



//Prim算法生成最小生成树
void MiniSpanTree_Prim(MGraph G)
{
    int adjvex[MAXVEX];//保存相关顶点间边的权值点下标
    int lowcost[MAXVEX];//保存相关顶点间边的权值
    adjvex[0]=0;//初始化第一个顶点下标为0
    lowcost[0]=0;//初始化第一个权值为0，即v0加入生成树，之后凡是lowcost数组中的值被设置为0就表示此下标的顶点被纳入最小生成树
    for(int i=1;i<G.numVertexes;i++) lowcost[i]=G.arc[0][i], adjvex[i]=0;
    for(int i=1;i<G.numVertexes;i++)
    {
        int min=INFINITY;//为了找到一定范围内的最小权值
        for(int j=1;j<G.numVertexes;j++) if(lowcost[j]!=0 && lowcost[j]<min) min=lowcost[j], int k=j;
        printf("(%d,%d)\n", adjvex[k], k);//打印当前顶点边中权值最小的边；
        lowcost[k]=0;//k点加入最小生成树；
        //更新lowcost数组
        for(int j=1;j<G.numVertexes;j++) if(lowcost[j]!=0 && G.arc[k][j]<lowcost[j]) lowcost[j]=G.arc[k][j], adjvex[j]=k;
    }
}