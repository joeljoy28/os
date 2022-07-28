#include<stdio.h>
void main()
{
    int n,ref[25],nf,frames[25],i,flag,j,p,z,pf=0,next[25],k,w;
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
         if(i<nf)
         {
             for(w=0;w<nf;w++)
          {
              if(frames[w]==-1)
            {    frames[w]=ref[i];
                pf++;
                break; }
         }
         }
    else
       {
         for(p=0;p<nf;p++)
           for(k=i;k>=0;k--)
            if(ref[k]==frames[p])
              {
              next[p]=i-k;
              break;
              }
        int max=0,lrui;
         for(z=0;z<nf;z++)
           if(next[z]>max)
           {
               max=next[z];
               lrui=z;
           }
    frames[lrui]=ref[i];
     pf++;
      }
      }
    }
printf("\nPage fault=%d",pf);
}
