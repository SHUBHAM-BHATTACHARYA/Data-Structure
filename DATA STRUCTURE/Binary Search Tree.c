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
    root=NULL;
    do
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("Inorder Traversal\n");
        printf("Preorder Traversal\n");
        printf("Postorder Traversal\n");
        printf("Quit\n");
        printf("Enter your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the No. to be inserted:");
            scanf("%d",&num);
            insert(num);
            break;
        case 2:
            printf("Enter the NO. to be deleted:");
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
            printf("EXIT");
        default:
            printf("Wrong choice\n");
        }
    }
    while(choice!=6);
}
