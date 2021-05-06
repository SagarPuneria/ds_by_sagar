#include<iostream>
using namespace std;
class pl
{
	struct node 
	{
		float coef;
		int expo;
		struct node *next;
	};
	struct node *head;
public:	
	pl()
	{
		head=NULL;
	}
	~pl()
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
	void create_list()
	{
		int i,n,ex;
		float co;
		cout<<"enter no. of terms\n";
		cin>>n;
		if(n==0)
			return;
		for(i=1;i<=n;i++)
		{
			cout<<"enter coeficient for term "<<i<<endl;
			cin>>co;
			cout<<"enter exponent for term "<<i<<endl;
			cin>>ex;
			insert_s(co,ex);
		}
	}
	void insert_s(float co,int ex)
	{
		struct node *curr,*temp;
		temp=new node;
		temp->coef=co;
		temp->expo=ex;
		if(head==NULL || ex>head->expo)
		{//if list is empty or expo greater than first one
			temp->next=head;
			head=temp;
			return;
		}
		curr=head;
		while(curr->next!=NULL && ex<=curr->next->expo)
			curr=curr->next;
		temp->next=curr->next;
		curr->next=temp;
	}
	void display()
	{
		struct node *curr;
		if(head==NULL)
		{
			cout<<"zero poylnomial\n";
			return;
		}
		curr=head;
		while(curr!=NULL)
		{
			cout<<curr->coef<<"x^"<<curr->expo;
			curr=curr->next;
			if(curr!=NULL)
				cout<<"+";
			else
				cout<<"\n";
		}
	}
	void poly_add(pl l1,pl l2)
	{
		struct node *c1,*c2;
		c1=l1.head;
		c2=l2.head;
		while(c1!=NULL && c2!=NULL)
		{
			if(c1->expo>c2->expo)
			{
				insert_s(c1->coef,c1->expo);
				c1=c1->next;
			}
			else if(c1->expo<c2->expo)
			{
				insert_s(c2->coef,c2->expo);
				c2=c2->next;
			}
			else if(c1->expo==c2->expo)
			{
				insert_s(c1->coef+c2->coef,c1->expo);
				c1=c1->next;
				c2=c2->next;
			}
		}
		while(c1!=NULL)
		{
			insert_s(c1->coef,c1->expo);
			c1=c1->next;
		}
		while(c2!=NULL)
		{
			insert_s(c2->coef,c2->expo);
			c2=c2->next;
		}
		cout<<"added polynomial is\n";
		display();
	}
};
int main()
{
	pl l1,l2,l3;
	l1.create_list();
	l2.create_list();
	cout<<"list 1 is \n";
	l1.display();
	cout<<"list 2 is \n";
	l2.display();
	l3.poly_add(l1,l2);
}
