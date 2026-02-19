#include <iostream>

using namespace std;

int capacity = 10000;

class Array
{
private:
	int n;
	int* arr;
public:
	Array()
		:n{0}, arr{new int[capacity]}
	{ }
	void addBack(int value)
	{
		arr[n] = value;
		n++;
	}
	int removeBack()
	{
		if (n == 0)
			return -1;
		else
		{
			n--;
			return arr[n];
		}
	}
	int front()
	{
		if (n == 0)
			return -1;
		else
			return arr[n - 1];
	}
	~Array()
	{
		delete[] arr;
	}
};

class ArrayStack
{
private:
	Array* array;
	int n;
public:
	ArrayStack()
		:array{new Array}, n{0}
	{ }
	void push(int value)
	{
		array->addBack(value);
		++n;
	}
	void pop()
	{
		if (n == 0)
			cout << "-1" << endl;
		else
		{ 
			cout << array->removeBack() << '\n';
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
	void top()
	{
		cout << array->front() << '\n';
	}
	~ArrayStack()
	{
		delete array;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ArrayStack s;
	int n;
	cin >> n;

	string cmd;
	for (int i = 0; i < n; ++i)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			int value;
			cin >> value;
			s.push(value);
		}
		else if (cmd == "pop")
			s.pop();
		else if (cmd == "size")
			s.size();
		else if (cmd == "empty")
			s.empty();
		else if (cmd == "top")
			s.top();
	}
}