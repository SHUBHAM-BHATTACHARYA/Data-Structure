#include<stdio.h>
int main()
{
    int i,n,a[100],item,f=0;
    printf("enter the value of n");
    scanf("%d",&n);
    printf("enter the value of array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        printf("enter the value of item");
        scanf("%d",&item);
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        printf("item found");
        else
            printf("item not found");
    return 0;
}

