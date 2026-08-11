#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<int> arrows) {
    int answer = 0;
    
    vector<pair<int, int>> dir = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    
    map<pair<int, int>, int> m;    
    vector<pair<int, int>> edges;
    
    int count = 0;
    pair<int, int> start = {0, 0};
    int pre;
    
    if(m.find(start) == m.end())
    {
        m[start] = count;
        pre = count;
        ++count;
    }
    
    for(auto& e : arrows)
    {
        start = {start.first + dir[e].first, start.second + dir[e].second};
        
        if(m.find(start) == m.end())
        {
            m[start] = count;
            ++count;
        }
        int cur = m[start];
        edges.push_back({pre, cur});
        pre = cur;
        
        start = {start.first + dir[e].first, start.second + dir[e].second};
        
        if(m.find(start) == m.end())
        {
            m[start] = count;
            ++count;
        }
        cur = m[start];
        edges.push_back({pre, cur});
        pre = cur;
    }
    
    vector<vector<int>> graph(count);
    vector<bool> visits_node(count, false);
    map<pair<int, int>, bool> visits_edge;
        
    for(auto& e : edges)
    {
        int a = min(e.first, e.second);
        int b = max(e.first, e.second);
        
        if (visits_edge.find({a, b}) == visits_edge.end())
        {
            visits_edge[{a, b}] = false;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    
    stack<int> s;
    s.push(0);
    visits_node[0] = true;
    
    while(!s.empty())
    {
        int t = s.top();
        s.pop();
        
        for(auto& e : graph[t])
        {
            int a = min(e, t);
            int b = max(e, t);
            
            if(visits_edge[{a, b}] == false)
            {
                if(visits_node[e] == false)
                {
                    visits_node[e] = true;
                    s.push(e);
                }
                else
                {
                    ++answer;
                }
                visits_edge[{a, b}] = true;
            }
        }
    }
    
    return answer;
}