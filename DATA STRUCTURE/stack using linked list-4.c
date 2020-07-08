#include<stdio.h>
#include<malloc.h>
int push();
int pop();
int display();
int peek();
struct node
{
    int data;
    struct node*link;
}*top;
main()
{
    int choice,n,m,pos,i;
    top=NULL;
    printf("1.Push\n");
    printf("2.Pop\n");
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
               push();
               break;
         case 2:
               pop();
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
push()
{
    struct node *tmp;
    int item;
    tmp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be pushed:");
    scanf("%d",&item);
    tmp->data=item;
    tmp->link=top;
    top=tmp;
}
pop()
{
    struct node*tmp;
    if(top==NULL)
        printf("Stack is empty\n");
    else
    {
        tmp=top;
        printf("Popped element is %d\n",tmp->data);
        top=top->link;
        free(tmp);
    }
}
display()
{
    struct node *ptr;
    ptr=top;
    if(top==NULL)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements:\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->link;
        }
    }
}
peek()
{
    printf("The value stored at the top is:%d\n",top->data);
}
