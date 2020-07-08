#include<stdio.h>
#define MAX 30
enum bool {FALSE,TRUE};
int quick(int arr[],int low,int up);
int display(int arr[],int low,int up);
int main()
{
    int array[MAX],n,i;
    printf("Enter the No of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Element%d: ",i+1);
        scanf("%d",&array[i]);
    }
    printf("\n Unsorted list is :\n");
    display(array,0,n-1);
    printf("\n");
    quick(array,0,n-1);
    printf("Sorted list is:\n");
    display(array,0,n-1);
    printf("\n");
}
quick(int arr[],int low,int up)
{
    int piv,tmp,left,right;
    enum bool pivot_placed=FALSE;
    left=low;
    right=up;
    piv=low;
    if(low>=up)
        return;
    printf("Sublist: ");
    display(arr,low,up);
    while(pivot_placed==FALSE)
    {
        while(arr[piv]<=arr[right] && piv!=right)
            right=right+1;
        if(piv==right)
            pivot_placed=TRUE;
        if(arr[piv]>arr[right])
        {
            tmp=arr[piv];
            arr[piv]=arr[right];
            arr[right]=tmp;
            piv=right;
        }
        while(arr[piv]>=arr[left] && left!=piv)
            left=left+1;
        if(piv==left)
            pivot_placed=TRUE;
        if(arr[piv]<arr[left])
        {
            tmp=arr[piv];
            arr[piv]=arr[left];
            arr[left]=tmp;
            piv=left;
        }
    }
    printf("->Pivot Placed is %d->",arr[piv]);
    display(arr,low,up);
    printf("\n");
    quick(arr,low,piv-1);
    quick(arr,piv+1,up);
}
display(int arr[],int low,int up)
{
    int i;
    for(i=low;i<=up;i++)
        printf("%d",arr[i]);
}

