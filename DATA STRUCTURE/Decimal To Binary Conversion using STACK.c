#include<stdio.h>
#include<conio.h>
#define max 20
int st[max],top=-1;
void push(int st[],int val);
int pop(int st[]);
int main()
{
    int num,digit;
    printf("\n Enter any Decimal Number:");
    scanf("%d",&num);
    while(num>0)
    {
        digit=num%2;
        push(st,digit);
        num/=2;
    }
    printf("\n The Binary equivalent is:");
    while(top!=-1)
        printf("%d",pop(st));
    getch();
    return 0;
}
void push(int st[],int val)
{
    if(top==max-1)
        printf("\n STACK OVERFLOW");
    else
    {
        top++;
        st[top]=val;
    }
}
int pop(int st[])
{
    int val;
    if(top==-1)
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    }
    else
    {
        val=st[top];
        top--;
        return val;
    }
}
