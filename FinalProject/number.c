#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

//the shared address space
int acc;
int count1=2,count2=250000,count3=500000,count4=750000;
pthread_mutex_t mylock;

void *
child_thread1 (p)
	void *p;
{
	while(count1<250000)
        {

		find1(count1);
		count1++;
        }
}//child_thread

void *
child_thread2 (p)
	void *p;
{
	while(count2<500000)
        {

	//the critical section with mutual-exclusive synchronization
	    
		find2(count2);
		count2++;
          

        }
}//child_thread
void *
child_thread3 (p)
	void *p;
{
	while(count3<750000)
        {

	//the critical section with mutual-exclusive synchronization
	    find3(count3);
		count3++;
            

        }
}//child_thread
void *
child_thread4 (p)
	void *p;
{
	while(count4<1000001)
        {

	//the critical section with mutual-exclusive synchronization
	    find4(count4);
		count4++;
            

        }
}//child_thread
main ()
{
	
	
	acc = 0;
        clock_t start, finish;
        double duration;
        
        pthread_t thread1,thread2,thread3,thread4;  
        pthread_mutex_init(&mylock,NULL);
	start = clock();
        pthread_create(&thread1,NULL,child_thread1,NULL);
        pthread_create(&thread2,NULL,child_thread2,NULL);
        pthread_create(&thread3,NULL,child_thread3,NULL);
        pthread_create(&thread4,NULL,child_thread4,NULL);
	
        pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
        pthread_join(thread3,NULL);
	
        pthread_join(thread4,NULL);
        finish = clock();   
        duration = (double)(finish - start) / CLOCKS_PER_SEC;   
        printf( "It take %f seconds\n", duration );   
	return 0;
}//main ()


void find1(int x)
{
     int i,k=sqrt(x);
     for( i=2;i<=k;i++)
     {
             if(x%i==0)
             {
                break;
             }
     }
     //if(i>sqrt(x))
     //printf("thread1 find the prime:%d\n",x);


}
void find2(int x)
{
     int i,k=sqrt(x);
    for(i=2;i<=k;i++)
     {
             if(x%i==0)
             {
                break;
             }
     }
     //if(i>sqrt(x))
     //printf("thread2 find the prime:%d\n",x);


}
void find3(int x)
{
     int i,k=sqrt(x);
    for( i=2;i<=k;i++)
     {
             if(x%i==0)
             {
                break;
             }
     }
     //if(i>sqrt(x))
     //printf("thread3 find the prime:%d\n",x);


}
void find4(int x)
{
     int i,k=sqrt(x);
    for( i=2;i<=k;i++)
     {
             if(x%i==0)
             {
                break;
             }
     }
     //if(i>sqrt(x))
    // printf("thread4 find the prime:%d\n",x);


}
















