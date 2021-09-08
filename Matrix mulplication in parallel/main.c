#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//the shared address space
int thracc,seqacc;
int count;
int size = 10000;
int thrsize = 5;
pthread_mutex_t mylock;

struct dataset
{
	int A;
	int B;
};

void *
child_thread (p)
	void *p;
{
	struct dataset *data = (struct dataset *)p;
	
	int temp = ((*data).A) * ((*data).B);
	pthread_mutex_lock (&mylock);
		thracc += temp;
	pthread_mutex_unlock (&mylock);
}

int main ()
{
	clock_t total = clock();
	srand(time(0));
	
	int i;
	double thrextime,seqextime;
	struct dataset data[size];
	
	for (i=0;i<size;i++)
	{
		data[i].A = rand()%100+1;
		data[i].B = rand()%100+1;
	}

	pthread_t thread_id[4];

	thracc = 0;
	seqacc = 0;
	count = 0;

	pthread_mutex_init (&mylock, NULL);
	
	clock_t begin = clock();
	for (i=0;i<size;i++)
	{
		pthread_create (&(thread_id[i%thrsize]), NULL, child_thread, &(data[i]));
		pthread_join(thread_id[i%thrsize], NULL);
	}	
	clock_t end = clock();
	thrextime = (double)(end - begin) / CLOCKS_PER_SEC;
	
	begin = clock();
	for (i=0;i<size;i++)
		seqacc += (data[i].A)*(data[i].B);
	end = clock();
	seqextime = (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf ("Seqence acc = %d\n", seqacc);
	printf ("Seqence time = %.20lf\n", seqextime);
	
	printf ("Thread acc = %d\n", thracc);
	printf ("Thread time = %.20lf\n", thrextime);

	//printf ("Total time = %.20lf\n", (double)(total - clock()) / CLOCKS_PER_SEC);
	return 0;
}
