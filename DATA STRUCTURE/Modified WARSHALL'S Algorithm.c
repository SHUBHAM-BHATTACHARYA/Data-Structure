#include<stdio.h>
#define infinity 9999
#define max 20
int main()
{
    int i,j,k,n;
    int adj[max][max],path[max][max];
    printf("Enter number of Vertices:");
    scanf("%d",&n);
    printf("Enter Weighted Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
        printf("The Weighted Matrix is :\n");
        display(adj,n);
        for(i=0;i<n;i++)
             for(j=0;j<n;j++)
             {
                  if(adj[i][j]==0)
                       path[i][j]=infinity;
                  else
                      path[i][j]=adj[i][j];
            }
        for(k=0;k<n;k++)
        {
            printf("Q%d is:\n",k);
            display(path,n);
            for(i=0;i<n;i++)
                 for(j=0;j<n;j++)
                    path[i][j]=minimum(path[i][j],path[i][k]+path[k][j]);
        }
        printf("Shortest Path Matrix Q%d of the given Graph is :\n",k);
        display(path,n);
}
minimum(int a,int b)
{
    if(a<=b)
        return a;
    else
        return b;
}
display(int matrix[max][max],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%7d",matrix[i][j]);
        printf("\n");
    }
}


