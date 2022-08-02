#include <stdio.h>
int main()
{ 
    int np,nb,i,j,p[25],b[25],allocated[25];
    printf("\nEnter the no. of memory blocks=");
    scanf("%d",&nb);
    printf("\nEnter the memory blocks=");
    for(i=0;i<nb;i++)
     scanf("%d",&b[i]);
    printf("\nEnter the no. of processes=");
    scanf("%d",&np);
    printf("\nEnter the processes=");
    for(i=0;i<np;i++)
    scanf("%d",&p[i]);
    for(i=0;i<np;i++)
    allocated[i]=-1;
    for(i=0;i<np;i++)
    {
        for(j=0;j<nb;j++)
         if(b[j]>=p[i])
         {
             b[j]-=p[i];
             allocated[i]=j;
             break;
         }
    }
    for(i=0;i<np;i++)
 {
    if(allocated[i]!=-1)
    {
        printf("\nProcess %d is allocated in block %d",i,allocated[i]);
    }
    else
    printf("\nProcess %d is not allocated",i);
}
    return 0;
}
