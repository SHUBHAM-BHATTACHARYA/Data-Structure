#include<stdio.h>
int queue[100],choice,front,rear,max,top,x,i;
void push(void);
void pop(void);
void display(void);
void peek(void);
int main()
{
    top=-1;
    front=-1;
    rear=-1;
    printf("Enter the MAX size of QUEUE:");
    scanf("%d",&max);
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.PEEK\n\t 5.EXIT\n\t");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                delete();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                peek();
                break;
            }
            case 5:
            {
                printf("\n\t EXIT");
                break;
            }
            default:
            {
                printf("\n\t Please enter a valid choice(1/2/3/4)");
            }
        }
    }
    while(choice!=5);
    return 0;
}
void insert()
{
    if(rear==max-1)
    {
        printf("\n\t Queue is over flow");
    }
    else
    {
        if(front==-1)
            front=0;
        printf(" Enter a value to be Inserted:");
        scanf("%d",&x);
        rear=rear+1;
        queue[rear]=x;
    }
}
void delete()
{
    if(front==-1||front>rear)
    {
        printf("\n\t Queue is underflow");
    }
    else
    {
        printf("\n\t The Deleted elements is %d",queue[front]);
        front=front+1;
    }
}
void display()
{
    if(front>=0)
    {
        printf("\n The elements in QUEUE\n");
        for(i=front;i<=rear;i++)
            printf("\n%d",queue[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The QUEUE is empty");
    }
}
void reverse()
{

    if(front>=0)
    {
        printf("\n The Reverse elements of Queue\n");
        for(i=rear;i>=front;i--)
            printf("\n%d",queue[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The QUEUE is empty");
    }
}
