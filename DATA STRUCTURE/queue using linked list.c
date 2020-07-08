#include<stdio.h>
#include<malloc.h>
int insert();
int delete();
int display();
int peek();
int count();
int reverse();
int search();
int sorted();
struct node
{
    int data;
    struct node*link;
}*front,*rear;
main()
{
    int choice,n,m,pos,i;
    front=NULL;
    rear=NULL;
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display\n");
    printf("4.Peek\n");
    printf("5.Count\n");
    printf("6.Reverse\n");
    printf("7.Search\n");
    printf("8.Sorted List\n");
    printf("9.EXIT\n");
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
               peek();
               break;
        case 5:
              count();
              break;
        case 6:
              reverse();
               break;
        case 7:
               printf("Enter the element to be searched:");
                scanf("%d",&m);
                search(m);
                break;
        case 8:
              sorted();
              break;
        case 9:
               printf("EXIT\n");
                break;
        default:
                printf("Wrong Choice\n");
        }
    }
    while(choice!=9);
}
insert()
{
    struct node *tmp;
    int item;
    tmp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be Insert:");
    scanf("%d",&item);
    tmp->data=item;
    tmp->link=NULL;
    if(front==NULL)
        front=tmp;
    else
        rear->link=tmp;
    rear=tmp;
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
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
peek()
{
    printf("The value stored at the front is:%d\n",front->data);
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
sorted()
{
    struct node *p1,*p2;
    int k;
    p1=front;
    while(p1->link!=NULL)
    {
        p2=p1->link;
        while(p2!=NULL)
        {
            if(p1->data > p2->data)
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



