#include<iostream>
using namespace std;
class tree
{
	public:
		void insert(int x)
		{
			node* t2=new node;
			if(t==NULL)
				t=t2;
			else
			{
				while(1)
				{
					if(t->data>x)
					{   
						if(t->left!=NULL)
							t=t->left;
						else
						{   
							t->left=t2;
							break;
						}   
					}
					else 
					{   
						if(t->right!=NULL)
							t=t->right;
						else
						{
							t->right=t2;
							break;
						}
					}

				}
			}

		}
	private:
		class node
		{
			public:
			tree *right;
			tree* left;
			int data;
			node():left(NULL),right(NULL),data(0)
			{}
		};
		node *t;
};
int main()
{
	tree t;
	t.insert(10);
}

