#include <stdio.h>

int main() {
    int n,ref[25],nf,frames[25],flag,cur=0,i,j,pf=0;
    printf("\nEnter the length of reference string=");
    scanf("%d",&n);
    printf("\nEnter the reference string=");
    for(i=0;i<n;i++)
    scanf("%d",&ref[i]);
    printf("\nEnter the no. of frames=");
    scanf("%d",&nf);
    for(i=0;i<nf;i++)
     frames[i]=-1;
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
         frames[cur]=ref[i];
         cur=(cur+1)%nf;
         pf++;
     }
    }
printf("\nPage faults=%d",pf);
    return 0;
}
