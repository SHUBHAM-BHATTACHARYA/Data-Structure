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

