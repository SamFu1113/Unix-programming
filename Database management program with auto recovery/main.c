#define _GNU_SOURCE
#define MAX_SIGNALS		30

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct person_info
{
	char name[20];
	char ID[20];
	int deposit;
	struct person_info *next;
}person_list;

typedef struct LinkedList_s {
	person_list *head;
	person_list *tail;
} LinkedList;

LinkedList *new_LinkedList ()
{
	LinkedList *this;

	this = (LinkedList*) malloc (sizeof(LinkedList));

	this->head = NULL;
	this->tail = NULL;

	return this;
}

void insert(LinkedList * this, char name[20], char ID[20], int deposit)
{	
	person_list *p;
	p = (person_list*) malloc (sizeof(person_list));
	strcpy(p->name, name);
	strcpy(p->ID, ID);
	p->deposit = deposit;
	p->next = NULL;
	if (this->head==NULL) 
	{
		this->head = p;
		this->tail = p;
	}
	else 
	{
		this->tail->next = p;
		this->tail = p;
	}	
}

void search(LinkedList *this)
{
	char name[20];
	printf("input you wanna search name\n");
	scanf("%s",name);
	
	person_list *p;
	p = this->head;
	while(p!=NULL && strcmp(p->name, name)!=0)
		p=p->next;

	if(p==NULL)
		printf("No this DATA\n");
	else
		printf("Name:%s- ID:%s- Deposit:%d\n", p->name, p->ID, p->deposit);

	return;
}

void delete(LinkedList *this)
{
	char name[20];
	printf("input you wanna delete name\n");
	scanf("%s",name);
	
	person_list *p, *q;
	p = this->head;
	q = NULL;
	while(p!=NULL && strcmp(p->name, name)!=0)
	{
		q=p;		
		p=p->next;
	}	

	if(p==NULL)
		printf("No this DATA\n");
	else
	{
		q->next=p->next;
		printf("delete this DATA\n");
	}		

	return;
}

void display(LinkedList *this)
{
	person_list *p;
	p=this->head;
	while(p!=NULL)
	{
		printf("Name:%s- ID:%s- Deposit:%d\n", p->name, p->ID, p->deposit);
		p=p->next;
	}
	return;
}

LinkedList *list;
void exit_handler()
{
	FILE *fp;
	fp = fopen ("contacts.txt", "w");
	
	person_list *p;
	p=list->head;
	while(p!=NULL)
	{
		fprintf(fp, "%s %s %d\n", p->name, p->ID, p->deposit);
		p=p->next;
	}
	fprintf(fp,"end\n");
	fclose(fp);
}

void readfile(LinkedList *this)
{
	char name[20];
	char ID[20];
	int deposit;
	FILE *fp;
	fp = fopen ("contacts.txt", "r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			fscanf(fp, "%s",name);
			if(!strcmp(name,"end")) break;
			fscanf(fp, "%s",ID);
			fscanf(fp, "%d",&deposit);	
			insert(list, name, ID, deposit);
		}
	}
	fclose(fp);
}

int main()
{
	atexit (exit_handler);
	char name[20];
	char ID[20];
	int deposit;
	int i;
	for (i=0;i<MAX_SIGNALS;i++)
		signal (i, exit);
	/*set signal for all exit*/
	list=new_LinkedList();
	readfile(list);
	int option;
	while(1)
	{
		printf("Select option\n");
		printf("1.insert\n2.search\n3.delete\n4.list all\n5.exit\n ");	
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("input your name\n");
				scanf("%s",name);
				printf("input your ID\n");
				scanf("%s",ID);
				printf("input your deposit\n");
				scanf("%d",&deposit);
				insert(list, name, ID, deposit);
				break;
			case 2:
				search(list);
				break;
			case 3:
				delete(list);
				break;
			case 4:
				display(list);
			case 5:
				return 0;
		}	
	}
	return 0;
}


















