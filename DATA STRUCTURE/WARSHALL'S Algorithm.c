#include<stdio.h>
#define max 20
int main()
{
    int i,j,k,n;
    int w_adj[max][max],adj[max][max],path[max][max];
    printf("Enter number of Vertices:");
    scanf("%d",&n);
    printf("Enter Weighted Adjacency Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&w_adj[i][j]);
        printf("The Weighted Adjacency Matrix is :\n");
        display(w_adj,n);
        for(i=0;i<n;i++)
             for(j=0;j<n;j++)
             {
                  if(w_adj[i][j]==0)
                       adj[i][j]=0;
                  else
                      adj[i][j]=1;
            }
        printf("The Adjacency Matrix is:\n");
        display(adj,n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                path[i][j]=adj[i][j];
        for(k=0;k<n;k++)
        {
            printf("P%d is:\n",k);
            display(path,n);
            for(i=0;i<n;i++)
                 for(j=0;j<n;j++)
                    path[i][j]=(path[i][j]||(path[i][k]&&path[k][j]));
        }
        printf("Path Matrix P%d of the given Graph is :\n",k);
        display(path,n);
}
display(int matrix[max][max],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%3d",matrix[i][j]);
        printf("\n");
    }
}

