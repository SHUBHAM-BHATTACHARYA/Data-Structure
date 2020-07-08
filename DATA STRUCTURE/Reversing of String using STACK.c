#include<stdio.h>
#define MAX 40
#include<string.h>
int top=-1;
char stack[MAX];
char pop();
push(char);
int main()
{
    char str[40];
    int i;
    printf("Enter the String:");
    gets(str);
    for(i=0;i<strlen(str);i++)
        push(str[i]);
    for(i=0;i<strlen(str);i++)
        str[i]=pop();
    printf("Reversed String is:");
    puts(str);
}
push(char item)
{
    if(top==(MAX-1))
        printf("STACK Overflow\n");
    else
        stack[++top]=item;
}
char pop()
{
    if(top==-1)
        printf("Stack Underflow\n");
    else
        return stack[top--];
}
