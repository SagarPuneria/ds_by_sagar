#include<stdio.h>
#include<string.h>	
#include<stdlib.h>
enum {CHAR=1,STRING,FLOAT,INT}op;

typedef struct node 
{

	int type;
	void *data;
	struct node *next;
}NODE;
struct node *head=NULL;
void insert_n(int ele)
{
	NODE *curr=head,*temp=NULL;int * p;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->type=4;
	temp->data=(int *)malloc(sizeof(int));
	p=temp->data;
	*p=ele;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=temp;
}
void insert_c(char ele)
{
	NODE *temp=NULL,*curr=head;
	char *p;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->type=1;
	temp->data=(char *)malloc(sizeof(char));
	p=temp->data;
	*p=ele;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=temp;
}
void insert_s(char *ele)
{
	NODE *temp=NULL,*curr=head;
	char *q;
	temp=(NODE *)malloc(sizeof(NODE));
	temp->type=2;
	temp->data=(char *)malloc(strlen(ele)*sizeof(char));
	q=temp->data;
	strcpy(q,(char *)ele);
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=temp;
}
insert(void *ele,int op)
{
	NODE *curr,*temp;
	char *p;
	char *q;
	int *n;
	float *f;
	curr=head;
	temp=(NODE *)malloc(sizeof(NODE));
	switch(op)
	{
		case CHAR:temp->type=CHAR;
			temp->data=(char *)malloc(sizeof(char));
			p=temp->data;
			*p=*((char *)ele);
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				return;
			}
			while(curr->next!=NULL)
				curr=curr->next;
			curr->next=temp;
			break;
		case STRING:temp->type=STRING;
			temp->data=(char *)malloc(strlen(ele)*sizeof(char));
			q=temp->data;
			strcpy(q,(char *)ele);
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				return;
			}
			while(curr->next!=NULL)
				curr=curr->next;
			curr->next=temp;
			break;
		case FLOAT:temp->type=FLOAT;
			temp->data=(float *)malloc(sizeof(float));
			f=temp->data;
			*f=*((float *)ele);
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				return;
			}
			while(curr->next!=NULL)
				curr=curr->next;
			curr->next=temp;
			break;
		case INT:temp->type=INT;
			temp->data=(int *)malloc(sizeof(int));
			n=temp->data;
			*n=*((int *)ele);
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				return;
			}
			while(curr->next!=NULL)
				curr=curr->next;
			curr->next=temp;
			break;
	}			
}			
void display()
{
	NODE *curr;
	curr=head;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("list is\n");
	while(curr!=NULL)
	{
		switch(curr->type)
		{
			case CHAR:
				printf("%c ",*((char *)curr->data));break;
			case INT:
				printf("%d ",*((int *)curr->data));break;
			case FLOAT:
				printf("%f ",*((float *)curr->data));break;
			case STRING:
				printf("%s ",((char *)curr->data));break;
		}
		curr=curr->next;
	}
	printf("\n");
}
int main()
{
	float f=7.3;
	int x=8;
	char z='a';	
	char *y="sagar";
	//insert_n(5);
	//insert_c('a');
	//insert_s("sagar");
	//insert(&x,4);
	insert(y,2);
	insert(&z,1);
	insert(&x,4);
	insert(&f,3);
	display();
	return 0;
}
