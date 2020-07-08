#include<stdio.h>
int main()
{
    int a[10][3],b[10][3],c[10][3],i,j,k=1,r1,c1,r2,c2,t;
    printf("Enter the No of Rows and column:");
    scanf("%d %d",&r1,&c1);
    printf("Enter the Elements:\n");
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
        {
            scanf("%d",&t);
            if(t!=0)
            {
                a[k][0]=i;
                a[k][1]=j;
                a[k][2]=t;
                k++;
            }
        }
        a[0][0]=r1;
        a[0][1]=c1;
        a[0][2]=k-1;
     printf("1st Sparse Matrix\n");
     for(i=0;i<k;i++)
     {
         for(j=0;j<3;j++)
             printf("%d\t",a[i][j]);
         printf("\n");
     }
     k=1;
     printf("Enter the No of Rows and column:");
    scanf("%d %d",&r2,&c2);
    printf("Enter the Elements:\n");
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
        {
            scanf("%d",&t);
            if(t!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=t;
                k++;
            }
        }
        b[0][0]=r2;
        b[0][1]=c2;
        b[0][2]=k-1;
     printf("2nd Sparse Matrix\n");
     for(i=0;i<k;i++)
     {
         for(j=0;j<3;j++)
              printf("%d\t",b[i][j]);
         printf("\n");
     }
     int k1,k2,k3,tot1,tot2;
     if(a[0][0]!=b[0][0]||a[0][1]!=b[0][1])
        printf("invalid matrix size");
     else
     {
         tot1=a[0][2];
         tot2=b[0][2];
         k1=k2=k3=1;
         while(k1<=tot1&&k2<=tot2)
         {
             if(a[k1][0]<b[k2][0])
             {
                 c[k3][0]=a[k1][0];
                 c[k3][1]=a[k1][1];
                 c[k3][2]=a[k1][2];
                 k3++;
                 k1++;
             }
             else
                if(a[k1][0]>b[k2][0])
                {
                    c[k3][0]=b[k2][0];
                    c[k3][1]=b[k2][1];
                    c[k3][2]=b[k2][2];
                    k3++;
                    k2++;
                }
                else if(a[k1][0]==b[k2][0])
                {
                    if(a[k1][1]<b[k2][1])
                    {
                        c[k3][0]=a[k1][0];
                        c[k3][1]=a[k1][1];
                        c[k3][2]=a[k1][2];
                        k3++;
                        k1++;
                    }
                    else
                        if(a[k1][1]>b[k2][1])
                        {
                            c[k3][0]=b[k2][0];
                            c[k3][1]=b[k2][1];
                            c[k3][2]=b[k2][2];
                            k3++;
                            k2++;
                        }
                        else
                        {
                            c[k3][0]=b[k2][0];
                            c[k3][1]=b[k2][1];
                            c[k3][2]=b[k2][2]+a[k1][2];
                            k3++;
                            k2++;
                            k1++;
                        }
                }
         }
         while(k1<=tot1)
         {
                c[k3][0]=a[k1][0];
                c[k3][1]=a[k1][1];
                c[k3][2]=a[k1][2];
                k3++;
                k1++;
         }
         while(k2<=tot2)
         {
                c[k3][0]=b[k2][0];
                c[k3][1]=b[k2][1];
                c[k3][2]=b[k2][2];
                k3++;
                k2++;
          }
          c[0][0]=a[0][0];
          c[0][1]=a[0][1];
          c[0][2]=k3-1;
          printf("Addition Sparse Matrix\n");
          for(i=0;i<k3;i++)
          {
              for(j=0;j<3;j++)
                  printf("%d\t",c[i][j]);
               printf("\n");
          }
       }
}
