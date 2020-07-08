#include<stdio.h>
#define MAX 20
int main()
{
    int a[MAX],i,j,tmp,n,k,incr;
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
    printf("\n Enter maximum increment(odd value):");
    scanf("%d",&incr);
    while(incr>=1)
    {
        for(j=incr;j<n;j++)
        {
            k=a[j];
            for(i=j-incr;i>=0 && k<a[i];i=i-incr)
                a[i+incr]=a[i];
            a[i+incr]=k;
        }
        printf("Increment=%d\n",incr);
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);
        printf("\n");
        incr=incr-2;
    }
        printf("Sorted list is:\n");
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);
        printf("\n");
}

