#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, K, X;

	cin >> N >> M >> K >> X;

	vector<vector<int>> graph(N + 1);
	vector<bool> visit(N + 1, false);
	vector<int> count(N + 1, -1);

	for (int i = 0; i < M; ++i)
	{
		int n1, n2;

		cin >> n1 >> n2;

		graph[n1].push_back(n2);
	}

	queue<int> q;
	q.push(X);
	visit[X] = true;
	count[X] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto& e : graph[cur])
		{
			if (visit[e] == false)
			{
				visit[e] = true;
				q.push(e);
				count[e] = count[cur] + 1;
			}
		}
	}

	int cities_count = 0;
	for (int i = 1; i < count.size(); ++i)
	{
		if (count[i] == K)
		{
			cout << i << '\n';
			++cities_count;
		}
	}

	if (cities_count == 0)
		cout << -1;


}