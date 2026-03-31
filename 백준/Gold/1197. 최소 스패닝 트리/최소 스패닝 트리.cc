#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
	int node1;
	int node2;
	int value;
};

struct compare
{
	bool operator()(const Edge& e1, const Edge& e2)
	{
		return e1.value > e2.value;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int V, E;
	cin >> V >> E;

	vector<vector<int>> graph(V + 1);
	vector<bool> visit_node(V + 1, false);
	vector<Edge> edges;

	int min_value = INT32_MAX;
	int start_node = -1;
	for (int i = 0; i < E; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		
		Edge edge{ A, B, C };
		edges.push_back(edge);

		graph[A].push_back(i);
		graph[B].push_back(i);

		if (min_value > C)
		{
			min_value = C;
			start_node = A;
		}
	}

	priority_queue<Edge, vector<Edge>, compare> pq; 

	visit_node[start_node] = true;
	for (auto& e : graph[start_node])
	{
		pq.push(edges[e]);
	}

	int count = 0;
	while (!pq.empty())
	{
		Edge edge = pq.top();
		int node;
		if (visit_node[edge.node1] == true && visit_node[edge.node2] == true)
			pq.pop();
		else
		{
			if (visit_node[edge.node1] == false)
				node = edge.node1;
			else
				node = edge.node2;

			count += edge.value;
			visit_node[node] = true;

			for (auto& e : graph[node])
			{
				Edge edge = edges[e];
				if (visit_node[edge.node1] == false || visit_node[edge.node2] == false)
					pq.push(edge);
			}
		}
	}
	cout << count;

}