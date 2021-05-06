#include<iostream>
#include<cstring>
using namespace std;
template<class U>
class Hash_Table
{
	struct node
	{
		U data;
		struct node *next;
	};
	struct node *table[10];

public:
	Hash_Table()
	{
		for(int i=0;i<10;++i)
		{
			table[i]=NULL;
		}
	}	
	
	void search(U n)//int or char
	{
		int hash;
		hash=n%10;
		struct node *curr;
		curr=table[hash];
		while(curr!=NULL)
		{
			if(curr->data==n)
			{
				break;
			}
			curr=curr->next;
		}
		if(curr!=NULL)
		{
			cout<<"Element found"<<endl;
		}
		else
		{
			cout<<"Element not found"<<endl;
		}
	}
	void get_data()//int or char
	{
		U n;
		char c;
		do
		{
			cout<<"Enter an element"<<endl;
			cin>>n;
			hashing(n);
			cout<<"Enter $ to continue"<<endl;
			cin>>c;
		}while(c=='$');
		cout<<"Enter an element to search"<<endl;
		cin>>n;
		search(n);
	}
	void display()
	{
		struct node *curr;
		for(int i=0;i<10;++i)
		{
			curr=table[i];
			while(curr!=NULL)
			{
				cout<<curr->data<<" ";
				curr=curr->next;
			}
		}
		cout<<endl;
	}
	void hashing(U n)//int
	{
		int hash;
		hash=n%10;
		struct node *temp,*curr;
		temp=new node;
		temp->data=n;
		temp->next=NULL;
		if(table[hash]==NULL)
		{
			table[hash]=temp;
		}
		else
		{
			curr=table[hash];
			while(curr->next!=NULL)
			{
				curr=curr->next;
			}
			curr->next=temp;
		}
	}
};

template<>
void Hash_Table<char*>::hashing(char* n)//char,string
{
	int hash;
	int num=n[0];
	hash=num%10;
	struct node *temp,*curr;
	temp=new node;
	temp->data=new char[10];
	strcpy(temp->data,n);
	temp->next=NULL;
	if(table[hash]==NULL)
	{
		table[hash]=temp;
	}
	else
	{
		curr=table[hash];
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=temp;
	}
}

template<>
void Hash_Table<char*>::search(char* n)//string
{
	int hash;
	int num=n[0];
	hash=num%10;
	struct node *curr;
	curr=table[hash];
	while(curr!=NULL)
	{
		if(strcmp(curr->data,n)==0)
		{
			break;
		}
		curr=curr->next;
	}
	if(curr!=NULL)
	{
		cout<<"String element found"<<endl;
	}
	else
	{
		cout<<"String element not found"<<endl;
	}
}

template<>
void Hash_Table<char*>::get_data()//string
{
	char *n;
	char c;
	n=new char[10];
	do
	{
		cout<<"Enter an string element"<<endl;
		cin>>n;
		hashing(n);
		cout<<"Enter $ to continue"<<endl;
		cin>>c;
	}while(c=='$');
	cout<<"Enter an string element to search"<<endl;
	cin>>n;
	search(n);
}

int main()
{
	Hash_Table <int>ht1;
	Hash_Table <char>ht2;
	Hash_Table <char*>ht3;
	cout<<"Enter integers in hash table"<<endl;
	ht1.get_data();
	cout<<"\nContents of hash table\n";
	ht1.display();

	cout<<"Enter characters in hash table"<<endl;
	ht2.get_data();
	cout<<"\nContents of hash table\n";
	ht2.display();

	//cout<<"Enter strings in hash table"<<endl;
	ht3.get_data();
	cout<<"\nContents of hash table"<<endl;
	ht3.display();
	return 0;
}
