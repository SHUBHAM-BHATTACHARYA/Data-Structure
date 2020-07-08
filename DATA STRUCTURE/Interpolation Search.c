#include<stdio.h>
int main()
{
    int a[20],low,mid,high,n,i,item;
    printf("Enter the No of Elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the Element to be searched: ");
    scanf("%d",&item);
    low=0;
    mid=-1;
    high=n-1;
    while(low<=high && item>=a[low] && item<=a[high])
    {
        mid=low+((high-low)*(item-a[low])/(a[high]-a[low]));
        if(a[mid]==item)
        {
            printf("%d found at position %d",item,mid+1);
                 break;
        }
        else if(a[mid]<item)
               low=mid+1;
        else if(a[mid>item])
               high=mid-1;
    }
    if(a[mid]!=item)
        printf("%d not found",item);
}
