#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int node;
    int value;
};

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<Edge>> maps(N);
    vector<bool> visits(N, false);
    vector<int> distance(N, INT32_MAX);
    
    for(int i = 0; i < road.size(); ++i)
    {
        int node1 = road[i][0] - 1;
        int node2 = road[i][1] - 1;
        int value = road[i][2];
        
        maps[node1].push_back({node2, value});
        maps[node2].push_back({node1, value});
    }

    int count = 0;
    distance[0] = 0;
    while(count != N)
    {
        int start_node;
        int dist = INT32_MAX;
        for(int i = 0; i < N; ++i)
        {
            if (visits[i] == false)
            {
                if (dist > distance[i])
                {
                    start_node = i;
                    dist = distance[i];
                }
            }
        }
        
        visits[start_node] = true;
        ++count;
        for(auto & e: maps[start_node])
        {
            distance[e.node] = distance[e.node] > distance[start_node] + e.value ? distance                                   [start_node] + e.value : distance[e.node];
            
        }
    }
    
    for(auto & e : distance)
        if (e <= K)
            answer++;
    return answer;
}