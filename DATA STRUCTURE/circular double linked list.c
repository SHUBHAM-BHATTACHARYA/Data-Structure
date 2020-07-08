#include<stdio.h>
#include<malloc.h>
int create_list();
int add_beg();
int add_last();
int add_pos();
int del_beg();
int del_last();
int del_pos();
int del_item();
int display();
int count();
int reverse();
int search();
int sorted();
struct node
{
    int data;
    struct node*prev;
    struct node*next;
}*start;
main()
{
    int choice,n,m,pos,i;
    start=NULL;
    printf("1.Create List\n");
    printf("2.Add at beginning\n");
    printf("3.Add at last\n");
    printf("4.Add at position\n");
    printf("5.Delete at beginning\n");
    printf("6.Delete at last\n");
    printf("7.Delete at position\n");
    printf("8.Delete Item\n");
    printf("9.Display\n");
    printf("10.Count\n");
    printf("11.Reverse\n");
    printf("12.Search\n");
    printf("13.Sorted List\n");
    printf("14.Quit\n");
    do
    {
         printf("Enter your choice:");
          scanf("%d",&choice);
         switch(choice)
        {
         case 1:
               printf("How many nodes you want:");
               scanf("%d",&n);
               for(i=0;i<n;i++)
               {
                   printf("Enter the element:");
                     scanf("%d",&m);
                   create_list(m);
               }
               break;
         case 2:
               printf("Enter the element:");
               scanf("%d",&m);
               add_beg(m);
               break;
        case 3:
               printf("Enter the element:");
               scanf("%d",&m);
               add_last(m);
               break;
         case 4:
               printf("Enter the element:");
                scanf("%d",&m);
               printf("Enter the position after which this element is inserted:");
                scanf("%d",&pos);
              add_pos(m,pos);
              break;
         case 5:
              del_beg();
              break;
         case 6:
              del_last();
              break;
          case 7:
              if(start==NULL)
              {
                   printf("List is Empty\n");
                    continue;
               }
               printf("Enter the position of item which is deleted:");
               scanf("%d",&pos);
               del_pos(pos);
               break;
         case 8:
              if(start==NULL)
              {
                   printf("List is Empty\n");
                    continue;
               }
               printf("Enter the element for deletion:");
               scanf("%d",&m);
               del_item(m);
               break;
        case 9:
              display();
              break;
        case 10:
              count();
              break;
        case 11:
              reverse();
               break;
        case 12:
               printf("Enter the element to be searched:");
                scanf("%d",&m);
                search(m);
                break;
        case 13:
              sorted();
              break;
        case 14:
               printf("EXIT");
                break;
        default:
                printf("Wrong Choice\n");
        }
    }
    while(choice!=14);
}
create_list(int item)
{
    struct node*p,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    if(start==NULL)
    {
        tmp->prev=NULL;
        start=tmp;
        tmp->next=start;
    }
    else
    {
        p=start;
        while(p->next!=start)
            p=p->next;
        p->next=tmp;
        tmp->prev=p;
        tmp->next=start;
        start->prev=tmp;
    }
}
add_beg(int item)
{
    struct node*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    tmp->next=start;
    tmp->prev=start->prev;
    start->prev->next=tmp;
    start->prev=tmp;
    start=tmp;
}
add_last(int item)
{
    struct node*tmp,*p;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    p=start->prev;
    tmp->prev=p;
    tmp->next=start;
    start->prev=tmp;
    p->next=tmp;
}
add_pos(int item,int pos)
{
     struct node*tmp,*p;
    int i;
    p=start;
    for(i=0;i<pos-1;i++)
    {
        p=p->next;
        if(p==NULL)
        {
            printf("There are less than %d element",pos);
            return;
        }
    }
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    p->next->prev=tmp;
    tmp->next=p->next;
    tmp->prev=p;
    p->next=tmp;
}
del_beg()
{
    struct node*tmp;
    tmp=start;
    tmp->next->prev=tmp->prev;
    tmp->prev->next=tmp->next;
    start=start->next;
    free(tmp);
}
del_last()
{
    struct node*tmp,*p;
    tmp=start->prev;
    tmp->prev->next=tmp->next;
    start->prev=tmp->prev;
    free(tmp);
}
del_pos(int pos)
{
    struct node*p;
    int i;
    p=start;
    for(i=1;i<pos;i++)
        p=p->next;
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
}
del_item(int item)
{
   struct node*tmp,*p;
    if(start->data==item)
    {
        tmp=start;
        start=start->next;
        start->prev=NULL;
        return;
    }
    p=start;
    while(p->next->next!=NULL)
    {
        if(p->next->data==item)
        {
            tmp=p->next;
            p->next=tmp->next;
            tmp->next->prev=p;
            free(tmp);
            return;
        }
        p=p->next;
    }
    if(p->next->data==item)
    {
        tmp=p->next;
        free(tmp);
        p->next=NULL;
        return;
    }
    printf("Element %d not found\n",item);
}
display()
{
    struct node*p;
    if(start==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    p=start;
    printf("List is:\n");
    while(p->next!=start)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}
count()
{
    struct node*p=start;
    int count=1;
    while(p->next!=start)
    {
        p=p->next;
        count++;
    }
    printf("Number of elements are %d\n",count);
}
reverse()
{
   struct node*p1,*p2;
    p1=start;
    p2=p1->next;
    p1->next=start->prev;
    p1->prev=p2;
    while(p2!=start->next)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    p2->prev=p2->next;
    p2->next=p1;
    start=p2;
}
search(int item)
{
    struct node *p;
    int pos=1,f=0;
    p=start;
    while(p->next!=start)
    {
        if(p->data==item)
        {
            f=1;
            break;
        }
        p=p->next;
        pos++;
    }
    if(p->data==item)
        f=1;
    if(f==0)
         printf("Item %d not found in list\n",item);
    else
        printf("Item %d found at position %d in list\n",item,pos);
}
sorted()
{
    struct node *p1,*p2;
    int k;
    p1=start;
    while(p1->next!=start)
    {
        p2=p1->next;
        while(p2!=start)
        {
            if(p1->data>p2->data)
            {
                k=p1->data;
                p1->data=p2->data;
                p2->data=k;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}



