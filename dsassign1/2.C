#include<iostream>
#include<cstdlib>
using namespace std;
/*struct node 
{
	int data;
	struct node *next;
};*/
class sl
{
	class node 
	{
		public:
		int data;
		class node *next;
	};
	node *head;
public:	
	void insertbeg(int ele)//struct node *insertbeg(int ele)
	{
		node *temp;
		temp=new node;
		temp->data=ele;
 		temp->next=head;
	 	head=temp;
	}
	void insertend(int ele)//struct node *insertend(int ele)
	{
		node *temp,*curr;
		temp=new node;
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
		node *curr;
		curr=head;
		while(curr!=NULL)// && (curr->data!=sea))
		{	
			if(curr->data==sea)
			{
				node *temp;
				temp=new node;
				temp->data=ele;
				temp->next=curr->next;
				curr->next=temp;
				return;
				//return head;
			}
			curr=curr->next;
		}
		cout<<"element not found\n";
	}
	void insertbefore(int sea,int ele)//struct node *insertbefore(int sea,int ele)
	{
		node *temp;
		if(head==NULL)
		{
			cout<<"list is empty\n";
			return;
			//return head;
		}
		if(head->data==sea)
		{
			temp=new node;
			temp->data=ele;
			temp->next=head;
	 		head=temp;
			return;
			//return head;
	 	}
		node *curr=head;
 		while(curr->next!=NULL)
		{
			if(curr->next->data==sea)
			{
	 			temp=new node;
	 			temp->data=ele;
				temp->next=curr->next;
				curr->next=temp;
				return;
				//return head;
			}
			curr=curr->next;
		}
		cout<<"element not found\n";
		return;
		//return head; 
	}
	void display()
	{
		node *curr;
		curr=head;
		cout<<"list is\n";
		while(curr!=NULL)
		{
			cout<<curr->data<<"\t";
			curr=curr->next;
		}
		cout<<endl;
	}
	sl()
	{
		head=NULL;
	}
	void del(int ele)//struct node *del(int ele)
	{
		//int x=-999;
		node *temp;
		if(head==NULL)
		{
			cout<<"list is empty\n";
			return;
			//return head;
		}
		if(head->data==ele)//delete first
		{
			
			temp=head;
			head=head->next;//(or)head=temp->next;
			delete temp;
			return;
			//return head;
		}	
		node *curr=head;
		while(curr->next!=NULL)//delete last or between
		{
			if(curr->next->data==ele)
			{
				temp=curr->next;
				curr->next=temp->next;
				delete temp;
				return;
				//return head;
			}
			curr=curr->next;
		}
		cout<<"elemen not found\n";
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
	void search(int ele)
	{
		node *curr;
		int pos=1;
		curr=head;
		while(curr!=NULL)
		{
			if(curr->data==ele)
			{
				cout<<"element "<<ele<<" found at position "<<pos<<endl;
				return;
			}
			curr=curr->next;
			pos++;
		}
		cout<<"element "<<ele<<" not found in list\n";
	}
	void reverse();
};
void sl::reverse()
{
	node *prev,*curr,*next;
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
	/*node *rhead=NULL,*temp;
	while(head!=NULL)
	{
		temp=head;
		head=temp->next;
		temp->next=rhead;
		rhead=temp;
 	}
	head=rhead;
	return;*/
}
int main()
{
	/*sl s;
	for(int i=0;i<4;i++)
		s.insertbeg(i);
	s.display();
	s.insertend(7);
	s.display();
	s.insertafter(2,5);
	s.display();
	s.insertbefore(7,9);
	s.display();
	s.del(3);
	s.display();
	s.reverse();
	s.display();
	*/
	sl s;
	int ch,ele,sea,item;
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
		cout<<"9.search\n";
		cout<<"10.quit\n";
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
			case 9:cout<<"enter ele to be search\n";
				cin>>ele;
				s.search(ele);
				break;
			case 10:exit(1);
			default:cout<<"wrong choice\n";
		}
	}	
	return 0;
}		
