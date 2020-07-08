#include<stdio.h>
#include<malloc.h>
typedef enum{FALSE,TRUE}bool;
struct node
{
    int data;
    int balance;
    struct node*lchild;
    struct node*rchild;
};
struct node*insert(int,struct node*,int*);
struct node*search(struct node*,int);
main()
{
    bool ht_inc;
    int data;
    int choice;
    struct node*root=(struct node*)malloc(sizeof(struct node));
    root=NULL;
      printf("1.Insert\n");
      printf("2.Display\n");
      printf("3.Quit\n");
      do
      {
          printf("Enter Your Choice:");
          scanf("%d",&choice);
          switch(choice)
          {
          case 1:
            printf("Enter the value to be Inserted:");
            scanf("%d",&data);
            if(search(root,data)==NULL)
                root=insert(data,root,&ht_inc);
            else
                printf("Duplicate value ignored\n");
            break;
          case 2:
            if(root==NULL)
            {
                printf("Tree is empty\n");
                continue;
            }
            printf("Tree is:\n");
            display(root,1);
            printf("\n\n");
            printf("Inorder Traversal is:");
            inorder(root);
            printf("\n");
            break;
          case 3:
            printf("EXIT");
            break;
          default:
            printf("Wrong Choice\n");
          }
      }
      while(choice!=3);
}
struct node*search(struct node *ptr,int data)
{
    if(ptr!=NULL)
        if(data<ptr->data)
        ptr=search(ptr->lchild,data);
    else if(data>ptr->data)
        ptr=search(ptr->rchild,data);
    return(ptr);
}
struct node *insert(int data,struct node *pptr,int *ht_inc)
{
    struct node *aptr;
    struct node *bptr;
    if(pptr==NULL)
    {
        pptr=(struct node *)malloc(sizeof(struct node));
        pptr->data=data;
        pptr->lchild=NULL;
        pptr->rchild=NULL;
        pptr->balance=0;
        *ht_inc=TRUE;
        return(pptr);
    }
    if(data<pptr->data)
    {
        pptr->lchild=insert(data,pptr->lchild,ht_inc);
        if(*ht_inc==TRUE)
        {
            switch(pptr->balance)
            {
            case -1:
                pptr->balance=0;
                *ht_inc=FALSE;
                break;
            case 0:
                pptr->balance=1;
                break;
            case 1:
                aptr=pptr->lchild;
                if(aptr->balance==1)
                {
                    printf("Left to Left Rotation\n");
                    pptr->lchild=aptr->rchild;
                    aptr->rchild=pptr;
                    pptr->balance=0;
                    aptr->balance=0;
                    pptr=aptr;
                }
                else
                {
                    printf("Left to Right Rotation\n");
                    bptr=aptr->rchild;
                    aptr->rchild=bptr->lchild;
                    bptr->lchild=aptr;
                    pptr->lchild=bptr->rchild;
                    bptr->rchild=pptr;
                    if(bptr->balance==1)
                        pptr->balance=-1;
                    else
                        pptr->balance=0;
                    if(bptr->balance==-1)
                        aptr->balance=1;
                    else
                        aptr->balance=0;
                    bptr->balance=0;
                    pptr=bptr;
                }
                *ht_inc=FALSE;
            }
        }
    }
    if(data>pptr->data)
    {
        pptr->rchild=insert(data,pptr->rchild,ht_inc);
        if(*ht_inc==TRUE)
        {
            switch(pptr->balance)
            {
            case 1:
                pptr->balance=0;
                *ht_inc=FALSE;
                break;
            case 0:
                pptr->balance=-1;
                break;
            case -1:
                aptr=pptr->rchild;
                if(aptr->balance==-1)
                {
                    printf("Right to Right Rotation\n");
                    pptr->rchild=aptr->lchild;
                    aptr->lchild=pptr;
                    pptr->balance=0;
                    aptr->balance=0;
                    pptr=aptr;
                }
                else
                {
                    printf("Right to Left Rotation\n");
                    bptr=aptr->lchild;
                    aptr->lchild=bptr->rchild;
                    bptr->rchild=aptr;
                    pptr->rchild=bptr->lchild;
                    bptr->lchild=pptr;
                    if(bptr->balance==-1)
                        pptr->balance=1;
                    else
                        pptr->balance=0;
                    if(bptr->balance==1)
                        aptr->balance=-1;
                    else
                        aptr->balance=0;
                    bptr->balance=0;
                    pptr=bptr;
                }
                *ht_inc=FALSE;
            }
        }
    }
    return(pptr);
}
display(struct node *ptr,int level)
{
    int i;
    if(ptr!=NULL)
    {
        display(ptr->rchild,level+1);
        printf("\n");
        for(i=0;i<level;i++)
            printf("  ");
        printf("%d",ptr->data);
        display(ptr->lchild,level+1);
    }
}
inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->lchild);
        printf("%d ",ptr->data);
        inorder(ptr->rchild);
    }
}
