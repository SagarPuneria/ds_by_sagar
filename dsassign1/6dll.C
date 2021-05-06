#include<iostream>
#include<stdlib.h>
using namespace std;
class dll
{
	struct node
	{
		int data;
		struct node *next,*prev;
	};
	struct node *head;
	public:
	void insertbeg(int ele)
	{
		struct node *temp;
		temp=new node;
		temp->data=ele;
		temp->prev=NULL;
		temp->next=head;
		if(head!=NULL)
			head->prev=temp;
		head=temp;
	}
	void insertend(int ele)
	{
		struct node *temp,*curr;
		temp=new node;
		temp->data=ele;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			temp->prev=NULL;
			return;
		}
		curr=head;
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=temp;
		temp->prev=curr;
		//return;
	}
	void insertafter(int item,int ele)
	{
		struct node *curr,*temp;
		curr=head;
		while(curr!=NULL)
		{
			if(curr->data==item)
			{
				temp=new node;
				temp->data=ele;
				temp->prev=curr;
				temp->next=curr->next;
				if(curr->next!=NULL)//if it is not at end of list
					curr->next->prev=temp;
				curr->next=temp;
				return;
			}
			curr=curr->next;
		}
		cout<<"element not found\n";
	}
	void insertbefore(int item,int ele)
	{
		struct node *curr,*temp;
		curr=head;
		while(curr!=NULL)
		{
			if(curr->data==item)
			{
				temp=new node;
				temp->data=ele;
				temp->prev=curr->prev;
				temp->next=curr;
				if(curr->prev!=NULL)//if it is not first in list
					curr->prev->next=temp;
				else
					head=temp;
				curr->prev=temp;
				return;
			}
			curr=curr->next;
		}
		cout<<"element not found\n";
	}
	void del(int item)
	{
		struct node *curr;
		curr=head;
		while(curr!=NULL)
		{
			if(curr->data==item)
			{
				if(curr->prev!=NULL)
					curr->prev->next=curr->next;
				else
					head=curr->next;
				if(curr->next!=NULL)
					curr->next->prev=curr->prev;
				delete curr;
				return;
			}
			curr=curr->next;
		}
		cout<<"element not found\n";
	}
	void create_list()
	{
		int i,n,ele;
		cout<<"enter no. of nodes\n";
		cin>>n;
		if(n==0)
			return;
		cout<<"enter elements to be inserted\n";
		cin>>ele;
		insertbeg(ele);
		for(i=2;i<=n;i++)
		{
			cout<<"enter ele to be inserted\n";
			cin>>ele;
			insertend(ele);
		}
	}
	dll()
	{
		head=NULL;
	}
	~dll()
	{
		struct node *curr;
		while(head!=NULL)
		{
			curr=head->next;
			delete head;
			head=curr;
		}
		cout<<"inside destructor\n";
	}
	void display()
	{
		struct node *curr;
		curr=head;
		cout<<"list is\n";
		while(curr!=NULL)
		{
			cout<<curr->data<<"\t";
			curr=curr->next;
		}
		cout<<endl;
	}
	void reverse();
};
void dll::reverse()
{
	struct node *curr;
	curr=head;
	while(curr->next!=NULL)
		curr=curr->next;
	while(curr!=NULL)
	{
		cout<<curr->data<<"\t";
		curr=curr->prev;
	}
	cout<<"\n";
	/*struct node *p1,*p2;
	p1=head;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL)
	{
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	head=p1;
	/*(or)struct node *prev,*curr,*next;
	prev=NULL;
	curr=head;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;*/
}
int main()
{
	dll s;
	int ch,ele,sea,item,flag=0;
	while(1)
	{
		cout<<"1.create list\n";
		cout<<"2.display\n";
		cout<<"3.Add at beginning\n";
		cout<<"4.Add at end\n";
		cout<<"5.Add after node\n";
		cout<<"6.Add before node\n";
		cout<<"7.delete\n";
		cout<<"8.reverse\n";
		//cout<<"9.search\n";
		cout<<"9.quit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:s.create_list();
				break;
			case 2:s.display();
				break;
			case 3:cout<<"enter ele to be inserted\n";
				cin>>ele;
				s.insertbeg(ele);
				break;
			case 4:cout<<"enter ele to be inserted\n";
				cin>>ele;
				s.insertend(ele);
				break;	
			case 5:cout<<"enter ele to be inserted\n";
				cin>>ele;
				cout<<"enter ele after which to be inserted\n";
				cin>>sea;
				s.insertafter(sea,ele);
				break;	
			case 6:cout<<"enter ele to be inserted\n";
				cin>>ele;
				cout<<"enter ele before which to be inserted\n";
				cin>>sea;
				s.insertbefore(sea,ele);
				break;		
			case 7:cout<<"enter ele to be deleted\n";
				cin>>ele;
				s.del(ele);
				break;
			case 8:s.reverse();
				break;
			//case 9:cout<<"enter ele to be search\n";
			//	cin>>ele;
			//	s.search(ele);
			//	break;
			case 9:flag=1;
				break;//exit(1);
			default:cout<<"wrong choice\n";
		}
		if(flag==1)
			break;
	}	
	return 0;
}				
