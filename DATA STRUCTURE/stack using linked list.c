#include<stdio.h>
#include<malloc.h>
int push();
int pop();
int display();
int peek();
int count();
int reverse();
int search();
int sorted();
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
    printf("5.Count\n");
    printf("6.Reverse\n");
    printf("7.Search\n");
    printf("8.Sorted List\n");
    printf("9.EXIT\n");
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
              count();
              break;
        case 6:
              reverse();
               break;
        case 7:
               printf("Enter the element to be searched:");
                scanf("%d",&m);
                search(m);
                break;
        case 8:
              sorted();
              break;
        case 9:
               printf("EXIT\n");
                break;
        default:
                printf("Wrong Choice\n");
        }
    }
    while(choice!=9);
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
count()
{
    struct node*p=top;
    int count=0;
    while(p!=NULL)
    {
        p=p->link;
        count++;
    }
    printf("No of elements are %d\n",count);
}
reverse()
{
    struct node*p1,*p2,*p3;
    if(top->link==NULL)
           return;
    p1=top;
    p2=p1->link;
    p3=p2->link;
    p1->link=NULL;
    p2->link=p1;
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->link;
        p2->link=p1;
    }
    top=p2;
}
search(int item)
{
    struct node *p=top;
    int pos=1;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            printf("item %d found at position %d\n",item,pos);
            return;
        }
        p=p->link;
        pos++;
    }
    if(p==NULL)
        printf("Item %d not found in list\n",item);
}
sorted()
{
    struct node *p1,*p2;
    int k;
    p1=top;
    while(p1->link!=NULL)
    {
        p2=p1->link;
        while(p2!=NULL)
        {
            if(p1->data > p2->data)
            {
                k=p1->data;
                p1->data=p2->data;
                p2->data=k;
            }
            p2=p2->link;
        }
        p1=p1->link;
    }
}

