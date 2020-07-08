#include<stdio.h>
#include<conio.h>
int partition(int a[],int n);
void radix_sort(int a[],int n);
void main()
{
    int a[10],i,j,n,k;
    printf("Enter the No.of elements in Array:");
    scanf("%d",&n);
    printf("Enter the Elements of the Array\n");
    for(i=0;i<n;i++)
    {
        printf("\n a[%d]=",i);
        scanf("%d",&a[i]);
    }
    radix_sort(a,n);
    printf("The Sorted Array is :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
int largest(int a[],int n)
{
    int large=a[0],i;
    for(i=1;i<n;i++)
    {
        if(a[i]>large)
            large=a[i];
    }
    return large;
}
void radix_sort(int a[],int n)
{
    int bucket[10][10],bucket_count[10];
    int i,j,k,remainder,NOP=0,divisor=1,large,pass;
    large=largest(a,n);
    while(large>0)
    {
        NOP++;
        large/=10;
    }
    for(pass=0;pass<NOP;pass++)
    {
        for(i=0;i<10;i++)
            bucket_count[i]=0;
        for(i=0;i<n;i++)
        {
            remainder=(a[i]/divisor)%10;
            bucket[remainder][bucket_count[remainder]]=a[i];
            bucket_count[remainder]+=1;
        }
        i=0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<bucket_count[k];j++)
            {
                a[i]=bucket[k][j];
                i++;
            }
        }
        divisor*=10;
    }
}
