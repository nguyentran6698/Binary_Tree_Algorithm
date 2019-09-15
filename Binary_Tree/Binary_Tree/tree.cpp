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
	int count_node(Node* p);
	int count_node() { return count_node(root);}
	int node_degree_2() { return node_degree_2(root);}
	int node_degree_2(Node*);
	int Height(Node* p);
};
void Tree::creat_tree()
{
	Queue t;
	Node* p, w;
	int x;
	root = new Node;
	cout << "Enter root value:";
	cin >> x;
	root->set_data(x);
	root->lchild, root->rchild = nullptr;
	t.enqueue(root);
	while (!t.isEmpty())
	{
		p = t.dequeue();
		cout << "Enter value for the left child " << p->get_data() << ": ";
		cin >> x;
		if (x != -1)
		{
			Node* w = new Node;
			w->set_data(x);
			w->lchild, w->rchild = nullptr;
			p->lchild = w;
			t.enqueue(w);
			
		}
		cout << "Enter value for the right child " << p->get_data() << ": ";
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
		cout << t->get_data ()<< " ";
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}
void Tree::inOrder(Node* t)
{
	if (t != nullptr)
	{
		inOrder(t->lchild);
		cout << t->get_data() << " ";
		inOrder(t->rchild);
	}
}
void Tree::postOrder(Node* t)
{
	if (t)
	{
		postOrder(t->lchild);
		postOrder(t->rchild);
		cout << t->get_data() << " ";
	}
}
void Tree::levelOrder(Node* root)
{
	Queue q;
	cout << root->get_data() << endl;
	q.enqueue(root);
	while (!q.isEmpty())
	{
		root = q.dequeue();
		if (root->lchild)
		{
			cout << root->lchild->get_data() <<" ";
			q.enqueue(root->lchild);
		}
		if (root->rchild)
		{
			cout << root->rchild->get_data() << " ";
			q.enqueue(root->rchild);
		}
	}

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
int Tree::count_node(Node *t)
{
	int x, y;
	if(t !=nullptr)
	{
		x = count_node(t->lchild);
		y = count_node(t->rchild);
		return x + y + 1;
	}
	return 0;
}
int Tree::node_degree_2(Node* root)
{
	int x, y;
	if (root != nullptr)
	{
		x = node_degree_2(root->lchild);
		y = node_degree_2(root->rchild);
		if (root->lchild != nullptr && root->rchild != nullptr)
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}
int main()
{
	Tree t;
	t.creat_tree();
	cout << "PreOrder: " << endl;
	t.preOrder();
	cout << endl;
	cout << "Number of Node in this Tree is: " << t.count_node() << endl;
	cout << "Number of Node degree 2 in this Tree is: " << t.node_degree_2() << endl;



	return 0;
}

