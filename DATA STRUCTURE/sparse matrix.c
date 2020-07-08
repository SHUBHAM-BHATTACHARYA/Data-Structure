#include<stdio.h>
int main()
{
    int a[10][10],b[10][10],i,j,r,c,count=0,k=1;
    printf("Enter the No of Row:");
    scanf("%d",&r);
    printf("Enter the No of Column:");
    scanf("%d",&c);
    printf("Enter the Elements:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]==0)
                count=count+1;
        }
    }
    if(count>(r*c)/2)
        printf("Matrix is a Sparse Matrix\n");
    else
        printf("Matrix is not Sparse Matrix\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    b[0][0]=r;
    b[0][1]=c;
    b[0][2]=k-1;
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}
