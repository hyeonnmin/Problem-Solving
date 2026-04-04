#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N);
	vector<int> count(N, 0);

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		a--, b--;

		graph[a].push_back(b);
		count[b]++;
	}

	priority_queue<int> pq;
	for (int i = 0; i < count.size(); ++i)
	{
		if (count[i] == 0)
			pq.push(i);
	}

	vector<int> result;
	while (!pq.empty())
	{
		int t = pq.top();
		result.push_back(t + 1);
		pq.pop();

		for (auto& e : graph[t])
		{
			count[e]--;
			if (count[e] == 0)
				pq.push(e);
		}
	}

	for (auto& e : result)
		cout << e << " ";
}