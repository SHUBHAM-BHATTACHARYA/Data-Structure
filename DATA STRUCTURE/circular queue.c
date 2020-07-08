#include<stdio.h>
int queue[100],choice,front,rear,max,top,x,i;
void insert(void);
void delete(void);
void display(void);
void peek(void);
int main()
{
    front=-1;
    rear=-1;
    printf("Enter the MAX size of Circular QUEUE:");
    scanf("%d",&max);
    printf("\n\t 1.INSERT\n\t 2.DELETE\n\t 3.DISPLAY\n\t 4.PEEK\n\t 5.EXIT\n\t");
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

    if((front==0 && rear==max-1)||(front==rear+1))
    {
        printf("\n\t Queue is over flow");
        return;
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==max-1)
    {
            rear=0;
    }
    else
    {
        rear=rear+1;
    }
    printf(" \n\t Enter a value to be Inserted:");
        scanf("%d",&x);
        queue[rear]=x;
}
void delete()
{
    if(front==-1)
    {
        printf("\n\t Queue is Underflow");
        return;
    }
    printf("\n\t The Deleted elements is %d",queue[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;

    }
    else
    {
        if(front==max-1)
            front=0;
        else
            front=front+1;
    }
    return queue[front];
}
void display()
{
    if(front>=0)
    {
        printf("\n The elements in QUEUE\n");
        if(front<=rear)
        {
            for(i=front;i<=rear;i++)
                printf("\n%d",queue[i]);
        }
        else
        {
        for(i=front;i<=max-1;i++)
                printf("\n%d",queue[i]);
        for(i=0;i<=rear;i++)
            printf("\n%d",queue[i]);
        }
    }
    else
        printf("Queue is Empty\n");
}
void peek()
{
    printf("Last Element of Queue is:%d",queue[front]);
}

