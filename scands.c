#include<stdio.h>
#include<stdlib.h>
int main() {
 int nc,nr,rq[25],ch,i,tr[25],flag,pr,tt=0,j;
 printf("\nEnter the no. of cylinders=");
 scanf("%d",&nc);
 printf("\nEnter the no. of requests=");
 scanf("%d",&nr);
 printf("\nEnter the request queue=");
 for(i=0;i<nr;i++)
   scanf("%d",&rq[i]);
 printf("\nEnter current position=");
 scanf("%d",&ch);
 printf("\nEnter previous request=");
 scanf("%d",&pr);
 for(i=0;i<nr-1;i++)
   for(j=0;j<nr-1-i;j++)
     if(rq[j]>rq[j+1])
     {
         int temp=rq[j];
         rq[j]=rq[j+1];
         rq[j+1]=temp;
     }
if(pr<ch)
    {
        tt+=(ch)+rq[nr-1];
    }
    else
    {
        tt+=(nc-1-ch)+(nc-1-rq[0]);
    }
printf("\nTotal track movements=%d",tt);
}
