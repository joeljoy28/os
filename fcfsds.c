#include <stdio.h>
int main() {
    // Write C code here
    int nr,rq[25],i,tm=0,sh;
    printf("\nEnter the no. of requesting processes=");
    scanf("%d",&nr);
    printf("\nEnter the requesting process=");
    for(i=0;i<nr;i++)
    scanf("%d",&rq[i]);
    printf("\nEnter initial position of disk head=");
    scanf("%d",&sh);
    for(i=0;i<nr;i++)
    if(i==0)
    {
    if(rq[i]<sh)
     tm+=sh-rq[i];
    else
     tm+=rq[i]-sh;
    }
    else
    {
     if(rq[i]<rq[i-1])
     tm+=rq[i-1]-rq[i];
    else
     tm+=rq[i]-rq[i-1];   
    }
    printf("Total track movements=%d",tm);
    return 0;
}
