#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 50
int pop ();
char infix[MAX], postfix[MAX];
int stack[MAX];
void infix_to_postfix();
int prec(char);
void push(int);
int top=0;
int main()
{
    int value;
    printf("Enter postfix and seperate the oparend by comma : ");
    fflush(stdin);
    gets(postfix);
    value=eval_post();
    printf("Value of expression : %d\n",value);
}
void push(int symbol)
{
    if(top > MAX)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	else
	{
		top=top+1;
		stack[top] = symbol;
	}
}
int pop()
{
    if (top == -1 )
	{
		printf("Stack underflow \n");
		exit(2);
	}
	else
		return (stack[top--]);if (top == -1 )
	{
		printf("Stack underflow \n");
		exit(2);
	}
	else
		return (stack[top--]);
}
int eval_post()
{
    long int a,b,temp,result,len;
    int i;
	len=strlen(postfix);
	postfix[len]='#';
	for(i=0;postfix[i]!='#';i++)
    {
        if (postfix[i]==',')
            continue;
        if(postfix[i]<='9' && postfix[i]>='0')
			push( postfix[i]-48 );
        else
		{
			a=pop();
			b=pop();
			switch(postfix[i])
			{
			case '+':
				temp=b+a; break;
			case '-':
				temp=b-a;break;
			case '*':
				temp=b*a;break;
			case '/':
				temp=b/a;break;
			case '%':
				temp=b%a;break;
			case '^':
				temp=pow(b,a);
			}
			push(temp);
		}
	}
    result=pop();
	return result;
}

