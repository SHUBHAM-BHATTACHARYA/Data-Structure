#include<stdio.h>
insert_node(char);
delete_node(char);
delnode_edge(char);
insert_edge(char,char);
del_edge(char,char);
struct node *find(char item);
struct node
{
    struct node *next;
    char name;
    struct edge *adj;
}*start=NULL;
struct edge
{
    char dest;
    struct edge *link;
};
int main()
{
    int choice;
    int node,origin,destin;
    printf("..............OPERATION ON DIRECTED GRAPH................\n");
    printf("1.Insert a node\n");
    printf("2.Insert an edge\n");
    printf("3.Delete a node\n");
    printf("4.Delete an edge\n");
    printf("5.Display\n");
    printf("6.Exit\n");
    do
    {
        printf("Enter your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter a Node to be Inserted:");
            fflush(stdin);
            scanf("%c",&node);
            insert_node(node);
            break;
        case 2:
            printf("Enter an edge to be Inserted:");
            fflush(stdin);
            scanf("%c %c",&origin,&destin);
            insert_edge(origin,destin);
            break;
        case 3:
            printf("Enter a node to be Deleted:");
            fflush(stdin);
            scanf("%c",&node);
            delete_node(node);
            break;
        case 4:
            printf("Enter an edge to be deleted:");
            fflush(stdin);
            scanf("%c %c",&origin,&destin);
            del_edge(origin,destin);
            delnode_edge(node);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("EXIT");
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    }
    while(choice!=6);
}
insert_node(char node_name)
{
    struct node *tmp,*ptr;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->name=node_name;
    tmp->next=NULL;
    tmp->adj=NULL;
    if(start==NULL)
    {
        start=tmp;
        return;
    }
    ptr=start;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    ptr->next=tmp;
}
delete_node(char u)
{
    struct node *tmp,*q;
    if(start->name==u)
    {
        tmp=start;
        start=start->next;
        free(tmp);
        return;
    }
    q=start;
    while(q->next->next!=NULL)
    {
        if(q->next->name==u)
        {
            tmp=q->next;
            q->next=tmp->next;
            free(tmp);
            return;
        }
        q=q->next;
    }
    if(q->next->name==u)
    {
        tmp=q->next;
        free(tmp);
        q->next=NULL;
    }
}
delnode_edge(char u)
{
    struct node *ptr;
    struct edge *q,*start_edge,*tmp;
    ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->adj->dest==u)
        {
            tmp=ptr->adj;
            ptr->adj=ptr->adj->link;
            free(tmp);
            continue;
        }
        q=ptr->adj;
        while(q->link->link!=NULL)
        {
            if(q->link->dest==u)
            {
                tmp=q->link;
                q->link=tmp->link;
                free(tmp);
                continue;
            }
            q=q->link;
        }
        if(q->link->dest==u)
        {
            tmp=q->link;
            free(tmp);
            q->link=NULL;
        }
        ptr=ptr->next;
    }
}
insert_edge(char u,char v)
{
    struct node *locu,*locv;
    struct edge *ptr,*tmp;
    locu=find(u);
    locv=find(v);
    if(locu==NULL)
    {
        printf("Source Node not present,first insert node %c\n",u);
        return;
    }
    if(locv==NULL)
    {
        printf("Destination Node not present,first insert node %c\n",v);
        return;
    }
    tmp=(struct edge*)malloc(sizeof(struct edge));
    tmp->dest=v;
    tmp->link=NULL;
    if(locu->adj==NULL)
    {
        locu->adj=tmp;
        return;
    }
    ptr=locu->adj;
    while(ptr->link!=NULL)
        ptr=ptr->link;
    ptr->link=tmp;
}
struct node *find(char item)
{
    struct node *ptr,*loc;
    ptr=start;
    while(ptr!=NULL)
    {
        if(item==ptr->name)
        {
            loc=ptr;
            return loc;
        }
        else
            ptr=ptr->next;
    }
    loc=NULL;
    return loc;
}
del_edge(char u,char v)
{
    struct node *locu,*locv;
    struct edge *ptr,*tmp,*q;
    locu=find(u);
    if(locu==NULL)
    {
        printf("Source node not present\n");
        return;
    }
    if(locu->adj->dest==v)
    {
        tmp=locu->adj;
        locu->adj=locu->adj->link;
        free(tmp);
        return;
    }
    q=locu->adj;
    while(q->link->link!=NULL)
    {
        if(q->link->dest==v)
        {
            tmp=q->link;
            q->link=tmp->link;
            free(tmp);
            return;
        }
        q=q->link;
    }
    if(q->link->dest==v)
    {
        tmp=q->link;
        free(tmp);
        q->link=NULL;
            return;
    }
    printf("The Edge not Present in the Graph\n");
}
display()
{
    struct node *ptr;
    struct edge *q;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%c",ptr->name);
        q=ptr->adj;
        while(q!=NULL)
        {
            printf("%c",q->dest);
            q=q->link;
        }
        printf("\n");
        ptr=ptr->next;
    }
}
