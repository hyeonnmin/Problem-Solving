#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    
    int cur_weight = 0;
    int truck_idx = 0;
    while(true)
    {
        ++answer;
        for(int i = 0; i < q.size(); ++i)
        {
            pair<int, int> p = q.front();
            p.second--;
            q.pop();
            q.push(p);
        }
        
        if(q.front().second == 0)
        {
            cur_weight -= q.front().first;
            q.pop();
            if (q.empty() && truck_idx == truck_weights.size())
                return answer;
        }
        if(truck_idx < truck_weights.size() && weight - cur_weight >= truck_weights[truck_idx])
        {
            q.push({truck_weights[truck_idx], bridge_length});
            cur_weight += truck_weights[truck_idx];
            ++truck_idx;
        }
    }
    
    return answer;
}