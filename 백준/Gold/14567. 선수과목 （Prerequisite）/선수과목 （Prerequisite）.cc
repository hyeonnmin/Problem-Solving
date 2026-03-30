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


	vector<vector<int>> graph(N + 1);
	vector<int> subject_year(N + 1, 0);
	vector<int> pre_count(N + 1, 0);

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;

		graph[A].push_back(B);
		pre_count[B]++;
	}

	queue<int> q;

	for (int i = 1; i < pre_count.size(); ++i)
	{
		if (pre_count[i] == 0)
		{
			q.push(i);
			subject_year[i] = 1;
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto& e : graph[cur])
		{
			--pre_count[e];

			if (pre_count[e] == 0)
			{
				q.push(e);
				subject_year[e] = subject_year[cur] + 1;
			}
			
		}
	}

	for (int i = 1; i < subject_year.size(); ++i)
		cout << subject_year[i] << " ";
}