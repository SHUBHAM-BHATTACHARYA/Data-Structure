#include<stdio.h>
#define MAX 20
int main()
{
    int a[MAX],i,j,tmp,n,k,smallest;
    printf("Enter the No of elements:");
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
        smallest=i;
        for(k=i+1;k<n;k++)
        {
            if(a[smallest]>a[k])
                smallest=k;
        }
        if(i!=smallest)
        {
            tmp=a[i];
            a[i]=a[smallest];
            a[smallest]=tmp;
        }
        printf("after Pass %d elements are:\n",i+1);
        for(j=0;j<n;j++)
            printf("%d\t",a[j]);
        printf("\n");
    }
        printf("Sorted list is:\n");
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);
        printf("\n");
}

