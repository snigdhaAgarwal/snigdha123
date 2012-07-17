#include<iostream>
using namespace std;
class tree
{
public:
	tree():t(NULL)
	{}
	void insert(int x)
	{
		t=recinsert(t,x);
	}
	node* recinsert(node *t1,int x)
	{
		if(t1==NULL)
		{
			node *t2=new node(x);
			return t2;
		}
		else if(t1->data>x)
		{
			t1->left=recinsert(t1->left,x);
		}
		else if(t1->data<x)
		{
			t1->right=recinsert(t1->right,x);
		}
		return t1;
	}
private:
	class node
	{
	public:
		node *right;
		node* left;
		int data;
		node(int x):left(NULL),right(NULL),data(x)
		{}
	};
	node *t;
};
int main()
{
	tree t;
	t.insert(10);
}
