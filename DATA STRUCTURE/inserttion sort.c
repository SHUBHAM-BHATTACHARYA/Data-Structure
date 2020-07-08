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
    for(j=1;j<n;j++)
    {
        k=a[j];
        for(i=j-1;i>=0 && k<a[i];i--)
            a[i+1]=a[i];
        a[i+1]=k;
        printf("Pass %d elements inserted at proper place:%d\n",j,k);
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);
        printf("\n");
    }
        printf("Sorted list is:\n");
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);
        printf("\n");
}

