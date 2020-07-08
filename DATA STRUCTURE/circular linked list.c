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
    struct node*link;
}*last;
main()
{
    int choice,n,m,pos,i;
    last=NULL;
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
              if(last==NULL)
              {
                   printf("List is Empty\n");
                    continue;
               }
               printf("Enter the position of item which is deleted:");
               scanf("%d",&pos);
               del_pos(pos);
               break;
         case 8:
              if(last==NULL)
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
    if(last==NULL)
    {
        last=tmp;
        tmp->link=last;
    }
    else
    {
        tmp->link=last->link;
        last->link=tmp;
        last=tmp;
    }
}
add_beg(int item)
{
    struct node*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    tmp->link=last->link;
    last->link=tmp;
}
add_last(int item)
{
    struct node*p,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    tmp->link=last->link;
    last->link=tmp;
    last=tmp;
}
add_pos(int item,int pos)
{
    struct node *tmp,*p;
    int i;
    p=last->link;
    for(i=0;i<pos-1;i++)
    {
        p=p->link;
        if(p==last->link)
        {
            printf("There are less than %d elements",pos);
            return;
        }
    }
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->link=p->link;
    tmp->data=item;
    p->link=tmp;
    if(p==last)
        last=tmp;
}
del_beg()
{
    struct node*tmp;
    tmp=last->link;
    last->link=tmp->link;
    free(tmp);
}
del_last()
{
    struct node*tmp,*p;
    p=last->link;
    while(p->link!=last)
        p=p->link;
    tmp=last;
    p->link=last->link;
    last=p;
    free(tmp);
}
del_pos(int pos)
{
    int i;
    struct node*tmp,*p;
    i=0;
    p=last;
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
    if(last->link==last&&last->data==item)
    {
        tmp=last;
        last=NULL;
        free(tmp);
        return;
    }
    p=last->link;
    if(p->data==item)
    {
        tmp=p;
        last->link=p->link;
        free(tmp);
        return;
    }
    while(p->link!=last)
    {
        if(p->link->data==item)
        {
            tmp=p->link;
            p->link=tmp->link;
            free(tmp);
            printf("%d deleted\n",item);
            return;
        }
        p=p->link;
    }
    if(p->link->data==item)
        {
            tmp=p->link;
            p->link=last->link;
            free(tmp);
            last=p;
            return;
        }
}
display()
{
    struct node*p;
    if(last==NULL)
    {
        printf("List is empty\n");
        return;
    }
    p=last->link;
    printf("List is:\n");
    while(p!=last)
    {
        printf("%d\t",p->data);
        p=p->link;
    }
    printf("%d\n",last->data);
}
count()
{
    struct node*p;
    int count=0,tmp;
    p=last->link;
    while(p!=last)
    {
        p=p->link;
        count++;
    }
    tmp=count+1;
    printf("No of elements are %d\n",tmp);
}
reverse()
{
    struct node*p1,*p2,*p3;
    int tmp;
    p1=last->link;
    tmp=p1;
    p2=p1->link;
    p3=p2->link;
    p1->link=last;
    p2->link=p1;
    while(p3!=last)
    {
        p1=p2;
        p2=p3;
        p3=p3->link;
        p2->link=p1;
    }
    p3->link=p2;
    last=tmp;
}
search(int item)
{
    struct node *p;
    int pos=1,f=0;
    p=last->link;
    while(p!=last)
    {
        if(p->data==item)
        {
            f=1;
            break;
        }
        p=p->link;
        pos++;
    }
    if(last->data==item)
        f=1;
    if(f==0)
        printf("Item %d not found in list\n",item);
    else
        printf("item %d found at position %d\n",item,pos);

}
sorted()
{
    struct node *p1,*p2;
    int k;
    p1=last->link;
    while(p1->link!=last->link)
    {
        p2=p1->link;
        while(p2!=last->link)
        {
            if(p1->data>p2->data)
            {
                k=p1->data;
                p1->data=p2->data;
                p2->data=k;
            }
            p2=p2->link;
        }
        p1=p1->link;
    }
}

