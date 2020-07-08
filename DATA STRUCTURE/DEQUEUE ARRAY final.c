#include<stdio.h>
int input_queue();
int output_queue();
int insert_right();
int insert_left();
int delete_left();
int delete_right();
int display_queue();
int dequeue[100],left=-1,right=-1,choice,max;
main()
{
    printf("Enter the MAX size of DEQUEUE:");
    scanf("%d",&max);
    printf("1.Input restricted dequeue\n");
    printf("2.Output restricted dequeue\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            input_queue();
            break;
        case 2:
            output_queue();
            break;
        case 3:
             printf("EXIT\n");
             break;
        default:
             printf("Wrong Choice\n");
        }
}
input_queue()
{
    printf("1.Insert at right\n");
    printf("2.Delete from left\n");
    printf("3.Delete from right\n");
    printf("4.Display\n");
    printf("5.Quit\n");
    do
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert_right();
            break;
        case 2:
            delete_left();
            break;
        case 3:
            delete_right();
            break;
        case 4:
            display_queue();
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
output_queue()
{
    printf("1.Insert at right\n");
    printf("2.Insert at left\n");
    printf("3.Delete from left\n");
    printf("4.Display\n");
    printf("5.Quit\n");
    do
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert_right();
            break;
        case 2:
            insert_left();
            break;
        case 3:
            delete_left();
            break;
        case 4:
            display_queue();
            break;
        case 5:
            printf("EXIT");
            break;
        default:
            printf("Wrong Choice\n");
        }
    }
    while(choice!=5);
}
insert_right()
{
    int x;
    if((left==0&&right==max-1)||(left==right+1))
    {
        printf("Queue Overflow\n");
        return 0;
    }
    if(left==-1)
    {
        left=0;
        right=0;
    }
    else
    {
        if(right==max-1)
            right=0;
        else
            right=right+1;
    }
    printf("Input the element:");
    scanf("%d",&x);
    dequeue[right]=x;
}
insert_left()
{
    int x;
    if((left==0&&right==max-1)||(left==right+1))
    {
        printf("Queue Overflow\n");
         return 0;
    }
    if(left==-1)
    {
        left=0;
        right=0;
    }
    else
    {
        if(left==0)
            left=max-1;
        else
            left=left-1;
    }
    printf("Input the element:");
    scanf("%d",&x);
    dequeue[left]=x;
}
delete_left()
{
    if(left==-1)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    printf("Element deleted:%d\n",dequeue[left]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(left==max-1)
            left=0;
        else
            left=left+1;
    }
}
delete_right()
{
    if(left==-1)
    {
        printf("Queue Underflow\n");
        return 0;
    }
    printf("Element deleted:%d\n",dequeue[right]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(right==0)
            right=max-1;
        else
            right=right-1;
    }
}
display_queue()
{
    int front=left,rear=right;
    if(left==-1)
    {
        printf("Queue is Empty\n");
        return 0;
    }
    printf("Queue Elements:\n");
    if(front<=rear)
    {
        while(front<=rear)
        {
            printf("%d\t",dequeue[front]);
            front++;
        }
    }
    else
    {
        while(front<=max-1)
        {
            printf("%d\t",dequeue[front]);
            front++;
        }
        front=0;
        while(front<=rear)
        {
            printf("%d\t",dequeue[front]);
            front++;
        }
    }
    printf("\n");
}



