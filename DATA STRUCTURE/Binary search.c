#include<stdio.h>
int main()
{
    int a[20],start,end,middle,n,i,item;
    printf("Enter the No of Elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the Element to be searched: ");
    scanf("%d",&item);
    start=0;
    end=n-1;
    middle=(start+end)/2;
    while(item!=a[middle] && start<=end)
    {
        if(item>a[middle])
            start=middle+1;
        else
            end=middle-1;
        middle=(start+end)/2;
    }
    if(item==a[middle])
        printf("%d found at position %d\n",item,middle+1);
    if(start>end)
        printf("%d not found in array\n",item);
}
