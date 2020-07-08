#include<stdio.h>
#include<malloc.h>
int insert();
int del_beg();
int del_last();
int del_pos();
int del_item();
int display();
int count();
int reverse();
int search();
struct node
{
    int data;
    struct node*link;
}*start;
main()
{
    int choice,n,m,pos,i;
    start=NULL;
    printf("1.Insert Item\n");
    printf("2.Delete at beginning\n");
    printf("3.Delete at last\n");
    printf("4.Delete at position\n");
    printf("5.Delete Item\n");
    printf("6.Display\n");
    printf("7.Count\n");
    printf("8.Reverse\n");
    printf("9.Search\n");
    printf("10.Quit\n");
    do
    {
         printf("Enter your choice:");
          scanf("%d",&choice);
         switch(choice)
        {
         case 1:
                printf("Enter the element:");
                     scanf("%d",&m);
                insert(m);
               break;
         case 2:
              del_beg();
              break;
         case 3:
              del_last();
              break;
          case 4:
              if(start==NULL)
              {
                   printf("List is Empty\n");
                    continue;
               }
               printf("Enter the position of item which is deleted:");
               scanf("%d",&pos);
               del_pos(pos);
               break;
         case 5:
              if(start==NULL)
              {
                   printf("List is Empty\n");
                    continue;
               }
               printf("Enter the element for deletion:");
               scanf("%d",&m);
               del_item(m);
               break;
        case 6:
              display();
              break;
        case 7:
              count();
              break;
        case 8:
              reverse();
               break;
        case 9:
               printf("Enter the element to be searched:");
                scanf("%d",&m);
                search(m);
                break;
        case 10:
               printf("EXIT");
                break;
        default:
                printf("Wrong Choice\n");
        }
    }
    while(choice!=10);
}
insert(int item)
{
    struct node*p,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    if(start==NULL || item<start->data)
    {
        tmp->link=start;
        start=tmp;
        return;
    }
    else
    {
        p=start;
        while(p->link!=NULL && p->link->data<item)
            p=p->link;
        tmp->link=p->link;
        p->link=tmp;
    }
}
del_beg()
{
    struct node*tmp;
    tmp=start;
    start=start->link;
    free(tmp);
}
del_last()
{
    struct node*tmp,*p;
    p=start;
    while(p->link->link!=NULL)
        p=p->link;
    tmp=p->link;
    p->link=NULL;
    free(tmp);
}
del_pos(int pos)
{
    int i;
    struct node*tmp,*p;
    i=1;
    p=start;
    while(i<pos-1)
    {
        p=p->link;
        i++;
    }
    tmp=p->link;
    p->link=tmp->link;
    free(tmp);
}
del_item(int item)
{
    struct node*tmp,*p;
    if(start->data==item)
    {
        tmp=start;
        start=start->link;
        free(tmp);
        return;
    }
    p=start;
    while(p->link->link!=NULL)
    {
        if(p->link->data==item)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            return;
        }
        p=p->link;
    }
    if(p->link->data==item)
    {
        tmp=p->link;
        free(tmp);
        p->link=NULL;
        return;
    }
}
display()
{
    struct node*p;
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }
    p=start;
    printf("List is:\n");
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->link;
    }
    printf("\n");
}
count()
{
    struct node*p=start;
    int count=0;
    while(p!=NULL)
    {
        p=p->link;
        count++;
    }
    printf("No of elements are %d\n",count);
}
reverse()
{
    struct node*p1,*p2,*p3;
    if(start->link==NULL)
           return;
    p1=start;
    p2=p1->link;
    p3=p2->link;
    p1->link=NULL;
    p2->link=p1;
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->link;
        p2->link=p1;
    }
    start=p2;
}
search(int item)
{
    struct node *p=start;
    int pos=1;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            printf("item %d found at position %d\n",item,pos);
            return;
        }
        p=p->link;
        pos++;
    }
    if(p==NULL)
        printf("Item %d not found in list\n",item);
}
