#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void BFS(vector<set<int>>& tree, vector<bool> visit, int cur)
{
	queue<int> q;
	q.push(cur);
	visit[cur] = true;

	while (!q.empty())
	{
		int top = q.front();
		cout << top << " ";
		q.pop();

		for (auto& e : tree[top])
		{
			if (visit[e] == false)
			{
				visit[e] = true;
				q.push(e);
			}
		}
	}

}

void DFS(vector<set<int>>& tree, vector<bool>& visit, int cur)
{
	visit[cur] = true;
	cout << cur << " ";

	for (auto& e : tree[cur])
	{
		if (visit[e] == false)
			DFS(tree, visit, e);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, V;
	cin >> N >> M >> V;

	vector<set<int>> tree(N + 1);
	vector<bool> visit_DFS(N + 1, false);
	vector<bool> visit_BFS(N + 1, false);

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		tree[a].insert(b);
		tree[b].insert(a);
	}

	DFS(tree, visit_DFS, V);
	cout << '\n';
	BFS(tree, visit_BFS, V);

}