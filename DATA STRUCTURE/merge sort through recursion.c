#include<stdio.h>
#define MAX 20
int a[MAX];
int main()
{
    int i,n;
    printf("Enter the NO of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&a[i]);
    }
    printf("Unsorted list is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    merge_sort(0,n-1);
    printf("\nSorted list is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
}
merge_sort(int low,int high)
{
    int mid;
    if(low!=high)
    {
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}
merge(int low,int mid,int high)
{
    int tmp[MAX];
    int i=low;
    int j=mid+1;
    int k=low;
    while((i<=mid)&&(j<=high))
    {
        if(a[i]<=a[j])
            tmp[k++]=a[i++];
        else
            tmp[k++]=a[j++];
    }
    while(i<=mid)
        tmp[k++]=a[i++];
    while(j<=high)
        tmp[k++]=a[j++];
    for(i=low;i<=high;i++)
        a[i]=tmp[i];
}
