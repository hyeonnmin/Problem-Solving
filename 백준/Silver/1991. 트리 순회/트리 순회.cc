#include <iostream>
#include <vector>

using namespace std;

struct Node {
	char e;
	int left_child = 0;
	int right_child = 0;
};

void pre_dfs(int cur, vector<Node>& t)
{
	int left_child = t[cur].left_child;
	int right_child = t[cur].right_child;

	cout << t[cur].e;
	if (left_child != 0)
		pre_dfs(left_child, t);
	if (right_child != 0)
		pre_dfs(right_child, t);
}

void in_dfs(int cur, vector<Node>& t)
{
	int left_child = t[cur].left_child;
	int right_child = t[cur].right_child;

	if (left_child != 0)
		in_dfs(left_child, t);
	cout << t[cur].e;
	if (right_child != 0)
		in_dfs(right_child, t);
}

void post_dfs(int cur, vector<Node>& t)
{
	int left_child = t[cur].left_child;
	int right_child = t[cur].right_child;

	if (left_child != 0)
		post_dfs(left_child, t);
	if (right_child != 0)
		post_dfs(right_child, t);
	cout << t[cur].e;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<Node> tree(N);
	for (int i = 0; i < N; ++i)
	{
		char a, b, c;
		cin >> a >> b >> c;

		tree[a - 'A'].e = a;
		if (b != '.')
			tree[a - 'A'].left_child = b - 'A';
		if (c != '.')
			tree[a - 'A'].right_child = c - 'A';
	}

	pre_dfs(0, tree);
	cout << '\n';
	in_dfs(0, tree);
	cout << '\n';
	post_dfs(0, tree);
}