#include<iostream>
using namespace std;
class node{
	public:
		int val;
		node *left,*right;
		node(int val)
		{
			this->val=val;
			right=left=NULL;
		}
};
class tree{
	public:
		node *root;
		tree()
		{
			root=NULL;
		}
		void insert(int data)
		{
			if(root==NULL)
			{
				root= new node(data);
			}
			else
			{
				node *current=root;
				while(true)
				{
					if(current->val>data)
					{
						if(current->left==NULL)
						{
							current->left=new node(data);
							break;
						}
						else
						{
							current=current->left;
						}
				    }
					else
					{
							if(current->right==NULL)
						{
							current->right=new node(data);
							break;
						}
						else
						{
							current=current->right;
						}
					}
				}
			}
		}
		void inorder (node *rt)
		{
			if(rt!=NULL)
			{
				inorder(rt->left);
				cout<<rt->val<<" ";
				inorder(rt->right);
			}
		}
		int search(node *rt,int data)
		{
			if(rt==NULL)return 0;
			else if(rt->val==data)return 1;
			else if(rt->val>data) return search(rt->left,data);
			else return search(rt->right,data);
		}
};
int main()
{
	tree A;
	A.insert(10);
	A.insert(8);
	A.insert(9);
	A.insert(5);
	A.insert(35);
	A.insert(12);
	A.insert(46);
	A.inorder(A.root);
	cout<<endl;
	cout<<" Enter element for search: ";
	int a;
	cin>>a;
	cout<<endl;
	A.search(A.root,a)==1?cout<<"finded":cout<<"node finded";
}
