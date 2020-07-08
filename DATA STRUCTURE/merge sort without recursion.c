#include<stdio.h>
#define MAX 30
int main()
{
    int a[MAX],tmp[MAX],i,j,k,n,size,l1,l2,h1,h2;
    printf("Enter the No of Elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&a[i]);
    }
    printf("Unsorted list is: ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    for(size=1;size<n;size=size*2)
    {
        l1=0;
        k=0;
        while(l1+size<n)
        {
            h1=l1+size-1;
            l2=h1+1;
            h2=l2+size-1;
            if(h2>=n)
                h2=n-1;
            i=l1;
            j=l2;
            while(i<=h1 && j<=h2)
            {
                if(a[i]<=a[j])
                    tmp[k++]=a[i++];
                else
                    tmp[k++]=a[j++];
            }
            while(i<=h1)
                tmp[k++]=a[i++];
            while(j<=h2)
                tmp[k++]=a[j++];
            l1=h2+1;
        }
        for(i=l1;k<n;i++)
            tmp[k++]=a[i];
        for(i=0;i<n;i++)
            a[i]=tmp[i];
        printf("\n Size=%d \nElements are: ",size);
        for(i=0;i<n;i++)
            printf("%d\t",a[i]);
    }
    printf("\nSorted list is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
}
