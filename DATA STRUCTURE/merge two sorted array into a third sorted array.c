#include<stdio.h>
int main()
{
    int a1[20],a2[20],a3[20];
    int i,j,k;
    int max1,max2;
    printf("Enter the NO of elements in list 1:");
    scanf("%d",&max1);
    printf("\nTake the elements in sorted order:\n");
    for(i=0;i<max1;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&a1[i]);
    }
    printf("\nEnter the No of elements in list 2:");
    scanf("%d",&max2);
    printf("\nTake the elements in sorted order:\n");
    for(i=0;i<max2;i++)
    {
        printf("Enter element %d:",i+1);
        scanf("%d",&a2[i]);
    }
    i=0;
    j=0;
    k=0;
    while((i<max1)&&(j<max2))
    {
        if(a1[i]<a2[j])
            a3[k++]=a1[i++];
        else
            a3[k++]=a2[j++];
    }
    while(i<max1)
        a3[k++]=a1[i++];
    while(j<max2)
        a3[k++]=a2[j++];
    printf("\nList 1: ");
    for(i=0;i<max1;i++)
        printf("%d\t",a1[i]);
    printf("\n\nList 2: ");
    for(i=0;i<max2;i++)
        printf("%d\t",a2[i]);
    printf("\n\nMerged list: ");
    for(i=0;i<max1+max2;i++)
        printf("%d ",a3[i]);
    printf("\n");
}
