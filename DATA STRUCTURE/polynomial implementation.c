#include<stdio.h>
int main()
{
    int a[100],i,n;
    printf("Enter the Highest power of X:");
    scanf("%d",&n);
    printf("Enter the Coefficient of X from highest power to lowest power:\n");
    for(i=n;i>=0;i--)
        scanf("%d",&a[i]);
    printf("Polynomial Expression are:\n");
    for(i=n;i>=0;i--)
    {
        if(a[i]==0)
            continue;
        else if(i>0)
            printf("%d*x^%d+",a[i],i);
        else
            printf("%d*x^%d",a[i],i);
    }
}
