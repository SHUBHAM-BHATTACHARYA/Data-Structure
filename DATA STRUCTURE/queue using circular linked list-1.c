#include<stdio.h>
#include<malloc.h>
int insert();
int delete();
int display();
int peek();
struct node
{
    int data;
    struct node*link;
}*rear;
main()
{
    int choice,n,m,pos,i;
    rear=NULL;
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display\n");
    printf("4.Peek\n");
    printf("5.EXIT\n");
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
               printf("EXIT\n");
                break;
        default:
                printf("Wrong Choice\n");
        }
    }
    while(choice!=5);
}
insert()
{
    struct node *p,*tmp;
    int item;
    tmp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be Insert:");
    scanf("%d",&item);
    tmp->data=item;
    tmp->link=NULL;
    if(rear==NULL)
    {
        rear=tmp;
        tmp->link=rear;
    }
    else
    {
        tmp->link=rear->link;
        rear->link=tmp;
        rear=tmp;
    }
}
delete()
{
    struct node *tmp,*p;
    if(rear==NULL)
        printf("QUEUE is Underflow\n");
    else if(rear->link==rear)
    {
        tmp=rear;
        rear=NULL;
        free(tmp);
        return;
    }
    p=rear->link;
    tmp=p;
    rear->link=p->link;
    printf("Deleted element is %d\n",tmp->data);
    free(tmp);
}
display()
{
    struct node *p;
    if(rear==NULL)
    {
        printf("QUEUE is empty\n");
        return;
    }
    p=rear->link;
        printf("QUEUE elements:\n");
        while(p!=rear)
        {
            printf("%d\n",p->data);
            p=p->link;
        }
        printf("%d\n",rear->data);
}
peek()
{
    printf("The value stored at the front is:%d\n",rear->data);
}


