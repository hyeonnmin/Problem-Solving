#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visits(n, false);
    
    int count = 0;
    int net_count = 0;
    while (count != n)
    {
        queue<int> q;        
        for(int i = 0; i < n; ++i)
        {
            if (visits[i] == false)
            {
                q.push(i);
                visits[i] = true;
                ++count;
                ++net_count;
                break;
            }
        }
        
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            for(int i = 0; i < n; ++i)
            {
                if (i != f && visits[i] == false && computers[f][i] == 1)
                {
                    q.push(i);
                    visits[i] = true;
                    ++count;
                }
            }
        }
    }
    
    
    answer = net_count;
    return answer;
}