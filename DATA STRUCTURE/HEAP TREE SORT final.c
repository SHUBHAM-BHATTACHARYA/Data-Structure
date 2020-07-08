#include<stdio.h>
int arr[20],n;
int insert(int,int);
int display();
int create_heap();
int heap_sort();
int del_root(int);
int main()
{
    int i;
    printf("Enter Number of Elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Entered List is:\n");
    display();
    create_heap();
    printf("Heap is:\n");
    display();
    heap_sort();
    printf("Sorted List is:\n");
    display();
}
display()
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
create_heap()
{
    int i;
    for(i=0;i<n;i++)
        insert(arr[i],i);
}
insert(int num,int loc)
{
    int par;
    while(loc>0)
    {
        par=(loc-1)/2;
        if(num<=arr[par])
        {
            arr[loc]=num;
            return 0;
        }
        arr[loc]=arr[par];
        loc=par;
    }
    arr[0]=num;
}
heap_sort()
{
    int last;
    for(last=n-1;last>0;last--)
        del_root(last);
}
del_root(int last)
{
    int left,right,i,temp;
    i=0;
    temp=arr[i];
    arr[i]=arr[last];
    arr[last]=temp;
    left=2*i+1;
    right=2*i+2;
    while(right<last)
    {
        if(arr[i]>=arr[left] && arr[i]>=arr[right])
            return 0;
        if(arr[right]<=arr[left])
        {
            temp=arr[i];
            arr[i]=arr[left];
            arr[left]=temp;
            i=left;
        }
        else
        {
            temp=arr[i];
            arr[i]=arr[right];
            arr[right]=temp;
            i=right;
        }
        left=2*i+1;
        right=2*i+2;
    }
    if(left==last-1 && arr[i]<arr[left])
    {
        temp=arr[i];
        arr[i]=arr[left];
        arr[left]=temp;
    }
}
