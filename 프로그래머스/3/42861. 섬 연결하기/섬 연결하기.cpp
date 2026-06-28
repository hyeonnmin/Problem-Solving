#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& v1, const vector<int>& v2)
{
    return v1[2] < v2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), comp);
    
    vector<int> visits(n, -1);
    int total_cost = 0;
    for(int i = 0; i < costs.size(); ++i)
    {
        int a = costs[i][0];
        int b = costs[i][1];
        
        if (visits[a] == -1 && visits[b] == -1)
        {
            visits[a] = a;
            visits[b] = a;
            total_cost += costs[i][2];
        }
        else if (visits[a] == -1)
        {
            visits[a] = visits[b];
            total_cost += costs[i][2];
        }
        else if (visits[b] == -1)
        {
            visits[b] = visits[a];
            total_cost += costs[i][2];
        }
        else if (visits[a] != visits[b])
        {
            int sub = visits[b];
            for(auto& e : visits)
            {
                if (e == sub)
                    e = visits[a];
            }
            total_cost += costs[i][2];

        }
            
    }
    
    answer = total_cost;
    
    return answer;
}