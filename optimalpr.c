#include<stdio.h>
void main()
{
    int n,ref[25],nf,frames[25],i,flag,j,p,z,pf=0,next[25],k;
    printf("\nEnter the length of reference string=");
    scanf("%d",&n);
    printf("\nEnter the reference string=");
    for(i=0;i<n;i++)
     scanf("%d",&ref[i]);
    printf("\nEnter the frame size=");
    scanf("%d",&nf);
    for(i=0;i<nf;i++)
    {
        frames[i]=-1;
        next[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        flag=0;
      for(j=0;j<nf;j++)
        if(ref[i]==frames[j])
         {
             flag=1;
             break;
         }
      if(flag==0)
      {
         for(p=0;p<nf;p++)
           for(k=i;k<n;k++)
           {
             next[p]=100;
            if(ref[k]==frames[p])
              {
              next[p]=k-i;
              break;
              }
           }
        int max=0,opti;
         for(z=0;z<nf;z++)
           if(next[z]>max)
           {
               max=next[z];
               opti=z;
           }
    frames[opti]=ref[i];
     pf++;
      }
    }
printf("\nPage fault=%d",pf);
}
