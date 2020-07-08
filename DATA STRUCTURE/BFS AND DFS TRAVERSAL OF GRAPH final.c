#include<stdio.h>
#define MAX 20
int create_graph();
int display();
int dfs_rec(int);
int dfs(int);
int bfs(int);
int adj_nodes(int);
int components();
typedef enum boolean{FALSE,TRUE}boolean;
int adj[MAX][MAX];
bool visited[MAX];
int n;
int main()
{
    int i,v,choice;
    create_graph();
    printf("1.Adjacency Matrix\n");
    printf("2.Depth First Search using Stack\n");
    printf("3.Depth First Search through Recursion\n");
    printf("4.Breadth First Search\n");
    printf("5.Adjacent Vertices\n");
    printf("6.Components\n");
    printf("7.EXIT\n");
    do
    {
        printf("\nEnter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Adjacency Matrix\n");
            display();
            break;
        case 2:
            printf("Enter Starting Node For Depth First Search:");
            scanf("%d",&v);
            for(i=1;i<=n;i++)
                visited[i]=FALSE;
            dfs(v);
            break;
        case 3:
            printf("Enter Starting Node For Depth First Search:");
            scanf("%d",&v);
            for(i=1;i<=n;i++)
                visited[i]=FALSE;
            dfs_rec(v);
            break;
        case 4:
            printf("Enter Starting Node For Breadth First Search:");
            scanf("%d",&v);
            for(i=1;i<=n;i++)
                visited[i]=FALSE;
            bfs(v);
            break;
        case 5:
            printf("Enter Node to Find Adjacent Vertices:");
            scanf("%d",&v);
            printf("Adjacent Vertices are:");
            adj_nodes(v);
            break;
        case 6:
            components();
            break;
        case 7:
            printf("EXIT\n");
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    }
    while(choice!=7);
}
create_graph()
{
    int i,max_edges,origin,destin;
    printf("Enter No of Nodes:");
    scanf("%d",&n);
    max_edges=n*(n-1);
    for(i=1;i<=max_edges;i++)
    {
        printf("Enter Edge %d(0 0 to quit):",i);
        scanf("%d %d",&origin,&destin);
        if((origin==0)&&(destin==0))
            break;
        if(origin>n||destin>n||origin<=0||destin<=0)
        {
            printf("Invalid Edge!\n");
            i--;
        }
        else
        {
            adj[origin][destin]=1;
        }
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
dfs_rec(int v)
{
    int i;
    visited[v]=TRUE;
    printf("%d ",v);
    for(i=1;i<=n;i++)
        if(adj[v][i]==1 && visited[i]==FALSE)
                 dfs_rec(i);
}
dfs(int v)
{
    int i,stack[MAX],top=-1,pop_v,j,t;
    int ch;
    top++;
    stack[top]=v;
    while(top>=0)
    {
        pop_v=stack[top];
        top--;
        if(visited[pop_v]==FALSE)
        {
            printf("%d ",pop_v);
            visited[pop_v]=TRUE;
        }
        else
            continue;
        for(i=n;i>=1;i--)
        {
            if(adj[pop_v][i]==1 && visited[i]==FALSE)
            {
                top++;
                stack[top]=i;
            }
        }
    }
}
bfs(int v)
{
    int i,front,rear;
    int queue[20];
    front=rear=-1;
    printf("%d ",v);
    visited[v]=TRUE;
    rear++;
    front++;
    queue[rear]=v;
    while(front<=rear)
    {
        v=queue[front];
        front++;
        for(i=1;i<=n;i++)
        {
            if(adj[v][i]==1 && visited[i]==FALSE)
            {
                printf("%d ",i);
                visited[i]=TRUE;
                rear++;
                queue[rear]=i;
            }
        }
    }
}
adj_nodes(int v)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(adj[v][i]==1)
             printf("%d\t",i);
    }
    printf("\n");
}
components()
{
    int i;
    for(i=1;i<=n;i++)
        visited[i]=FALSE;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==FALSE)
            dfs_rec(i);
    }
    printf("\n");
}
