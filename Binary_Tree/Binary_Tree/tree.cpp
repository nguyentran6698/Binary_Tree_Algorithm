#include "Tree_Node.h"
#include <iostream>
using namespace std;
class Tree
{
private:
	Node* root;
public:
	Tree()
	{
		root = nullptr;
	}
	void creat_tree();
	void preOrder(Node *p);
	void preOrder() { preOrder(root); }
	void postOrder(Node* p);
	void postOrder() { postOrder(root); }
	void inOrder(Node* p);
	void inOrder() { inOrder(root); }
	void levelOrder(Node* p);
	int Height(Node* p);
};
void Tree::creat_tree()
{
	Queue t;
	Node* p;
	int x;
	cout << "Enter root value:";
	cin >> x;
	root->set_data(x);
	root->lchild, root->rchild = nullptr;
	t.enqueue(root);
	while (!t.isEmpty)
	{
		p = t.dequeue();
		cout << "Enter value for the left child " << p->get_data << ": ";
		cin >> x;
		if (x != -1)
		{
			Node* w = new Node;
			w->set_data(x);
			w->lchild, w->rchild = nullptr;
			p->lchild = w;
			t.enqueue(w);
			
		}
		cout << "Enter value for the right child " << p->get_data << ": ";
		cin >> x;
		if (x != -1)
		{
			Node* w = new Node;
			w->set_data(x);
			w->lchild, w->rchild = nullptr;
			p->rchild = w;
			t.enqueue(w);

		}
		
	}
}
void Tree::preOrder(Node *t)
{
	if (t != nullptr)
	{
		cout << t->get_data << " ";
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}
void Tree::inOrder(Node* t)
{
	if (t != nullptr)
	{
		inOrder(t->lchild);
		cout << t->get_data << " ";
		inOrder(t->rchild);
	}
}
void Tree::postOrder(Node* t)
{
	if (t)
	{
		postOrder(t->lchild);
		postOrder(t->rchild);
		cout << t->get_data << " ";
	}
}
void Tree::levelOrder(Node* t)
{

}
int Tree::Height(Node* root)
{
	int x = 0, y = 0;
	if (root == 0)
		return 0;
	x = Height(root->lchild);
	y = Height(root->rchild);
	if (x > y)
		return x + 1;
	else
		return y + 1;
	
}
int main()
{




}

