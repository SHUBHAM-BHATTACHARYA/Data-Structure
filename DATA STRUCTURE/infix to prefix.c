#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 50
int pop();
char infix[MAX],postfix[MAX];
int stack[MAX];
void infix_to_postfix();
int prec(char);
void push(int);
int pop();
int top=0;
int main()
{
    int i;
    printf("Enter Infix Expression:");
    fflush(stdin);
    gets(infix);
    strrev(infix);
    for(i=0;infix[i]!='\0';i++)
    {
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
    }
    infix_to_postfix();
    strrev(postfix);
    printf("Prefix Expression:%s\n",postfix);
}
void infix_to_postfix()
{
    int i,p=0,type,precedence,len,a[MAX];
    char next;
    stack[top]='#';
    len=strlen(infix);
    infix[len]='#';
    for(i=0;infix[i]!='#';i++)
    {
        switch(infix[i])
        {
        case '(':
            push(infix[i]);
            break;
        case ')':
            while((next=pop())!='(')
                   postfix[p++]=next;
                   break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
            precedence=prec(infix[i]);
            while(stack[top]!='#' && precedence<prec(stack[top]))
                postfix[p++]=pop();
            push(infix[i]);
            break;
            default:postfix[p++]=infix[i];
        }
    }
    while(stack[top]!='#')
        postfix[p++]=pop();
    postfix[p]='\0';
}
int prec(char symbol)
{
    switch(symbol)
    {
    case '(':
        return 0;
    case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;

    }
}void push(int symbol)
{
    if(top>MAX)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    else
    {
        top=top+1;
        stack[top]=symbol;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        exit(2);
    }
    else
        return(stack[top--]);
}

