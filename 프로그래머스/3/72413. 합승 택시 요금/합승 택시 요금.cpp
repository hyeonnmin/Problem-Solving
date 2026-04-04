#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int node;
    int distance;
    
    bool operator < (const Edge& others) const
    {
        return distance > others.distance;
    }
};

void Texi (vector<vector<Edge>>& graph, vector<int>& distance, vector<bool>& visits, int start)
{
    priority_queue<Edge> pq;
    visits[start];
    distance[start] = 0;
    
    for(auto& e : graph[start])
    {
        int new_distance = distance[start] + e.distance;
        if (new_distance < distance[e.node])
        {
            pq.push({e.node, new_distance});
        }
    }
    
    while(!pq.empty())
    {
        Edge edge = pq.top();
        pq.pop();
        
        if (distance[edge.node] > edge.distance)
            distance[edge.node] = edge.distance;
        
        for(auto& e : graph[edge.node])
        {
            int new_distance = distance[edge.node] + e.distance;
            if (new_distance < distance[e.node])
            {
                pq.push({e.node, new_distance});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    vector<vector<Edge>> graph(n);
    for(int i = 0; i < fares.size(); ++i)
    {
        int c = fares[i][0] - 1;
        int d = fares[i][1] - 1;
        int f = fares[i][2];
        
        graph[c].push_back({d, f});
        graph[d].push_back({c, f});
    }
    
    vector<int> distance_s (n, INT32_MAX);
    vector<bool> visits_s (n, false);
    Texi(graph, distance_s, visits_s, s - 1);

    vector<int> distance_a (n, INT32_MAX);
    vector<bool> visits_a (n, false);
    Texi(graph, distance_a, visits_a, a - 1);
    
    vector<int> distance_b (n, INT32_MAX);
    vector<bool> visits_b (n, false);
    Texi(graph, distance_b, visits_b, b - 1);
    
    int min_cost = INT32_MAX;
    for(int i = 0; i < n; ++i)
    {
        int cur_cost = distance_s[i] + distance_a[i] + distance_b[i];
        min_cost = min_cost > cur_cost ? cur_cost : min_cost;
    }
    answer = min_cost;
    
    return answer;
}