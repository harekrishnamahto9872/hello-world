#include<iostream>
using namespace std;
class tree{
	public:
	int info;
	tree *right;
	tree *left;
	
};
class node{
	public:
	tree *info;
	node *next;
}*front=NULL,*rear=NULL,*q=NULL;
void enqueue(node *q,tree *val)
{
	node *n=new node;
	n->info=val;
	n->next=NULL;
	if(front==NULL)
	{
		front=rear=n;
		q=n;
	}
	else
	{
		rear->next=n;
	}
}
int isemptyqueue(node *q)
{
	if(front=NULL)
	return(1);
	else
	return(0);
}
tree * dequeue(node *q)
{
	if(isemptyqueue)
	return(0);
	else
	{
		node *m=front;
		tree *p=front->info;
		front=q=front->next;
		delete(m);
	}
}
tree * insert_node(tree *root,int val)
{

	if(root==NULL)
	{
		tree *p=new tree;
		root=p;
		root->info=val;
		root->left=NULL;
		root->right=NULL;
	}
	else if(val<=root->info)
	{
		root->left=insert_node(root->left,val);	
		
	}
	
	else
	{
		root->right=insert_node(root->right,val);
		
	}
	return(root);
}
void post_traverse(tree *root)
{
	if(root)
	{
		
		post_traverse(root->left);
		post_traverse(root->right);
		cout<<root->info<<endl;
	}
}

void pre_traverse(tree *root)
{
	if(root)
	{
		
		cout<<root->info<<endl;
		pre_traverse(root->left);
		pre_traverse(root->right);
		
	}
}
void in_traverse(tree *root)
{
	if(root)
	{
		
		
		in_traverse(root->left);
		cout<<root->info<<endl;
		in_traverse(root->right);
		
	}
}
int level_traverse(tree *root)
{
	tree *temp;
	if(!root)
	return(0);
	enqueue(front,root);
	while(!isemptyqueue(q))
	{
		temp=dequeue(q);
		cout<<temp->info<<endl;
		enqueue(front,temp->left);
		enqueue(front,temp->right);
	}
	
}
tree * find(tree *root,int val)
{
	if(root==NULL)
	return(NULL);
	else if(val<root->info)
	return(find(root->left,val));
	else if(val>root->info)
	return(find(root->right,val));
	return(root);
}
tree * maxval(tree *root)
{
	while(root->right!=NULL)
	root=root->right;
	return(root);
}
tree * delete1(tree *root,int val)
{
	if(root==NULL)
	return(NULL);
	else if(val<root->info)
	root->left=delete1(root->left,val);
	else if(val>root->info)
	root->right=delete1(root->right,val);
	else
	{
		if(root->left==NULL)
		{
			tree *temp=root->right;
			delete(root);
			return(temp);
		}
		if(root->right==NULL)
		{
			tree *temp=root->left;
			delete(root);
			return(temp);
		}
		else
		{
			tree *temp=maxval(root->left);
			root->info=temp->info;
			root->left=delete1(root->left,temp->info);
			
		}
	}
	return(root);
}
main()
{
	tree *root=NULL;
	int n;
	int val;
	cout<<"Enter how many nodes u want"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter value to be inserted"<<endl;
		cin>>val;
		root=insert_node(root,val);
	}
	cout<<"in_order"<<endl;
	in_traverse(root);
	cout<<"Pre_order"<<endl;
	pre_traverse(root);
	cout<<"post_order"<<endl;
	post_traverse(root);
	cout<<"Level Order"<<endl;
	int item;
	cout<<"Enter value to be searched"<<endl;
	cin>>item;
	tree *f=find(root,item);
	if(f==NULL)
	cout<<"NOT found"<<endl;
	else
	cout<<"value Found at address "<<f<<endl;
	
	int d;
	cout<<"Enter element to be deleted"<<endl;
	cin>>d;
	root=delete1(root,d);
	
	pre_traverse(root);
	
//	level_traverse(root);	
}
