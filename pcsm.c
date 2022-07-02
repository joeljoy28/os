#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<time.h>
sem_t mutex,full,empty;
int buffer[5],get=0,item=0,gitem,put=0,pro[20],con[20],n;
void *producer(void *arg)
{
     sem_wait(&empty);
     sem_wait(&mutex);
     buffer[put%n]=item;
     item++;
     printf("producer%d produces %d item buffered[%d]:%d\n",(*(int*)arg),buffer[put%n],put%n,item);
     put++;
     sem_post(&mutex);
     sem_post(&full);
     sleep(1);
}
void *consumer(void *arg)
{

      sem_wait(&full);
      sem_wait(&mutex);
      gitem=buffer[get%n];
      printf("consumer%d consumes %d item buffered[%d]:%d\n",(*(int *)arg),gitem,get%n,gitem);
      get++;
      sem_post(&mutex);
      sem_post(&empty);
      sleep(2);
    
}
void main()
{
    int p,c,j,k;
    pthread_t a[10],b[10];
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    printf("Enter the size of buffer=");
    scanf("%d",&n);
    sem_init(&empty,0,n);
    printf("\nEnter the no. of producers=");
    scanf("%d",&p);
    printf("\nEnter the no. of consumers=");
    scanf("%d",&c);
    for(j=0;j<p;j++)
    {
        pro[j]=j;
        pthread_create(&a[j],NULL,producer,&pro[j]);
    }
    for(k=0;k<c;k++)
    {
        con[k]=k;
        pthread_create(&b[k],NULL,consumer,&con[k]);
    }
    for(j=0;j<p;j++)
    pthread_join(a[j],NULL);
    for(k=0;k<c;k++)
    pthread_join(b[k],NULL);
}
