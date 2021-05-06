#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
/*struct node 
{
	int data;
	struct node *next;
};*/
template<class T>
class sl
{
	struct node 
	{
		T data;
		struct node *next;
	};
	struct node *head;
public:	
	sl()
	{
		head=NULL;
	}
	~sl()
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
	void insertbeg(T ele)//struct node *insertbeg(int ele)
	{
		struct node *temp;
		temp=new node;
		temp->data=ele;
 		temp->next=head;
	 	head=temp;
		return;
		//return head;
	}
	void insertend(T ele)//struct node *insertend(int ele)
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
	void insertafter(T sea,T ele)//struct node *insertafter(int sea,int ele)
	{
		struct node *curr;
		curr=head;
		while(curr!=NULL)// && (curr->data!=sea))
		{	
			if(curr->data==sea)
			{
				struct node *temp;
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
	void insertbefore(T sea,T ele)//struct node *insertbefore(int sea,int ele)
	{
		struct node *temp;
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
		struct node *curr=head;
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
	}
	void display()
	{
		struct node *curr;
		curr=head;
		if(head==NULL)
		{
			cout<<"list is empty\n";
			return;
		}
		cout<<"list is\n";
		while(curr!=NULL)
		{
			cout<<curr->data<<" ";
			curr=curr->next;
		}
		cout<<"\n";
	}
	void del(T ele)//struct node *del(int ele)
	{
		//int x=-999;
		struct node *temp;
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
		struct node *curr=head;
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
		int i,n;
		T ele;
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
		return;
	}
	void reverse();
};
template<>
void sl<char *>::insertbeg(char *ele)
{
	struct node *temp;
	temp=new node;
	temp->data=new char[strlen(ele)+1];
	strcpy(temp->data,ele);
	temp->next=head;
 	head=temp;
}
template<>
void sl<char *>::insertend(char *ele)//struct node *insertend(int ele)
{
	struct node *temp,*curr;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=new char[strlen(ele)+1];
	strcpy(temp->data,ele);	
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
template<>
void sl<char *>::insertafter(char *sea,char *ele)//struct node *insertafter(int sea,int ele)
{
	struct node *curr;
	curr=head;
	while(curr!=NULL)// && (curr->data!=sea))
	{	
		if(curr->data==sea)
		{
			struct node *temp;
			temp=new node;
			temp->data=new char[strlen(ele)+1];
			strcpy(temp->data,ele);	
			temp->next=curr->next;
			curr->next=temp;
			return;
		}
		curr=curr->next;
	}
	cout<<"element not found\n";
}
template<>
void sl<char *>::insertbefore(char *sea,char *ele)//struct node *insertbefore(int sea,int ele)
{
	struct node *temp;
	if(head==NULL)
	{
		cout<<"list is empty\n";
		return;
	}
	if(head->data==sea)
	{
		temp=new node;
		temp->data=new char[strlen(ele)+1];
		strcpy(temp->data,ele);	
		temp->next=head;
 		head=temp;
		return;
 	}
	struct node *curr=head;
	while(curr->next!=NULL)
	{
		if(curr->next->data==sea)
		{
			temp=new node;
			temp->data=new char[strlen(ele)+1];
			strcpy(temp->data,ele);	
			temp->next=curr->next;
			curr->next=temp;
			return;
		}
		curr=curr->next;
	}
	cout<<"element not found\n";
}
template<class T>
void sl<T>::reverse()
{
	struct node *rhead=NULL,*temp;
	while(head!=NULL)
	{
		temp=head;
		head=temp->next;
		temp->next=rhead;
		rhead=temp;
 	}
	head=rhead;
	return;
}
int main()
{
	/*sl<int>s;
	s.insertbeg(4);
	s.display();
	s.insertend(7);
	s.display();
	sl<char>s;
	s.insertbeg('a');
	s.display();
	s.insertend('g');
	s.display();
	/*s.insertafter(2,5);
	s.display();
	s.insertbefore(7,9);
	s.display();
	s.del(3);
	s.display();
	s.reverse();
	s.display();
	*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//sl<int>s;
	//int ch;
	//int ele,sea,item;
	//sl<char>s;
	//int ch;
	//char ele,sea,item;
	sl<char *>s;
	int ch,flag=0;
	char ele[15],sea[15],item[15];
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
			case 9:flag=1;//exit(1);
				break;
			default:cout<<"wrong choice\n";
		}
		if(flag==1)
			break;
	}	
	return 0;
}		
