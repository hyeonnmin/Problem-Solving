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

	vector<vector<int>> graph(N);
	vector<int> count(N, 0);
	vector<int> cost(N, 0);

	for (int i = 0; i < N; ++i)
	{
		int c;
		cin >> c;
		cost[i] = c;

		int a;
		cin >> a;
		while (a != -1)
		{
			count[i]++;
			graph[a - 1].push_back(i);

			cin >> a;
		}
	}

	queue<int> q;
	vector<int> total_cost(N, 0);

	for (int i = 0; i < N; ++i)
	{
		if (count[i] == 0)
		{
			q.push(i);
			total_cost[i] = cost[i];
		}
	}
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto& e : graph[cur])
		{
			total_cost[e] = total_cost[e] < total_cost[cur] + cost[e] ? total_cost[cur] + cost[e] : total_cost[e];
			--count[e];
			if (count[e] == 0)
				q.push(e);
		}
	}


	for (auto& e : total_cost)
		cout << e << " ";
}