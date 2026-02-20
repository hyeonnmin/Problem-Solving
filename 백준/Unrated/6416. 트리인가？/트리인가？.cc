#include <iostream>
#include <vector>	
#include <stack>

using namespace std;

class Node
{
public:
	int data;
	bool visited;
	Node* parent;
	vector<Node*> child;

	Node()
		:visited{false}, parent{ nullptr }
	{ }
	Node(int data)
		:data{data}, visited{false}, parent{nullptr}
	{ }
	void insertChild(Node* input)
	{
		child.push_back(input);
	}
	void deleteChild(Node* input)
	{
		for (int i = 0; i < child.size(); ++i)
		{
			if (child[i] == input)
			{
				child.erase(this->child.begin() + i);
				break;
			}
		}
	}
	~Node()
	{	}
};

class Tree
{
private:
	Node* root;
	vector<Node*> node_list;
	bool checkTree = true;
public:
	Tree()
		:root{nullptr}
	{ }
	Tree(int data)
		:root{ new Node(data) }
	{
		node_list.push_back(root);
	}
	void setRoot(int data)
	{
		root = new Node{ data };
		node_list.push_back(root);
	}
	Node* getRoot()
	{
		return root;
	}

	void insertNode(int parent_data, int data)
	{
		Node* par = findNode(parent_data);
		if (par == nullptr)
		{	
			Node* sub = new Node(parent_data);
			par = sub;
			node_list.push_back(sub);
		}
		Node* chi = findNode(data);
		if (chi == nullptr)
		{
			Node* sub = new Node(data);
			chi = sub;
			node_list.push_back(sub);
		}
		else if (chi->parent != nullptr)
			checkTree = false;

		par->child.push_back(chi);
		chi->parent = par;
	}
	
	bool isTree()
	{
		if (node_list.empty())
			return true;

		if (checkTree == false)
			return false;

		int count = 0;
		for (auto& n : node_list)
		{
			if (n->parent == nullptr)
				++count;
		}
		if (count != 1)
			return false;
		return true;

		Node* root = node_list[0];
		while (root->parent)
			root = root->parent;

		stack<Node*> s;
		s.push(root);
		root->visited = true;
		while (!s.empty())
		{
			Node* cur = s.top();
			s.pop();
			for (auto& c : cur->child)
			{
				s.push(c);
				if (c->visited == true)
					return false;

				c->visited = true;
			}
		}
		for (auto& n : node_list)
		{
			if (n->visited == false)
				return false;
		}
		return true;

	}

	void delNode(int data)
	{

	}
	Node* findNode(int data)
	{
		for (auto& n : node_list)
		{
			if (n->data == data)
				return n;
		}

		return nullptr;
	}
	void printChild(int data){}
	int countDepth(int data){}
	void preorder(Node* node){}
	void postorder(Node* node){}

	~Tree()
	{
		for (auto& n : node_list)
			delete n;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int u, v;
	int count = 0;
	
	while (true)
	{
		Tree t;
		while (true)
		{
			cin >> u >> v;
			if ((u == 0 && v == 0) || (u == -1 && v == -1))
				break;
			t.insertNode(u, v);
		}
		if (u == -1 && v == -1)
			break;

		++count;
		if (t.isTree())
			cout << "Case " << count << " is a tree.\n";
		else
			cout << "Case " << count << " is not a tree.\n";


	}
}