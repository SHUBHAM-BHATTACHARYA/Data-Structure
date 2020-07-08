#include<stdio.h>
#define max 20
int adj[max][max],tree[max][max],n;
int main()
{
    int source,treecost;
    readmatrix();
    printf("\n Enter The Source:");
    scanf("%d",&source);
    treecost=spanningtree(source);
    display(treecost);
    return 0;
}
void readmatrix()
{
    int i,j;
    printf("\n Enter the Number of Nodes in the Graph:");
    scanf("%d",&n);
    printf("\n Enter the Adjacency matrix of the Graph\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
               scanf("%d",&adj[i][j]);
}
int spanningtree(int src)
{
    int visited[max],d[max],parent[max];
    int i,j,k,min,u,v,cost;
    for(i=1;i<=n;i++)
    {
        d[i]=adj[src][i];
        visited [i]=0;
        parent[i]=src;
    }
    visited[src]=1;
    cost=0;
    k=1;
    for(i=1;i<n;i++)
    {
        min=9999;
        for(j=1;j<=n;j++)
        {
            if(visited[j]==0 && d[j]<min)
            {
                min=d[j];
                u=j;
            }
        }
        visited[u]=1;
        cost=cost+d[u];
        tree[k][1]=parent[u];
        tree[k++][2]=u;
        for(v=1;v<=n;v++)
            if(visited[v]==0 && (adj[u][v]<d[v]))
        {
            d[v]=adj[u][v];
            parent[v]=u;
        }
    }
    return(cost);
}
void display(int cost)
{
    int i;
    printf("\n The Edges of the Minimum Spanning Tree are\n");
    for(i=1;i<n;i++)
        printf("%d  %d\n",tree[i][1],tree[i][2]);
    printf("\n Total cost of the Minimum Spanning Tree is:%d",cost);
}

