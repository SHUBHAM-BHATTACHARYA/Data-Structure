#include<stdio.h>
#define MAX 20
struct edge
{
    int u;
    int v;
    int weight;
    struct edge *link;
}*front=NULL;
int adj[MAX][MAX];
int father[MAX];
struct edge tree[MAX];
int n;
int wt_tree=0;
int count=0;
int create_graph();
void make_tree();
void insert_tree(int i,int j,int wt);
void insert_pqueue(int i,int j,int wt);
struct edge *del_pqueue();
int main()
{
    int i;
    create_graph();
    make_tree();
    printf("Edges to be included in Spanning Tree are:\n");
    for(i=1;i<=count;i++)
    {
        printf("%d  ",tree[i].u);
        printf("%d\n",tree[i].v);
    }
    printf("Weight of this Minimum Spanning Tree is:%d\n",wt_tree);
}
create_graph()
{
    int i,max_edges,origin,destin,wt;
    printf("Enter No of Nodes:");
    scanf("%d",&n);
    max_edges=n*(n-1)/2;
    for(i=1;i<=max_edges;i++)
    {
        printf("Enter Edge %d(0 0 to quit):",i);
        scanf("%d %d",&origin,&destin);
        if((origin==0)&&(destin==0))
                break;
        printf("Enter Weight for this Edge:");
        scanf("%d",&wt);
        if(origin>n||destin>n||origin<=0||destin<=0)
        {
            printf("Invalid Edge!\n");
            i--;
        }
        else
            insert_pqueue(origin,destin,wt);
    }
    if(i<n-1)
    {
        printf("Spanning Tree is not Possible\n");
        exit(1);
    }
}
void make_tree()
{
    struct edge *tmp;
    int node1,node2,root_n1,root_n2;
    while(count<n-1)
    {
        tmp=del_pqueue();
        node1=tmp->u;
        node2=tmp->v;
        printf("n1=%d",node1);
        printf("n2=%d",node2);
        while(node1>0)
        {
            root_n1=node1;
            node1=father[node1];
        }
        while(node2>0)
        {
            root_n2=node2;
            node2=father[node2];
        }
        printf("root n1=%d ",root_n1);
        printf("root n2=%d\n",root_n2);
        if(root_n1!=root_n2)
        {
            insert_tree(tmp->u,tmp->v,tmp->weight);
            wt_tree=wt_tree+tmp->weight;
            father[root_n2]=root_n1;
        }
    }
}
void insert_tree(int i,int j,int wt)
{
    printf("This Edge Inserted in the Spanning Tree\n");
    count++;
    tree[count].u=i;
    tree[count].v=j;
    tree[count].weight=wt;
}
void insert_pqueue(int i,int j,int wt)
{
    struct edge *tmp,*q;
    tmp=(struct edge*)malloc(sizeof(struct edge));
    tmp->u=i;
    tmp->v=j;
    tmp->weight=wt;
    if(front==NULL||tmp->weight<front->weight)
    {
        tmp->link=front;
        front=tmp;
    }
    else
    {
        q=front;
        while(q->link!=NULL && q->link->weight <= tmp->weight)
            q=q->link;
        tmp->link=q->link;
        q->link=tmp;
        if(q->link==NULL)
            tmp->link=NULL;
    }
}
struct edge *del_pqueue()
{
    struct edge *tmp;
    tmp=front;
    printf("Edge Processed is:%d->%d %d\n",tmp->u,tmp->v,tmp->weight);
    front=front->link;
    return tmp;
}
