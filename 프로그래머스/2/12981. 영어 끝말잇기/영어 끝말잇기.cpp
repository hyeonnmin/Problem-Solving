#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(0);
    
    set<string> s;
    
    string pre = words[0];
    s.insert(pre);
    for(int i = 1; i < words.size(); ++i)
    {
        string cur = words[i];
        if(pre[pre.size() - 1] != cur[0])
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        if(s.find(cur) != s.end())
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        
        s.insert(cur);
        pre = cur;
    }
    
    return answer;
}