#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> process;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); ++i)
    {
        process.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    answer = 1;
    while(true)
    {
        int idx = process.front().first;
        int priority = process.front().second;
        
        if (priority == pq.top())
        {
            if (idx == location)
                return answer;
            ++answer;
            pq.pop();
            process.pop();
        }
        else
        {
            process.pop();
            process.push({idx, priority});
        }
    }
    
    
    return answer;
}