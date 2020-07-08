#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node*link;
}*start=NULL;
main()
{
    struct node *tmp,*p;
    int i,n,item;
    printf("Enter the No of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element%d: ",i+1);
        scanf("%d",&item);
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->data=item;
        tmp->link=NULL;
        if(start==NULL)
            start=tmp;
        else
        {
            p=start;
            while(p->link!=NULL)
                p=p->link;
            p->link=tmp;
        }
    }
    printf("\nUnsorted list is:\n");
    display();
    radix_sort();
    printf("\nSorted list is:\n");
    display();
}
display()
{
    struct node *p=start;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->link;
    }
    printf("\n");
}
radix_sort()
{
    int i,k,dig,maxdig,mindig,least_sig,most_sig;
    struct node *p,*rear[10],*front[10];
    least_sig=1;
    most_sig=large_dig(start);
    for(k=least_sig;k<=most_sig;k++)
    {
        printf("\nPASS %d: Examining %dth digit from right",k,k);
        for(i=0;i<=9;i++)
        {
            rear[i]=NULL;
            front[i]=NULL;
        }
        maxdig=0;
        mindig=9;
        p=start;
        while(p!=NULL)
        {
            dig=digit(p->data,k);
            if(dig>maxdig)
                maxdig=dig;
            if(dig<mindig)
                 mindig=dig;
            if(front[dig]==NULL)
                front[dig]=p;
            else
                rear[dig]->link=p;
            rear[dig]=p;
            p=p->link;
        }
        printf("\n mindig=%d   maxdig=%d\n",mindig,maxdig);
        start=front[mindig];
        for(i=mindig;i<maxdig;i++)
        {
            if(rear[i+1]!=NULL)
                rear[i]->link=front[i+1];
            else
                rear[i+1]=rear[i];
        }
        rear[maxdig]->link=NULL;
        printf("\n NEW LIST: ");
        display();
    }
}
int large_dig()
{
    struct node *p=start;
    int large=0,ndig=0;
    while(p!=NULL)
    {
        if(p->data>large)
            large=p->data;
        p=p->link;
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
int digit(int number,int k)
{
    int digit,i;
    for(i=0;i<=k;i++)
    {
        digit=number%10;
        number=number/10;
    }
    return(digit);
}

