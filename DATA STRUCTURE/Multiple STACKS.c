#include<stdio.h>
#include<conio.h>
#define MAX 10
int stack[MAX],topA=-1,topB=MAX;
int main()
{
    int choice,val;
    printf("1.PUSH IN STACKA\n");
    printf("2.PUSH IN STACKB\n");
    printf("3.POP FROM STACKA\n");
    printf("4.POP FROM STACKB\n");
    printf("5.DISPLAY STACKA\n");
    printf("6.DISPLAY STACKB\n");
    printf("7.EXIT\n");
    do
    {
        printf("\nEnter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\n Enter the value to Pushed on StackA:");
            scanf("%d",&val);
            pushA(val);
            break;
        case 2:
            printf("\n Enter the value to Pushed on StackB:");
            scanf("%d",&val);
            pushB(val);
            break;
        case 3:
            val=popA();
            if(val!=-999)
                printf("\nThe Value Popped from StackA=%d",val);
            break;
        case 4:
            val=popB();
            if(val!=-999)
                printf("\n The Value Popped from StackB=%d",val);
            break;
        case 5:
            printf("\n The Content of StackA are:");
            display_stackA();
            break;
        case 6:
            printf("\n The Content of StackB are:");
            display_stackB();
            break;
        case 7:
            printf("\n EXIT");
        }
    }
    while(choice!=7);
}
void pushA(int val)
{
    if(topA==topB)
        printf("\n OVERFLOW");
    else
    {
        topA+=1;
        stack[topA]=val;
    }
}
int popA()
{
    int val;
    if(topA==-1)
    {
        printf("\n UNDERFLOW");
        val=-999;
    }
    else
    {
        val=stack[topA];
        topA--;
    }
    return val;
}
void display_stackA()
{
    int i;
    if(topA==-1)
        printf("\n Stack Empty");
    else
    {
        for(i=topA;i>=0;i--)
            printf("\n %d",stack[i]);
    }
}
void pushB(int val)
{
    if(topB-1==topA)
        printf("\n OVERFLOW");
    else
    {
        topB-=1;
        stack[topB]=val;
    }
}
int popB()
{
    int val;
    if(topB==MAX)
    {
        printf("\n UNDERFLOW");
        val=-999;
    }
    else
    {
        val=stack[topB];
        topB++;
    }
    return val;
}
void display_stackB()
{
    int i;
    if(topB==MAX)
        printf("\n Stack Empty");
    else
    {
        for(i=topB;i<MAX;i++)
            printf("\n %d",stack[i]);
    }
}
