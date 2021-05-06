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
	struct node 
	{
		int data;
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
	void insertbeg(int ele)//struct node *insertbeg(int ele)
	{
		struct node *temp;
		temp=new node;
		temp->data=ele;
 		temp->next=head;
	 	head=temp;
	}
	void find(int ele)//struct node *del(int ele)
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
			insertbeg(temp->data);//delete temp;
			return;
		}	
		struct node *curr=head;
		while(curr->next!=NULL)//delete last or between
		{
			if(curr->next->data==ele)
			{
				temp=curr->next;
				curr->next=temp->next;
				insertbeg(temp->data);//delete temp;
				return;
			}
			curr=curr->next;
		}
		cout<<"elemen not found\n";
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
};
int main()
{
	sl s;
	int ch,ele,flag=0;
	while(1)
	{
		cout<<"1.Add at beginning\n";
		cout<<"2.find element\n";
		cout<<"3.display\n";
		cout<<"4.quit\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"enter ele to be inserted\n";
				cin>>ele;
				s.insertbeg(ele);
				break;
			case 2:cout<<"enter ele to be  deleted\n";
				cin>>ele;
				s.find(ele);
				break;
			case 3:s.display();
				break;
			case 4:flag=1;//exit(1);
				break;
			default:cout<<"wrong choice\n";
		}
		if(flag==1)
			break;
	}	
	return 0;
}
