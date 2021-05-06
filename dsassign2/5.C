#include<iostream>
using namespace std;
template<class T>
class bt
{
	struct node
	{
		T data;
		struct node *left;
		struct node *right;
	};
	public:
	struct node *root;
	bt()
	{
		root=NULL;
	}
	void order_del(struct node *curr)
	{
		if(curr!=NULL)
		{
			order_del(curr->left);
			order_del(curr->right);
			delete curr;
			cout<<"inside destructor\n";
		}
	}
	~bt()
	{
		order_del(root);
	}
	void insertion(T ele)
	{
		char ch;
		struct node *temp,*curr;
		temp=new node;
		temp->data=ele;
		temp->left=temp->right=NULL;
		if(root==NULL)
		{
			root=temp;
			return;
		}
		curr=root;
		while(1)//(curr!=NULL)
		{
			cout<<"l (or) r\n";
			cin>>ch;
			if(ch=='l')
			{
				if(curr->left==NULL)
				{
					curr->left=temp;
					return;//break;
				}
				else
					curr=curr->left;
			}
			else
			{
				if(curr->right==NULL)
				{
					curr->right=temp;
					return;//break;
				}
				else
					curr=curr->right;
			}
		}
	}
	void inorder(struct node *curr)
	{
		if(curr!=NULL)
		{
			inorder(curr->left);
			cout<<curr->data<<"\t";
			inorder(curr->right);
		}
	}
	void preorder(struct node *curr)
	{
		if(curr!=NULL)
		{
			cout<<curr->data<<"\t";
			preorder(curr->left);
			preorder(curr->right);
		}
	}
	void postorder(struct node *curr)
	{
		if(curr!=NULL)
		{
			postorder(curr->left);
			postorder(curr->right);
			cout<<curr->data<<"\t";
		}
	}
	
	void mirror(struct node *curr)
	{
		struct node *temp;
		if(curr!=NULL)
		{
			temp=curr->left;
			curr->left=curr->right;
			curr->right=temp;
			mirror(curr->left);	
			mirror(curr->right);
		}
	}
	void del(T);
};
template<class T>
void bt<T>::del(T dkey)
{
	struct node *par,*curr,*child,*succ,*parsucc;	
	curr=root;
	par=NULL;
	while(curr!=NULL)
	{
		if(dkey==curr->data)
			break;
		par=curr;
		if(dkey<curr->data)
			curr=curr->left;
		else
			curr=curr->right;
	}
	if(curr==NULL)
	{
		cout<<"dkey element not present\n";
		return;
	}
	if(curr->left!=NULL && curr->right!=NULL)
	{//2 children
		parsucc=curr;
		succ=curr->right;
		while(succ->left!=NULL)
		{
			parsucc=succ;
			succ=succ->left;
		}
		curr->data=succ->data;
		curr=succ;
		par=parsucc;
	}
	//1 or no child
	if(curr->left!=NULL)//node to be deleted has left child
		child=curr->left;
	else//node to be deleted has right child or no child
		child=curr->right;//child may be NULL or may not be NULL
	if(par==NULL)//tree has only one node(root node)
		root=child;
	else if(curr==par->left)//node is left child of its parent
		par->left=child;
	else//node is right child of its parent
		par->right=child;
	delete curr;
}
int main()
{
	char val;
	bt<char>b;
	int ch,flag=0;
	while(1)
	{
		cout<<"1.insertion\n";
		cout<<"2.preorder\n";
		cout<<"3.inorder\n";
		cout<<"4.postorder\n";
		cout<<"5.deletion\n";
		cout<<"6.mirror\n";
		cout<<"7.quit\n";
		cout<<"enter your choice\n";
		cin>>ch;
		switch(ch)
		{	
			case 1:cout<<"enter element\n";
				cin>>val;
				b.insertion(val);
				break;
			case 2:b.preorder(b.root);
				cout<<endl;
				break;
			case 3:b.inorder(b.root);
				cout<<endl;
				break;
			case 4:b.postorder(b.root);
				cout<<endl;
				break;
			case 5:cout<<"enter element to be deleted\n";
				cin>>val; 
				b.del(val);
				break;
			case 6:b.mirror(b.root);
				break;
			case 7:flag=1;
				break;
			default:cout<<"wrong choice";
		}
		if(flag==1)
			break;
	}
}
