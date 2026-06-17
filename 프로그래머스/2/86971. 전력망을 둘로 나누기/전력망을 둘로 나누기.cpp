#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    vector<vector<int>> tree(n + 1);
    
    for(auto& e : wires)
    {
        int n1 = e[0];
        int n2 = e[1];
        
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    
    int count = n;
    for(auto& e : wires)
    {
        vector<bool> visits(n + 1, false);
        
        int n1 = e[0];
        int n2 = e[1];
        
        visits[n1] = true;
        visits[n2] = true;
        
        int count1 = 1;
        int count2 = 1;
        
        queue<int> q1;
        q1.push(n1);
        
        queue<int> q2;
        q2.push(n2);
        
        while(!q1.empty())
        {
            int f = q1.front();
            q1.pop();
            for(auto& l : tree[f])
            {
                if (visits[l] == false)
                {
                    visits[l] = true;
                    q1.push(l);
                    ++count1;
                }
            }
        }
        
        while(!q2.empty())
        {
            int f = q2.front();
            q2.pop();
            for(auto& l : tree[f])
            {
                if (visits[l] == false)
                {
                    visits[l] = true;
                    q2.push(l);
                    ++count2;
                }
            }
        }
        count = min(count, abs(count1 - count2));
        
        
        
    }
    
    answer = count;
    return answer;
}