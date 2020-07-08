#include<stdio.h>
#define MAX 20
int main()
{
    int a[MAX],i,j,tmp,n,k;
    printf("Enter the No of element:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&a[i]);
    }
    printf("Unsorted list is :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
    for(i=0;i<n-1;i++)
    {
        k=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                k++;
            }
        }
        if(k==0)
            break;
        printf("after Pass %d elements are:\n",i+1);
        for(k=0;k<n;k++)
            printf("%d\t",a[k]);
        printf("\n");
    }
        printf("Sorted list is:\n");
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);
        printf("\n");
}
