#include<stdio.h>
#define max 20
int adj[max][max];
int n;
int main()
{
    int choice;
    int node,origin,destin;
    printf("..............OPERATION ON DIRECTED GRAPH................\n WHERE NODES ARE TREATED AS NUMBER AND WAIT AS 1\n");
    create_graph();
    printf("1.Insert a node\n");
    printf("2.Insert an edge\n");
    printf("3.Delete a node\n");
    printf("4.Delete an edge\n");
    printf("5.Display\n");
    printf("6.Exit\n");
    do
    {
        printf("Enter your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert_node();
            break;
        case 2:
            printf("Enter an edge to be Inserted:");
            scanf("%d %d",&origin,&destin);
            insert_edge(origin,destin);
            break;
        case 3:
            printf("Enter a node to be Deleted:");
            scanf("%d",&node);
            delete_node(node);
            break;
        case 4:
            printf("Enter an edge to be deleted:");
            scanf("%d %d",&origin,&destin);
            del_edge(origin,destin);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("EXIT");
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    }
    while(choice!=6);
}
create_graph()
{
    int i,max_edges,origin,destin;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    max_edges=n*(n-1);
    for(i=1;i<=max_edges;i++)
    {
        printf("Enter edge %d(0 0)t quit:",i);
        scanf("%d %d",&origin,&destin);
        if((origin==0)&&(destin==0))
            break;
        if(origin>n||destin>n||origin<=0||destin<=0)
        {
            printf("Invalid Edge!\n");
            i--;
        }
        else
            adj[origin][destin]=1;
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
insert_node()
{
    int i;
    n++;
    printf("The inserted node is %d\n",n);
    for(i=1;i<=n;i++)
    {
        adj[i][n]=0;
        adj[n][i]=0;
    }
}
delete_node(u)
{
    int i,j;
    if(n==0)
    {
        printf("Graph is Empty\n");
        return;
    }
    if(u>n)
    {
        printf("This node is not present in the graph\n");
        return;
    }
    for(i=u;i<=n-1;i++)
        for(j=1;j<=n;j++)
    {
        adj[j][i]=adj[j][i+1];
        adj[i][j]=adj[i+1][j];
    }
    n--;
}
insert_edge(u,v)
{
    if(u>n)
    {
        printf("Source node does not exists\n");
        return;
    }
    if(v>n)
    {
        printf("Destination node does not exist\n");
        return;
    }
    adj[u][v]=1;
}
del_edge(u,v)
{
    if(u>n||v>n||adj[u][v]==0)
    {
        printf("This Edge does not Exist\n");
        return;
    }
    adj[u][v]=0;
}
