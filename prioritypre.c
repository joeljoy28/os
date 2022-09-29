#include <stdio.h>
int main()
{
    int n,i,j,bt[25],rb[25],wt[25],tat[25],p[25],temp,at[25],time,count=0,ct=0;
    float awt=0,atat=0;
    printf("\nEnter no. of processes=");
    scanf("%d",&n);
    printf("\nEnter the arrival time of processes=");
    for(i=0;i<n;i++)
     scanf("%d",&at[i]);
    printf("\nEnter the burst time of processes=");
    for(i=0;i<n;i++)
     scanf("%d",&bt[i]);
    printf("\nEnter priority of processes=");
    for(i=0;i<n;i++)
     scanf("%d",&p[i]);
    for(i=0;i<n;i++)
     rb[i]=bt[i];
     p[24]=10000;
    for(time=0;count!=n;time++)
    {
  int   largest=24;
     for(i=0;i<n;i++)
     {
         if(at[i]<=time && p[i]<p[largest] && rb[i]>0)
         {
             largest=i;
         }
     }
    rb[largest]--;
    if(rb[largest]==0)
    {
        count++;
        ct=time+1;
        atat+=ct-at[largest];
        awt+=ct-at[largest]-bt[largest];
    }
    }
    awt/=n;
    atat/=n;
 printf("\nAverage waiting time=%f",awt);
 printf("\nAverage turn around time=%f",atat);
    return 0;
}
