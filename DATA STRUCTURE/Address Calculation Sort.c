#include<stdio.h>
#include<malloc.h>
#define max 20
struct node
{
    int data;
    struct node *link;
};
struct node *head[10];
int n,i,arr[max];
int main()
{
    int i;
    printf("Enter the number of elements in the list:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Unsorted List is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
    addr_sort();
    printf("Sorted List is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}
addr_sort()
{
    int i,k,dig;
    struct node *p;
    int addr;
    k=large_dig();
    for(i=0;i<=9;i++)
        head[i]=NULL;
    for(i=0;i<n;i++)
    {
        addr=hash_fn(arr[i],k);
        insert(arr[i],addr);
    }
    for(i=0;i<=9;i++)
    {
        printf("head(%d)->",i);
        p=head[i];
        while(p!=NULL)
        {
            printf("%d  ",p->data);
            p=p->link;
        }
        printf("\n");
    }
    i=0;
    for(k=0;k<=9;k++)
    {
        p=head[k];
        while(p!=NULL)
        {
            arr[i++]=p->data;
            p=p->link;
        }
    }
}
insert(int num,int addr)
{
    struct node *q,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=num;
    if(head[addr]==NULL || num<head[addr]->data)
    {
        tmp->link=head[addr];
        head[addr]=tmp;
        return;
    }
    else
    {
        q=head[addr];
        while(q->link!=NULL && q->link->data<num)
            q=q->link;
        tmp->link=q->link;
        q->link=tmp;
    }
}
int large_dig()
{
    int large=0,ndig=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>large)
            large=arr[i];
    }
    printf("\n Largest Element is %d",large);
    while(large!=0)
    {
        ndig++;
        large=large/10;
    }
    printf("\n Number of digits in it are %d\n",ndig);
    return(ndig);
}
hash_fn(int number,int k)
{
    int digit,addr,i;
    for(i=1;i<=k;i++)
    {
        digit=number%10;
        number=number/10;
    }
    addr=digit;
    return(addr);
}
