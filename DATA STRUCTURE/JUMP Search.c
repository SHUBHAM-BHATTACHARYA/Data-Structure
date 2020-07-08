#include<stdio.h>
int main()
{
    int a[20],n,i,j,item,p,f=0,pos;
    printf("Enter the No of Elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the Element to be searched: ");
    scanf("%d",&item);
    p=(n*n);
    for(i=0;i<p;i++)
    {
       if(a[i*p] < item < a[(i+1)*p])
       {
           for(j=(i*p);j<((i+1)*p);j++)
           {
                 if(item==a[j])
                 {
                     f=1;
                     pos=j;
                     break;
                 }
           }
       }
       if(f==1)
          break;
    }
    if(f==1)
        printf("%d found at position %d\n",item,pos+1);
    else
        printf("%d not found in array\n",item);
}
