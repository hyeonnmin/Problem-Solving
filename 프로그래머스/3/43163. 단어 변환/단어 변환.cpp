#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    int begin_idx = words.size();
    words.push_back(begin);
    
    int target_idx = -1;
    for(int i = 0; i < words.size(); ++i)
    {
        if (words[i] == target)
            target_idx = i;
    }
    
    if (target_idx == -1)
        return 0;
    
    vector<vector<int>> graph(words.size());
    for(int i = 0; i < words.size(); ++i)
    {
        string cur = words[i];
        for(int j = i + 1; j < words.size(); ++j)
        {
            string comp = words[j];
            int count = 0;
            for(int k = 0; k < cur.size(); ++k)
            {
                if (cur[k] == comp[k])
                    ++count;
            }
            if (count + 1 == cur.size())
            {
                graph[j].push_back(i);
                graph[i].push_back(j);
            }
        }
    }
    
    vector<int> visits(words.size(), -1);
    queue<int> q;
    q.push(begin_idx);
    visits[begin_idx] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        if (cur == target_idx)
            return visits[cur];
        
        for(auto & e : graph[cur])
        {
            if (visits[e] == -1)
            {
                q.push(e);
                visits[e] = visits[cur] + 1;
            }
        }
    }
    
    return answer;
}