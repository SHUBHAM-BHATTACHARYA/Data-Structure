#include<stdio.h>
int main()
{
    int a[100],b[100],i,n1,n2,c[100],h;
    printf("Enter the Highest power of X in 1st Expression:");
    scanf("%d",&n1);
    printf("Enter the Coefficient of X from highest power to lowest power:\n");
    for(i=n1;i>=0;i--)
        scanf("%d",&a[i]);
    printf("Polynomial Expression are:\n");
    for(i=n1;i>=0;i--)
    {
        if(a[i]==0)
            continue;
        else if(i>0)
            printf("%d*x^%d+",a[i],i);
        else
            printf("%d*x^%d",a[i],i);
    }
    printf("\nEnter the Highest power of X in 2nd Expression:");
    scanf("%d",&n2);
    printf("Enter the Coefficient of X from highest power to lowest power:\n");
    for(i=n2;i>=0;i--)
        scanf("%d",&b[i]);
    printf("Polynomial Expression are:\n");
    for(i=n2;i>=0;i--)
    {
        if(b[i]==0)
            continue;
        else if(i>0)
            printf("%d*x^%d+",b[i],i);
        else
            printf("%d*x^%d",b[i],i);
    }
    printf("\nPolynomial Addition=\n");
    if(n1>n2)
    {
        for(i=0;i<=n1;i++)
            c[i]=a[i]+b[i];
        for(i=n1;i<n2;i++)
            c[i]=a[i];
         h=n1;
    }
    else
    {
        for(i=0;i<=n2;i++)
            c[i]=a[i]+b[i];
        for(i=n2;i<n1;i++)
            c[i]=b[i];
        h=n2;
    }
    for(i=h;i>=0;i--)
    {
        if(c[i]==0)
            continue;
        else if(i>0)
             printf("%d*x^%d+",c[i],i);
        else
            printf("%d*x^%d",c[i],i);
    }
}

