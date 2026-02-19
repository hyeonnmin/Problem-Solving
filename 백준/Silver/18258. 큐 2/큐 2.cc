#include <iostream>

using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node(int value)
		:value{ value }, next{nullptr}
	{ }
	~Node()
	{
	}
};

class SinglyLinkedList {
public:
	Node* head;
	Node* tail;
	
	SinglyLinkedList()
		:head{nullptr}, tail{nullptr}
	{ }

	void addBack(int value)
	{
		Node* n = new Node{ value };

		if (head == nullptr)
		{
			head = n;
			tail = n;
		}
		else if (head == tail)
		{
			head->next = n;
			tail = n;
		}
		else
		{
			tail->next = n;
			tail = n;
		}
	}
	int removeFront()
	{
		if (head == nullptr)
			return -1;
		else if (head == tail)
		{
			int value = head->value;
			delete head;
			head = nullptr;
			tail = nullptr;
			return value;
		}
		else
		{
			Node* sub = head;
			int value = sub->value;
			head = head->next;
			delete sub;
			return value;
		}
	}
	int getFront()
	{
		if (head == nullptr)
			return -1;
		else
			return head->value;
	}

	int getBack()
	{
		if (tail == nullptr)
			return -1;
		else
			return tail->value;
	}

	~SinglyLinkedList()
	{
		while (head != nullptr)
		{
			this->removeFront();
		}
	}
};

class LinkedListQueue
{
public:
	SinglyLinkedList* linkedList;
	int n;
	LinkedListQueue()
		:linkedList{new SinglyLinkedList}, n{0}
	{ }
	void push(int value)
	{ 
		linkedList->addBack(value);
		++n;
	}
	void pop()
	{ 
		if (n == 0)
			cout << "-1" << '\n';
		else
		{
			cout << linkedList->removeFront() << '\n';
			--n;
		}
	}
	void size()
	{ 
		cout << n << '\n';
	}
	void empty()
	{ 
		if (n == 0)
			cout << "1" << '\n';
		else
			cout << "0" << '\n';
	}
	void front()
	{
		if (n == 0)
			cout << "-1" << '\n';
		else
			cout << linkedList->getFront() << '\n';
	}
	void back()
	{ 
		if (n == 0)
			cout << "-1" << '\n';
		else
			cout << linkedList->getBack() << '\n';;
	}
	~LinkedListQueue()
	{
		delete linkedList;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	LinkedListQueue q;
	string order;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> order;
		if (order == "push")
		{
			int value;
			cin >> value;
			q.push(value);
		}
		else if (order == "front")
			q.front();
		else if (order == "back")
			q.back();
		else if (order == "size")
			q.size();
		else if (order == "empty")
			q.empty();
		else if (order == "pop")
			q.pop();

	}
}