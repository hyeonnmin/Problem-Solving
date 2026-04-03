#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n + 1);
    vector<int> visits(n + 1, -1);
    
    for(int i = 0; i < edge.size(); ++i)
    {
        int a = edge[i][0];
        int b = edge[i][1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue<int> q;
    int max_distance = 0;
    
    q.push(1);
    visits[1] = 0;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(auto & e : graph[cur])
        {
            if (visits[e] == -1)
            {
                q.push(e);
                visits[e] = visits[cur] + 1;
                max_distance = visits[e] > max_distance ? visits[e] : max_distance;
            }
        }
    }

    for(auto & e : visits)
        answer += max_distance == e ? 1 : 0;
    
    return answer;
}