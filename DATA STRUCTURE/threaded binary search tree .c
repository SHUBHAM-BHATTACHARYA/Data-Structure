#include<stdio.h>
#include<malloc.h>
#define infinity 9999
typedef enum{thread,link}boolean;
struct node *in_succ(struct node *p);
struct node *in_pred(struct node *p);
struct node
{
    struct node *left_ptr;
    boolean left;
    int data;
    boolean right;
    struct node *right_ptr;
}*head=NULL;
main()
{
    int choice,num;
    insert_head();
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Inorder Traversal\n");
    printf("4.Preorder Traversal\n");
    printf("5.Quit\n");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the No to be inserted:");
                scanf("%d",&num);
                insert(num);
                break;
            case 2:
                printf("\nEnter the No to be deleted:");
                scanf("%d",&num);
                del(num);
                break;
            case 3:
                inorder();
                break;
            case 4:
                preorder();
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
insert_head()
{
    struct node*tmp;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=infinity;
    head->left=thread;
    head->left_ptr=head;
    head->right=link;
    head->right_ptr=head;
}
find(int item,struct node **par,struct node **loc)
{
    struct node *ptr,*ptrsave;
    if(head->left_ptr==head)
    {
        *loc=NULL;
        *par=head;
        return;
    }
    if(item==head->left_ptr->data)
    {
        *loc=head->left_ptr;
        *par=head;
        return;
    }
    ptr=head->left_ptr;
    while(ptr!=head)
    {
        ptrsave=ptr;
        if(item<ptr->data)
        {
            if(ptr->left==link)
                ptr=ptr->left_ptr;
            else
                break;
        }
        else
            if(item>ptr->data)
        {
            if(ptr->right==link)
                ptr=ptr->right_ptr;
            else
                break;
        }
        if(item==ptr->data)
        {
            *loc=ptr;
            *par=ptrsave;
            return;
        }
    }
    *loc=NULL;
    *par=ptrsave;
}
insert(int item)
{
    struct node *tmp,*parent,*location;
    find(item,&parent,&location);
    if(location!=NULL)
    {
        printf("Item already present");
        return;
    }
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->data=item;
    tmp->left=thread;
    tmp->right=thread;
    if(parent==head)
    {
        head->left=link;
        head->left_ptr=tmp;
        tmp->left_ptr=head;
        tmp->right_ptr=head;
    }
    else
        if(item < parent->data)
        {
             tmp->left_ptr=parent->left_ptr;
             tmp->right_ptr=parent;
             parent->left=link;
             parent->left_ptr=tmp;
        }
        else
        {
            tmp->left_ptr=parent;
            tmp->right_ptr=parent->right_ptr;
            parent->right=link;
            parent->right_ptr=tmp;
        }
}
del(int item)
{
    struct node *parent,*location;
    if(head==NULL)
    {
        printf("Tree empty");
        return;
    }
    find(item,&parent,&location);
    if(location==NULL)
    {
        printf("Item not present in Tree");
        return;
    }
    if(location->left==thread && location->right==thread)
        case_a(parent,location);
    if(location->left==link && location->right==thread)
        case_b(parent,location);
    if(location->left==thread && location->right==link)
        case_b(parent,location);
    if(location->left==link && location->right==link)
        case_c(parent,location);
}
case_a(struct node *par,struct node*loc)
{
    if(par==head)
    {
        head->left==thread;
        head->left_ptr=head;
    }
    else
        if(loc==par->left_ptr)
    {
        par->left=thread;
        par->left_ptr=loc->left_ptr;
    }
    else
    {
        par->right=thread;
        par->right_ptr=loc->right_ptr;
    }
    free(loc);
}
case_b(struct node *par,struct node *loc)
{
    struct node *child,*s,*p;
    if(loc->left==link)
        child=loc->left_ptr;
    else
        child=loc->right_ptr;
    if(par==head)
        head->left_ptr=child;
    else
        if(loc==par->left_ptr)
                par->left_ptr=child;
        else
            par->right_ptr=child;
    s=in_succ(loc);
    p=in_pred(loc);
    if(loc->right==link)
        s->left_ptr=p;
    else
    {
        if(loc->left==link)
            p->right_ptr=s;
    }
    free(loc);
}
case_c(struct node*par,struct node*loc)
{
    struct node *ptr,*ptrsave,*suc,*parsuc,*s,*p;
    ptrsave=loc;
    ptr=loc->right_ptr;
    while(ptr->left==link)
    {
        ptrsave=ptr;
        ptr=ptr->left_ptr;
    }
    suc=ptr;
    parsuc=ptrsave;
    loc->data=suc->data;
    if(suc->left==thread && suc->right==thread)
        case_a(parsuc,suc);
    else
        case_b(parsuc,suc);
}
struct node *in_succ(struct node *ptr)
{
    struct node *succ;
    if(ptr->right==thread)
        succ=ptr->right_ptr;
    else
    {
        ptr=ptr->right_ptr;
        while(ptr->left==link)
            ptr=ptr->left_ptr;
        succ=ptr;
    }
    return succ;
}
struct node *in_pred(struct node *ptr)
{
    struct node *pred;
    if(ptr->left==thread)
        pred=ptr->left_ptr;
    else
    {
        ptr=ptr->left_ptr;
        while(ptr->right==link)
            ptr=ptr->right_ptr;
        pred=ptr;
    }
    return pred;
}
inorder()
{
    struct node *ptr;
    if(head->left_ptr==head)
    {
        printf("Tree is Empty");
        return;
    }
    ptr=head->left_ptr;
    while(ptr->left==link)
        ptr=ptr->left_ptr;
    printf("%d\t",ptr->data);
    while(1)
    {
        ptr=in_succ(ptr);
        if(ptr==head)
            break;
        printf("%d\t",ptr->data);
    }
}
preorder()
{
    struct node *ptr;
    if(head->left_ptr==head)
    {
        printf("Tree is Empty");
        return;
    }
    ptr=head->left_ptr;
    while(ptr!=head)
    {
        printf("%d\t",ptr->data);
        if(ptr->left==link)
            ptr=ptr->left_ptr;
        else
            if(ptr->right_ptr==link)
                 ptr=ptr->right_ptr;
             else
             {
                 while(ptr!=head && ptr->right==thread)
                    ptr=ptr->right_ptr;
                 if(ptr!=head)
                    ptr=ptr->right_ptr;
             }
    }
}
