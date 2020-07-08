#include<stdio.h>
#define max 20
int adj[max][max];
int n;
int main()
{
    int max_edges,i,j,origin,destin;
    char graph_type;
    printf("----------CREATION OF DIRECTED AND UNDIRECTED GRAPH----------\n WHERE THE NODES ARE TREATED AS NUMBER AND WAIT AS 1\n");
    printf("Enter Number of Nodes:");
    scanf("%d",&n);
    printf("Enter type of Graph,Directed or Undirected(d/u):");
    fflush(stdin);
    scanf("%c",&graph_type);
    if(graph_type=='u')
        max_edges=n*(n-1)/2;
    else
        max_edges=n*(n-1);
    for(i=1;i<=max_edges;i++)
    {
        printf("Enter Edge %d( 0 0 to quit):",i);
        scanf("%d\t %d",&origin,&destin);
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
            if(graph_type=='u')
                adj[destin][origin]=1;
        }
    }
    printf("The Adjacency Matrix is:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%4d",adj[i][j]);
        printf("\n");
    }
}
