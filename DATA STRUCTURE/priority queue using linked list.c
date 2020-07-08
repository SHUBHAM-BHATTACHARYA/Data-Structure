#include<stdio.h>
#include<malloc.h>
int insert();
int delete();
int display();
int count();
int reverse();
int search();
struct node
{
    int data;
    int priority;
    struct node*link;
}*front;
main()
{
    int choice,n,m,pos,i;
    front=NULL;
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display\n");
    printf("4.Count\n");
    printf("5.Reverse\n");
    printf("6.Search\n");
    printf("7.EXIT\n");
    do
    {
         printf("Enter your choice:");
          scanf("%d",&choice);
         switch(choice)
         {
         case 1:
               insert();
               break;
         case 2:
               delete();
               break;
        case 3:
               display();
               break;
        case 4:
              count();
              break;
        case 5:
              reverse();
               break;
        case 6:
               printf("Enter the element to be searched:");
                scanf("%d",&m);
                search(m);
                break;
        case 7:
               printf("EXIT\n");
                break;
        default:
                printf("Wrong Choice\n");
        }
    }
    while(choice!=7);
}
insert()
{
    struct node *tmp,*p;
    int item,item_priority;
    tmp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be Insert:");
    scanf("%d",&item);
    printf("Enter the priority:");
    scanf("%d",&item_priority);
    tmp->data=item;
    tmp->priority=item_priority;
    if(front==NULL || item_priority<front->priority)
    {
        tmp->link=front;
        front=tmp;
    }
    else
    {
        p=front;
        while(p->link!=NULL && p->link->priority<=item_priority)
            p=p->link;
        tmp->link=p->link;
        p->link=tmp;
    }
}
delete()
{
    struct node*tmp;
    if(front==NULL)
        printf("QUEUE is Underflow\n");
    else
    {
        tmp=front;
        printf("Delete element is %d\n",tmp->data);
        front=front->link;
        free(tmp);
    }
}
display()
{
    struct node *ptr;
    ptr=front;
    if(front==NULL)
        printf("QUEUE is empty\n");
    else
    {
        printf("QUEUE elements:\n");
        printf("Priority    Item\n");
        while(ptr!=NULL)
        {
            printf("%5d    %5d\n",ptr->priority,ptr->data);
            ptr=ptr->link;
        }
    }
}
count()
{
    struct node*p=front;
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
    if(front->link==NULL)
           return;
    p1=front;
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
    front=p2;
}
search(int item)
{
    struct node *p=front;
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

