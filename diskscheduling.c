#include<stdio.h>
#include<stdlib.h>
void fcfs(int n,int head,int a[])
{int i,temp,seek_time=0;
	printf("\nFCFS");
	printf("\n***");
	
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			temp= head-a[0];
			if(temp<0)
				seek_time= -1*temp;
			else
				seek_time=temp;
		}
		else
		{head=a[i];
			temp=a[i]-a[i-1];
			if(temp<0)
			{
				seek_time=seek_time+ (-1*temp);
			}
			else
			{
				seek_time= seek_time+temp;
			}
		}
	}
	printf("\nTotal seek time:%d",seek_time);
	
}
void scan(int n,int a[])
{
	int i,j,temp,seek_time=0,loc,head;
	printf("\nEnter the previous disk head:");
	scanf("%d",&head);
	a[n+1]=head;
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<=n+1;i++)
	{	
		if(a[i]==head)
			loc=i;
		printf("\t%d",a[i]);
	}
	for(i=loc;i>0;i--)
	{	head=i;
		temp= a[i]-a[i-1];
		if(temp<0)
			seek_time= seek_time+ (-1*temp);
		else	
			seek_time= seek_time+temp;
	}
	head=0;
	for(i=loc+1;i<=n+1;i++)
	{
		temp=a[i]-a[head];
		head=i;
		if(temp<0)
			seek_time= seek_time+ (-1*temp);
		else	
			seek_time= seek_time+ temp;
	}
	printf("\nTotal seek time:%d",seek_time);
}
void cscan(int n,int a[])
{
	int i,j,temp,seek_time=0,loc,head,flag=0,loc1;
	printf("\nEnter the previous disk head:");
	scanf("%d",&head);
	if(head!=199)
	{a[n+1]=head; a[n+2]=199; flag=1;}
	if(flag==0)
	{
		a[n+1]=199;
	}
	printf("%d",a[n+2]);
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<=n+2;i++)
	{	
		if(a[i]==head)
			loc=i;
		if(a[i]==199)
			loc1=i;
		printf("\t%d",a[i]);
	}
	for(i=loc;i>0;i--)
	{	head=i;
		temp= a[i]-a[i-1];
		printf("\n%d - %d",a[i],a[i-1]);
		if(temp<0)
			seek_time= seek_time+ (-1*temp);
		else	
			seek_time= seek_time+temp;
	}
	head=0;
	//seek_time+=199;
	for(i=loc1;i>loc;i--)
	{
		temp=a[i]-a[head];
		head=i;
		printf("\n%d - %d",a[i],a[i-1]);
		if(temp<0)
			seek_time= seek_time+ (-1*temp);
		else	
			seek_time= seek_time+ temp;
	}
	printf("\nTotal seek time:%d",seek_time);
}
int main()
{
	int i,cy,n,a[20],b[20],c[20],d[20],ele,head,choice;
	printf("\nEnter the number of cylinders:");
	scanf("%d",&cy);
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i=0;i<n;i++)
	{	printf("\n %d:",i+1);
		scanf("%d",&ele);
		if(ele<=200 && ele>0)
		{
			a[i]=ele;
		}
		else	
		{
			do{
				printf("\nNot valid ,Enter again:");
				scanf("%d",&ele);
				
			}while(ele>200);
		}
	}
	printf("\nEnter the disk head:");
	scanf("%d",&head);
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
		c[i]=a[i];
	}
	do{
		printf("\n1.FCFS");
		printf("\n2.SCAN");
		printf("\n3.CSCAN");
		printf("\n0. EXIT");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: exit(1);
			case 1: for(i=0;i<n;i++)
					{
						b[i]=a[i];
					}
					fcfs(n,head,b);
					break;
			case 2: c[0]=0;
					for(i=0;i<n;i++)
					{
						c[i+1]=a[i];
					}
					scan(n,c);
					break;
			case 3: d[0]=0;
					for(i=0;i<n;i++)
					{
						d[i+1]=a[i];
					}
					cscan(n,d);
					break;
				
			default: printf("Invalid choice!!");
		}
	}while(choice!=0);
	
	return 0;
}
