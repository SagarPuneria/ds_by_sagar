#include<iostream>
using namespace std;
struct node 
{
	int data;
	struct node *next;
};
class sl
{
	 struct node *head;
public:	
	void insertbeg(int ele)
	{
	 struct node *temp;
	 temp=new node;
	 temp->data=ele;
	 if(head==NULL)
	 {
	  temp->next=NULL;
	  head=temp;
     	 }
	else
	 {
	 temp->next=head;
	 head=temp;
	 }
	}
	void insertend(int ele)
	{
	 struct node *temp;
	 temp=new node;
	 temp->data=ele;
	 temp->next=NULL;
	 if(head==NULL)
	 {
	  head=temp;
	  }
	 else
	 {
	  struct node *curr;
	  curr=head;
	  while(curr->next!=NULL)
	  curr=curr->next;
	  curr->next=temp;
	 }
	 }
	void insertafter(int sea,int ele)
	{
	 struct node *curr;
	 curr=head;
	 while((curr!=NULL)&&(curr->data!=sea))
	 curr=curr->next;
	 if(curr!=NULL)
	 {
	  struct node *temp;
	  temp=new node;
	  temp->data=ele;
	  temp->next=curr->next;
	  curr->next=temp;
	 }
	 else	
	 {
	 cout<<"element not found";
	 }
	}
	 void insertbefore(int sea,int ele)
	{
	 if(head!=NULL)
	 {
	  if(head->data==sea)
	 {
	  struct node *temp;
  	  temp=new node;
	  temp->data=ele;
	  temp->next=head;
	 head=temp;
	 } 
	 else
	 {
	 struct node *curr;
	 curr=head;
	 while((curr->next!=NULL)&&(curr->next->data!=sea))
	 curr=curr->next;
	 if(curr->next!=NULL)
	 {
	 struct node *temp;
	 temp=new node;
	 temp->data=ele;
	 temp->next=curr->next;
	 curr->next=temp;
	
}
	 else
	 cout<<"element not found";
	}
 
	}
	else
	 cout<<"list empty";
	}
	void travelforward()
	{
	 struct node *curr;
	 curr=head;
	 while(curr!=NULL)
	 {
	 cout<<curr->data<<endl;
	 curr=curr->next;
	 }
	}
	sl()
	{
	 head=NULL;
	}
	int deletefirst()
	{
	 int x=-999;
	 if(head!=NULL)
	 {
	  struct node *temp;
	  temp=head;
	  x=temp->data;
	 head=temp->next;
	 delete temp;
	}
	else
	 cout<<"list is empty";
	return x;
	}
	int deleteend()
	{
	  int x=-999;
	  if(head!=NULL)
	  {
 	    if(head->next==NULL)
	    {
	      x=head->data;
	      delete head;
	    }
	   else
	    {
	      struct node *curr,*temp;
	      curr=head;
	      while(curr->next->next!=NULL)
	      curr=curr->next;
	       temp=curr->next;
	      x=temp->data;
	      curr->next=NULL;
	      delete temp;
	     }
	    }
	   else
	    cout<<"list is empty";
	     return x;
	    }
 	int deletespecific(int ele)
	{
	 if(head==NULL)
	  cout<<"list is empty";
	 else
	 {
	 if(head->data==ele)
	  {
	  struct node *temp;
	  temp=head;
	  head=temp->next;
	  delete temp;
	  }
	 else
	 {
	struct node *curr,*temp;
	curr=head;
	while(curr->next!=NULL&&curr->next->data!=ele)
	curr=curr->next;
	if(curr->next!=NULL)
	 {
	 temp=curr->next;
	 curr->next=temp->next;
	 delete temp;
	}
	else
	cout<<"element not found";
	}
	}
	}
	void reverse()
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
	 }
};
int main()
{
	int a,b;
	sl s;
	for(int i=0;i<4;i++)
	s.insertbeg(i);
	//s.insertbeg(2);
	//s.travelforward();
	s.insertend(7);
	s.insertafter(2,5);
	s.insertbefore(7,9);
	
	s.travelforward();

	s.deletefirst();
	s.deleteend();
	s.deletespecific(5);
	//cout<<"a value"<<a<<"\t";
	
	cout<<"\t";
	s.travelforward();
	cout<<"\n";
	s.reverse();
	s.travelforward();
return 0;
}		
