#include<stdio.h>
#include<malloc.h>
struct node
{
    int coef;
    int expo;
    struct node*link;
};
struct node *poly_add(struct node*,struct node*);
struct node *enter(struct node*);
struct node *insert(struct node*,int,int);
struct node *display(struct node*);
int main()
{
    int choice;
    struct node *p1_start,*p2_start,*p3_start;
    p1_start=NULL;
    p2_start=NULL;
    p3_start=NULL;
    printf("1.Create 1st Polynomial\n");
    printf("2.Display 1st Polynomial\n");
    printf("3.Create 2nd Polynomial\n");
    printf("4.Display 2nd Polynomial\n");
    printf("5.Add the Polynomial\n");
    printf("6.Display the Addition\n");
    printf("Exit\n");
    do
    {
         printf("Enter your choice:");
          scanf("%d",&choice);
         switch(choice)
         {
         case 1:
            p1_start=enter(p1_start);
            break;
         case 2:
            display(p1_start);
            break;
         case 3:
             p2_start=enter(p2_start);
            break;
         case 4:
            display(p2_start);
            break;
         case 5:
            p3_start=poly_add(p1_start,p2_start);
            break;
         case 6:
            display(p3_start);
            break;
         case 7:
            printf("EXIT\n");
            break;
         default:
            printf("Wrong Choice\n");
         }
    }
    while(choice!=7);
}
struct node *enter(struct node *start)
{
    int i,n,ex,co;
    printf("How many terms you want :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter coefficient for term %d:",i);
        scanf("%d",&co);
        printf("Enter exponent for term %d:",i);
        scanf("%d",&ex);
    }
    return start;
}
struct node *insert(struct node *start,int co,int ex)
{
    struct node *ptr,*tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->expo=ex;
    tmp->coef=co;
    if(start==NULL||ex>start->expo)
    {
        tmp->link=start;
        start=tmp;
    }
    else
    {
        ptr=start;
        while(ptr->link!=NULL&&ptr->link->expo>ex)
            ptr=ptr->link;
        tmp->link=ptr->link;
        ptr->link=tmp;
        if(ptr->link==NULL)
            tmp->link=NULL;
    }
    return start;
}
struct node *poly_add(struct node *p1,struct node *p2)
{
    struct node *p3_start,*p3,*tmp;
    p3_start=NULL;
    if(p1==NULL && p2==NULL)
        return p3_start;
    while(p1!=NULL && p2!=NULL)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        if(p3_start==NULL)
        {
            p3_start=tmp;
            p3=p3_start;
        }
        else
        {
            p3->link=tmp;
            p3=p3->link;
        }
        if(p1->expo>p2->expo)
        {
            tmp->coef=p1->coef;
            tmp->expo=p1->expo;
            p2=p2->link;
        }
        else
        {
            if(p2->expo>p1->expo)
            {
                tmp->coef=p2->coef;
                tmp->expo=p2->expo;
                p2=p2->link;
            }
            else if(p1->expo==p2->expo)
            {
                tmp->coef=p1->coef+p2->coef;
                tmp->expo=p1->expo;
                p1=p1->link;
                p2=p2->link;
            }

        }

    }
    while(p1!=NULL)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->coef=p1->coef;
        tmp->expo=p1->expo;
        if(p3_start==NULL)
        {
            p3_start=tmp;
            p3=p3_start;
        }
        else
        {
            p3->link=tmp;
            p3=p3->link;
        }
        p1=p1->link;

    }
    while(p2!=NULL)
    {
        tmp=(struct node*)malloc(sizeof(struct node));
        tmp->coef=p2->coef;
        tmp->expo=p2->expo;
        if(p3_start==NULL)
        {
            p3_start=tmp;
            p3=p3_start;
        }
        else
        {
            p3->link=tmp;
            p3=p3->link;
        }
        p2=p2->link;

    }
    p3->link=NULL;
    return p3_start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    printf("\n");
    if(ptr==NULL)
    {
       printf("EMPTY\n");
        return;
    }
    while(ptr!=NULL)
    {
        printf("%d*x^%d+",ptr->coef,ptr->expo);
        ptr=ptr->link;
    }
    printf("\b\b\n");
}
