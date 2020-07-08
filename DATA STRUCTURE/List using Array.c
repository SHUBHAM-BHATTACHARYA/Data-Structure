#include<stdio.h>
#define max 20
int arr[max];
int n;
int main()
{
    int choice,item,pos;
    printf("1.Input List\n");
    printf("2.Insert\n");
    printf("3.Search\n");
    printf("4.Delete\n");
    printf("5.Display\n");
    printf("6.Quit\n");
    do
    {
        printf("Enter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the Number of Elements to be Entered:");
            scanf("%d",&n);
            input(n);
            break;
        case 2:
            insert();
            break;
        case 3:
            printf("Enter the Element to be Searched:");
            scanf("%d",&item);
            pos=search(item);
            if(pos>=1)
                printf("%d found at Position %d\n",item,pos);
            else
                printf("Element not Found\n");
            break;
        case 4:
            del();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("EXIT\n");
            break;
        default:
            printf("Wrong Choice\n");
        }
    }
    while(choice!=6);
}
input()
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Input Value for Element %d:",i+1);
        scanf("%d",&arr[i]);
    }
}
int search(int item)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(item==arr[i])
            return(i+1);
    }
    return(0);
}
insert()
{
    int temp,item,position;
    if(n==max)
    {
        printf("List Overflow\n");
        return;
    }
    printf("Enter Position for Insertion:");
    scanf("%d",&position);
    printf("Enter the Value:");
    scanf("%d",&item);
    if(position>n+1)
    {
        printf("Enter Position less than or equal to %d\n",n+1);
        return;
    }
    if(position==n+1)
    {
        arr[n]=item;
        n=n+1;
        return;
    }
    temp=n-1;
    while(temp>=position-1)
    {
        arr[temp+1]=arr[temp];
        temp--;
    }
    arr[position-1]=item;
    n=n+1;
}
del()
{
    int temp,position,item;
    if(n==0)
    {
        printf("List Underflow\n");
        return;
    }
    printf("Enter the Element to be Deleted:");
    scanf("%d",&item);
    if(item==arr[n-1])
    {
        n=n-1;
        return;
    }
    position=search(item);
    if(position==0)
    {
        printf("Element not Present in Array\n");
        return;
    }
    temp=position-1;
    while(temp<=n-1)
    {
        arr[temp]=arr[temp+1];
        temp++;
    }
    n=n-1;
}
display()
{
    int i;
    if(n==0)
    {
        printf("List is Empty\n");
        return;
    }
    for(i=0;i<n;i++)
        printf("Value at Position %d:%d\n",i+1,arr[i]);
}
