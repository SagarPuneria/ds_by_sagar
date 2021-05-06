#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insertbeg(int ele)//struct node *insertbeg(int ele)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=head;
 	head=temp;
}
void insertend(int ele)//struct node *insertend(int ele)
{
	struct node *temp,*curr;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=ele;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	curr=head;
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=temp;
}
void insertafter(int sea,int ele)//struct node *insertafter(int sea,int ele)
{
	struct node *curr;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	curr=head;
	while(curr!=NULL)// && (curr->data!=sea))
	{	
		if(curr->data==sea)
		{
			struct node *temp;
			temp=(struct node *)malloc(sizeof(struct node));
			temp->data=ele;
			temp->next=curr->next;
			curr->next=temp;
			return;
		}
		curr=curr->next;
	}
	printf("element not found\n");
}
void insertbefore(int sea,int ele)//struct node *insertbefore(int sea,int ele)
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->data==sea)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=ele;
		temp->next=head;
 		head=temp;
		return;
 	}
	struct node *curr=head;
	while(curr->next!=NULL)
	{
		if(curr->next->data==sea)
		{
 			temp=(struct node *)malloc(sizeof(struct node));
 			temp->data=ele;
			temp->next=curr->next;
			curr->next=temp;
			return;
		}
		curr=curr->next;
	}
	printf("element not found\n");
}
void display()
{
	struct node *curr;
	curr=head;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("list is\n");
	while(curr!=NULL)
	{
		printf("%d ",curr->data);
		curr=curr->next;
	}
	printf("\n");
}
void del(int ele)//struct node *del(int ele)
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->data==ele)//delete first
	{
		temp=head;
		head=head->next;//(or)head=temp->next;
		free(temp);
		return;
	}	
	struct node *curr=head;
	while(curr->next!=NULL)//delete last or between
	{
		if(curr->next->data==ele)
		{
			temp=curr->next;
			curr->next=temp->next;
			free(temp);
			return;
		}
		curr=curr->next;
	}
	printf("elemen not found\n");
}
void create_list()
{
	int i,n,ele;
	printf("enter no. of nodes\n");
	scanf("%d",&n);
	if(n==0)
		return;
	printf("enter elements to be inserted\n");
	scanf("%d",&ele);
	insertbeg(ele);
	for(i=2;i<=n;i++)
	{
		printf("enter ele to be inserted\n");
		scanf("%d",&ele);
		insertend(ele);
	}
}
void sorting()
{
	struct node *p,*q;
	int temp;
	for(p=head;p->next!=NULL;p=p->next)//selection sort
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data>q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
}
void reverse()
{
	struct node *prev,*curr,*next;
	prev=NULL;
	curr=head;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
}
int main()
{
	int ch,ele,sea,item;
	while(1)
	{
		printf("1.create list\n");
		printf("2.display\n");
		printf("3.Add at beginning\n");
		printf("4.Add at end\n");
		printf("5.Add after node\n");
		printf("6.Add before node\n");
		printf("7.delete\n");
		printf("8.reverse\n");
		printf("9.sorting\n");
		printf("10.quit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create_list();
				break;
			case 2:display();
				break;
			case 3:printf("enter ele to be inserted\n");
				scanf("%d",&ele);
				insertbeg(ele);
				break;
			case 4:printf("enter ele to be inserted\n");
				scanf("%d",&ele);
				insertend(ele);
				break;	
			case 5:printf("enter ele to be inserted\n");
				scanf("%d",&ele);
				printf("enter ele after which to be inserted\n");
				scanf("%d",&sea);
				insertafter(sea,ele);
				break;	
			case 6:printf("enter ele to be inserted\n");
				scanf("%d",&ele);
				printf("enter ele before which to be inserted\n");
				scanf("%d",&sea);
				insertbefore(sea,ele);
				break;		
			case 7:printf("enter ele to be deleted\n");
				scanf("%d",&ele);
				del(ele);
				break;
			case 8:reverse();
				break;
			case 9:sorting();
				break;
			case 10:exit(1);
			default:printf("wrong choice\n");
		}
	}	
	return 0;
}		
