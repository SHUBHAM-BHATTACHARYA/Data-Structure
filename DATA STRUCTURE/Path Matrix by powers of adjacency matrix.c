#include<stdio.h>
#define MAX 20
int n;
int main()
{
    int w_adj[MAX][MAX],adj[MAX][MAX],adjp[MAX][MAX];
    int x[MAX][MAX],path[20][20],i,j,p;
    printf("Input number of Vertices:");
    scanf("%d",&n);
    printf("Enter the Weighted adjacency Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&w_adj[i][j]);
    printf("The Weighted adjacency Matrix is:\n");
    display(w_adj);
    to_boolean(w_adj,adj);
    printf("The Boolean Adjacency Matrix is:\n");
    display(adj);
    while(1)
    {
        printf("Enter the Path length to be Searched(o to quit):");
        scanf("%d",&p);
        if(p==0)
            break;
        pow_matrix(adj,p,adjp);
        printf("The Path Matrix for Length equal to %d is:\n",p);
        display(adjp);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          x[i][j]=0;
    for(p=1;p<=n;p++)
    {
        pow_matrix(adj,p,adjp);
        for(i=0;i<n;i++)
           for(j=0;j<n;j++)
              x[i][j]=x[i][j]+adjp[i][j];
    }
    printf("The Matrix is:\n");
    display(x);
    to_boolean(x,path);
    printf("The Path Matrix is:\n");
    display(path);
}
pow_matrix(int adj[MAX][MAX],int p,int adjp[MAX][MAX])
{
    int i,j,k,tmp[MAX][MAX];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adjp[i][j]=adj[i][j];
     for(k=1;k<p;k++)
     {
         multiply(adjp,adj,tmp);
         for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            adjp[i][j]=tmp[i][j];
     }
}
multiply(int mat1[MAX][MAX],int mat2[MAX][MAX],int mat3[MAX][MAX])
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            mat3[i][j]=0;
            for(k=0;k<n;k++)
                mat3[i][j]=mat3[i][j]+mat1[i][k]*mat2[k][j];
        }
}
to_boolean(int mat[MAX][MAX],int boolmat[MAX][MAX])
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(mat[i][j]==0)
               boolmat[i][j]=0;
            else
                boolmat[i][j]=1;
        }
}
display(int matrix[MAX][MAX])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%4d",matrix[i][j]);
        printf("\n");
    }
}
