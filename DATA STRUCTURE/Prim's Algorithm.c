#include<stdio.h>
#define MAX 20
#define TEMP 0
#define PERM 1
#define FALSE 0
#define TRUE 1
#define infinity 9999
struct node
{
    int predecessor;
    int dist;
    int status;
};
struct edge
{
    int u;
    int v;
};
int adj[MAX][MAX];
int n;
int main()
{
    int i,j;
    int wt_tree,count;
    int path[MAX];
    struct edge tree[MAX];
    create_graph();
    printf("Adjacency Matrix is:\n");
    display();
    count=maketree(tree,&wt_tree);
    printf("Weight of Spanning Tree is:%d\n",wt_tree);
    printf("Edges to be included in Spanning Tree are:\n");
    for(i=1;i<=count;i++)
    {
        printf("%d\t",tree[i].u);
        printf("%d\n",tree[i].v);
    }
}
create_graph()
{
    int i,max_edges,origin,destin,wt;
    printf("Enter No of Nodes:");
    scanf("%d",&n);
    max_edges=n*(n-1)/2;
    for(i=1;i<=max_edges;i++)
    {
        printf("Enter Edge %d(0 0 to quit):",i);
        scanf("%d %d",&origin,&destin);
        if((origin==0)&&(destin==0))
            break;
        printf("Enter Weight for this Edge:");
        scanf("%d",&wt);
        if(origin>n||destin>n||origin<=0||destin<=0)
        {
            printf("Invalid Edge!\n");
            i--;
        }
        else
        {
            adj[origin][destin]=wt;
            adj[destin][origin]=wt;
        }
    }
    if(i<n-1)
    {
        printf("Spanning Tree is not Possible\n");
        exit(1);
    }
}
display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%4d",adj[i][j]);
        printf("\n");
    }
}
int maketree(struct edge tree[MAX],int *weight)
{
    struct node state[MAX];
    int i,k,min,count,current,newdist;
    int m;
    int u1,v1;
    *weight=0;
    for(i=1;i<=n;i++)
    {
        state[i].predecessor=0;
        state[i].dist=infinity;
        state[i].status=TEMP;
    }
    state[1].predecessor=0;
    state[1].dist=0;
    state[1].status=PERM;
    current=1;
    count=0;
    while(all_perm(state)!=TRUE)
    {
        for(i=1;i<=n;i++)
        {
            if(adj[current][i]>0 && state[i].status==TEMP)
            {
                if(adj[current][i]<state[i].dist)
                {
                    state[i].predecessor=current;
                    state[i].dist=adj[current][i];
                }
            }
        }
        min=infinity;
        for(i=1;i<=n;i++)
        {
            if(state[i].status==TEMP && state[i].dist<min)
            {
                min=state[i].dist;
                current=i;
            }
        }
        state[current].status=PERM;
        u1=state[current].predecessor;
        v1=current;
        count++;
        tree[count].u=u1;
        tree[count].v=v1;
        *weight=*weight+adj[u1][v1];
    }
    return(count);
}
int all_perm(struct node state[MAX])
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(state[i].status==TEMP)
            return FALSE;
    }
    return TRUE;
}
