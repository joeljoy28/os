#include <stdio.h>
struct sector
{
    int used;
}s[25];
int main() {
    int sno,i,fno,nfree,nblocks,start,cur,j,k;
    printf("\nEnter the no of sectors in the disk=");
    scanf("%d",&sno);
    for(i=0;i<sno;i++)
    s[i].used=0;
    printf("\nEnter the no of files=");
    scanf("%d",&fno);
    nfree=sno;
    for(i=0;i<fno;i++)
    {
        if(nfree==0)
        {
            printf("\nAll sectors are full");
            break;
        }
    do
    {
     printf("\nEnter starting position=");
     scanf("%d",&start);
     if(s[start].used)
     printf("\nSector is occupied");
    }
    while(s[start].used);
    printf("\nEnter the no. of blocks in the file=");
    scanf("%d",&nblocks);
    if(nfree<nblocks)
      printf("\nNot possible");
    else
    {
     cur=start;
     int flag=0;
     for(j=0;j<nblocks;j++)
     {
     if(s[cur].used)
     {    flag=1;
        break;}
     s[cur].used=1;    
     cur=(cur+1)%sno;
    }
    if(flag==0)
     {
         for(k=0;k<nblocks;k++)
          printf("%d ",start+k);
          nfree-=nblocks;
     }
    else
    {
        printf("\nNot possilbe");
    }
    }
    }
    return 0;
}
