#include<iostream>
using namespace std;
class Node
{
private:
	int data;
	Node* next;
public:
	Node* lchild;
	Node* rchild;
	Node()
	{
		next = nullptr;
	}
	void set_next(Node* t)
	{
		next = t;
	}
	Node* get_next()
	{
		return next;
	}
	int get_data()
	{
		return data;
	}
	void set_data(int data)
	{
		this->data = data;
	}
};
class Queue
{
private:
	int data;
	int front;
	int rear;
	Node* *q;
	int size;
public:
	Queue()
	{
		size = 10;
		front, rear = 0;
		q = new Node* [size];
	}
	void enqueue(Node *);
	Node* dequeue();
	bool isEmpty();
};
void Queue::enqueue(Node * t)
{
	if ((rear + 1) % size == front)
		cout << "The queue is Full" << endl;
	else
	{
		rear = (rear + 1) % size;
		q[rear] = t;
	}
}
Node* Queue::dequeue()
{
	Node* x = nullptr;
	if ((front + 1) % size == rear)
		cout << "The queue is empty" << endl;
	else
	{
		front = (front + 1) % size;
		x = q[front];
	}
	return x;
}
bool Queue::isEmpty()
{
	if (front == rear)
		return true;
	else
		return false;
}
