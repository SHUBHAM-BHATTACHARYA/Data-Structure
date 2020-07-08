#include<stdio.h>
int main()
{
    int a[10][10],b[10][10],i,j,r,c,count=0,k=1,temp;
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
        temp=b[i][0];
        b[i][0]=b[i][1];
        b[i][1]=temp;
    }
    printf("Transpose Sparse Matrix is:\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}

