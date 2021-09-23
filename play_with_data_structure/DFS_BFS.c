#define MAXVEX 9
Boolean visited[MAXVEX];

//邻接矩阵的深度优先递归算法
void DFS(MGraph G, int i)
{
    visited[i]=TRUE;
    printf("%c", G.vexs[i]);
    for(int j=0;j<G.numVertexes;j++)
        if(G.arc[i][j]==1 && !visited[j])
            DFS(G, j);
}


//邻接矩阵的深度遍历操作
void DFSTraverse(MGraph G)
{
    for(int i=0;i<G.numVertexes;i++) visited[i]=FALSE;
    for(int i=0;i<G.numVertexes;i++)
    {
        if(!visited[i])
            DFS(G, i);
    }
}


//邻接表的深度优先递归算法
void DFS(GraphAdjList GL, int i)
{
    EdgeNode* p;
    visited[i]=TRUE;
    printf("%c", GL->adjList[i].data);
    p=GL->adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
            DFS(GL, p->adjvex);
        p=p->next;
    }
}


//邻接表的深度遍历操作
void DFSTraverse(GraphAdjList GL)
{
    for(int i=0;i<GL->numVertexes;i++)
        visited[i]=FALSE;
    for(int i=0;i<GL->numVertexes;i++)
        if(!visited[i])
            DFS(GL, i);
}


//邻接矩阵的广度遍历算法
void BFSTraverse(MGraph G)
{
    Queue Q;
    for(int i=0;i<G.numVertexes;i++) visited[i]=FALSE;
    InitQueue(&Q);
    for(int i=0;i<G.numVertexes;i++)
    {
        if(!visited[i])
        {
            visited[i]=TRUE;
            printf("%c", G.vexs[i]);
            EnQueue(&Q, i);
            while(!QueueEmpty(Q))
            {
                DeQueue(&Q, &i);
                for(int j=0;j<G.numVertexes;j++)
                {
                    if(G.arc[i][j]==1 && !visited[j])
                    {
                        visited[j]=TRUE;
                        printf("%c", G.vexs[j]);
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}

//邻接表的广度遍历算法
void BFSTraverse(GraphAdjList GL)
{
    EdgeNode* p;
    Queue Q;
    for(int i=0;i<G.numVertexes;i++) visited[i]=FALSE;
    InitQueue(&Q);
    for(int i=0;i<G.numVertexes;i++)
    {
        if(!visited[i])
        {
            visited[i]=TRUE;
            printf("%c", GL->adjList[i].data);
            EnQueue(&Q, i);
            while(!QueueEmpty(Q))
            {
                DeQueue(&Q,&i);
                p=GL->adjList[i].firstedge;
                while(p)
                {
                    if(!visited[p->adjvex])
                    {
                        visited[p->adjvex]=TRUE;
                        printf("%c ",GL->adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p=p->next;
                }
            }
        }
    }
}