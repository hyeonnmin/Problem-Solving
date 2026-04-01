#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int parent = -1;
	vector<int> child;
};

int count_leaf(vector<Node>& tree, int cur)
{
	if (tree[cur].child.size() == 0)
		return 1;

	int sum = 0;
	for (auto& e : tree[cur].child)
	{
		sum += count_leaf(tree, e);
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<Node> tree(N);

	int root;
	for (int i = 0; i < N; ++i)
	{
		int parent;
		cin >> parent;

		if (parent == -1)
			root = i;
		else
		{
			tree[parent].child.push_back(i);
			tree[i].parent = parent;
		}
	}

	int delete_node;
	cin >> delete_node;

	int parent = tree[delete_node].parent;

	if (parent == -1)
	{
		cout << 0;
		return 0;
	}
	else
	{
		for (int i = 0; i < tree[parent].child.size(); ++i)
		{
			if (tree[parent].child[i] == delete_node)
				tree[parent].child.erase(tree[parent].child.begin() + i);
		}
	}

	cout << count_leaf(tree, root);

}