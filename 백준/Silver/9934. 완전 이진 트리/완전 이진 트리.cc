#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void inorder_traversal(int cur, vector<int>& tree, vector<int>& inorder)
{
	static int count = 0;

	if (cur >= int(tree.size()))
		return;

	inorder_traversal(cur * 2, tree, inorder);
	tree[cur] = inorder[count];
	++count;
	inorder_traversal(cur * 2 + 1, tree, inorder);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K;
	cin >> K;
	int n = pow(2, K) - 1;

	vector<int> tree(n + 1, 0);	
	vector<int> inorder;

	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		inorder.push_back(input);
	}

	inorder_traversal(1, tree, inorder);

	int count = 1;
	for (int i = 1; i < tree.size(); ++i)
	{
		if (pow(2, count) == i)
		{
			cout << '\n';
			++count;
		}

		cout << tree[i] << " ";
	}

}