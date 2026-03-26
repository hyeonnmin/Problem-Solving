#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;

	vector<vector<int>> tree(N+1);
	vector<int> record_parent(N+1, 0);
	record_parent[1] = -1;
	for (int i = 0; i < N - 1; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		for (auto& e : tree[num])
		{
			if (record_parent[e] == 0)
			{
				record_parent[e] = num;
				q.push(e);
			}
		}
	}

	for (int i = 2; i < record_parent.size(); ++i)
	{
		cout << record_parent[i] << '\n';
	}
}