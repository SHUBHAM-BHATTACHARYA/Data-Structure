#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}*root;
main()
{
    int choice,num;
    struct node *ptr;
    root=NULL;
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Inorder Traversal\n");
        printf("4.Preorder Traversal\n");
        printf("5.Postorder Traversal\n");
        printf("6.Find Smallest Element\n");
        printf("7.Find Largest Element\n");
        printf("8.Total Nodes\n");
        printf("9.Total External Nodes\n");
        printf("10.Total Internal Nodes\n");
        printf("11.Height\n");
        printf("12.Mirror Image\n");
        printf("13.Delete Tree\n");
        printf("14.QUIT\n");
    do
    {
        printf("\n Enter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the number to be Inserted:");
                scanf("%d",&num);
                insert(num);
                break;
            case 2:
                printf("Enter the number to be deleted:");
                scanf("%d",&num);
                del(num);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                ptr=find_smallest(root);
                printf("\n The Smallest Element is:%d",ptr->data);
                break;
            case 7:
                ptr=find_largest(root);
                printf("\n The Largest Element is:%d",ptr->data);
                break;
            case 8:
                printf("\n Total NO of Nodes=%d",total_nodes(root));
                break;
            case 9:
                printf("\n Total NO of External Nodes=%d",external_nodes(root));
                break;
            case 10:
                printf("\n Total NO of Internal Nodes=%d",internal_nodes(root));
                break;
            case 11:
                printf("\n Height=%d",height(root));
                break;
            case 12:
                root=mirror_image(root);
                break;
            case 13:
                root=delete_tree(root);
                break;
            case 14:
                printf("EXIT");
                break;
            default:
                printf("Wrong Choice\n");
        }
    }
    while(choice!=14);
}
find(int item,struct node **par,struct node **loc)
{
    struct node *ptr,*ptrsave;
    if(root==NULL)
    {
        *loc=NULL;
        *par=NULL;
        return;
    }
    if(item==root->data)
    {
        *loc=root;
        *par=NULL;
        return;
    }
    if(item<root->data)
        ptr=root->lchild;
    else
        ptr=root->rchild;
    ptrsave=root;
    while(ptr!=NULL)
    {
        if(item==ptr->data)
        {
            *loc=ptr;
            *par=ptrsave;
            return;
        }
        ptrsave=ptr;
        if(item<ptr->data)
            ptr=ptr->lchild;
        else
            ptr=ptr->rchild;
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
        printf("\n Item already present\n");
        return;
    }
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->data=item;
    tmp->lchild=NULL;
    tmp->rchild=NULL;
    if(parent==NULL)
        root=tmp;
    else
        if(item<parent->data)
        parent->lchild=tmp;
    else
        parent->rchild=tmp;
}
del(int item)
{
    struct node *parent,*location;
    if(root==NULL)
    {
        printf("\n Tree Empty");
        return;
    }
    find(item,&parent,&location);
    if(location==NULL)
    {
        printf("\n Item not present in Tree");
        return;
    }
    if(location->lchild==NULL&&location->rchild==NULL)
        case_a(parent,location);
    if(location->lchild!=NULL&&location->rchild==NULL)
        case_b(parent,location);
    if(location->lchild==NULL&&location->rchild!=NULL)
        case_b(parent,location);
    if(location->lchild!=NULL &&location->rchild!=NULL)
        case_c(parent,location);
    free(location);
}
case_a(struct node *par,struct node *loc)
{
    if(par==NULL)
        root=NULL;
    else
        if(loc==par->lchild)
                 par->lchild=NULL;
        else
            par->rchild=NULL;
}
case_b(struct node *par,struct node*loc)
{
    struct node*child;
    if(loc->lchild!=NULL)
        child=loc->lchild;
    else
         child=loc->rchild;
    if(par==NULL)
            root=child;
     else
          if(loc==par->lchild)
               par->lchild=child;
         else
             par->rchild=child;
}
case_c(struct node *par,struct node *loc)
{
    struct node *ptr,*ptrsave,*suc,*parsuc;
    ptrsave=loc;
    ptr=loc->rchild;
    while(ptr->lchild!=NULL)
    {
        ptrsave=ptr;
        ptr=ptr->lchild;
    }
    suc=ptr;
    parsuc=ptrsave;
    if(suc->lchild==NULL&&suc->rchild==NULL)
        case_a(parsuc,suc);
    else
        case_b(parsuc,suc);
    if(par==NULL)
        root=suc;
    else
        if(loc==par->lchild)
               par->lchild=suc;
         else
             par->rchild=suc;
    suc->lchild=loc->lchild;
    suc->rchild=loc->rchild;
}
preorder(struct node *ptr)
{
    if(root==NULL)
    {
        printf("\n Tree is empty");
        return;
    }
    if(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}
inorder(struct node *ptr)
{
    if(root==NULL)
       {
           printf("\n Tree is Empty");
           return;
       }
       if(ptr!=NULL)
        {
            inorder(ptr->lchild);
            printf("%d\t",ptr->data);
            inorder(ptr->rchild);
        }
}
postorder(struct node*ptr)
{
    if(root==NULL)
    {
        printf("\n Tree is empty");
        return;
    }
    if(ptr!=NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d\t",ptr->data);
    }
}
find_smallest(struct node *ptr)
{
    if(ptr==NULL || ptr->lchild==NULL)
        return ptr;
    else
        return find_smallest(ptr->lchild);
}
find_largest(struct node *ptr)
{
    if(ptr==NULL || ptr->rchild==NULL)
        return ptr;
    else
        return find_largest(ptr->rchild);
}
total_nodes(struct node *ptr)
{
    if(ptr==NULL)
        return 0;
    else
        return(total_nodes(ptr->lchild)+total_nodes(ptr->rchild)+1);
}
external_nodes(struct node *ptr)
{
    if(ptr==NULL)
        return 0;
    else if((ptr->lchild==NULL)&&(ptr->rchild==NULL))
        return 1;
    else
        return(external_nodes(ptr->lchild)+external_nodes(ptr->rchild));
}
internal_nodes(struct node*ptr)
{
    if((ptr==NULL)|| ((ptr->lchild==NULL) && (ptr->rchild==NULL)))
        return 0;
    else
        return(internal_nodes(ptr->lchild)+internal_nodes(ptr->rchild)+1);
}
height(struct node *ptr)
{
    int lheight,rheight;
    if(ptr==NULL)
        return 0;
    else
    {
        lheight=height(ptr->lchild);
        rheight=height(ptr->rchild);
        if(lheight>rheight)
            return(lheight+1);
        else
            return(rheight+1);
    }
}
mirror_image(struct node *ptr)
{
    struct node *tmp;
    if(ptr!=NULL)
    {
        mirror_image(ptr->lchild);
        mirror_image(ptr->rchild);
        tmp=ptr->lchild;
        tmp->lchild=tmp->rchild;
        ptr->rchild=tmp;
    }
}
delete_tree(struct node *ptr)
{
    if(ptr!=NULL)
    {
        delete_tree(ptr->lchild);
        delete_tree(ptr->rchild);
        free(ptr);
    }
}


