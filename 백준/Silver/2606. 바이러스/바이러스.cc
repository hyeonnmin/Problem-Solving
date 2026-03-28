#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int node_count;
	cin >> node_count;
	
	vector<vector<int>> graph(node_count + 1);
	vector<char> visit(node_count + 1, false);

	int edge_count;
	cin >> edge_count;

	for (int i = 0; i < edge_count; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;

		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}
	int virus_count = 0;

	queue<int> q;
	q.push(1);
	visit[1] = true;

	while (!q.empty())
	{
		int e = q.front();
		q.pop();

		for (auto& c : graph[e])
		{
			if (visit[c] == false)
			{
				visit[c] = true;
				++virus_count;
				q.push(c);
			}
		}
	}
	
	cout << virus_count;
}