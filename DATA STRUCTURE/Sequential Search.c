#include<stdio.h>
int main()
{
    int a[20],n,i,item;
    printf("Enter the No of Elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the Element to be searched: ");
    scanf("%d",&item);
    for(i=0;i<n;i++)
    {
        if(item==a[i])
        {
            printf("Item %d found at position %d\n",item,i+1);
            break;
        }
    }
    if(i==n)
        printf("Item %d not found in Array\n",item);
}
