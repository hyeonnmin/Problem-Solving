#include <string>
#include <vector>
#include <map> 
#include <iostream> 
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& p1, pair<int, int>& p2)
{
    return p1.second > p2.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    map<int, int> m;
    
    string sub = "";
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] != '{' && s[i] != '}' && s[i] != ',')
        {
            sub += s[i];
        }
        else
        {
            if(sub != "")
            {
                m[stoi(sub)]++;
                sub = "";
            }
        }
    }
    
    
    vector<pair<int, int>> v;
    
    for(auto& e : m)
        v.push_back(e);
    
    sort(v.begin(), v.end(), compare);
    
    for(auto& e : v)
        answer.push_back(e.first);
    
    return answer;
}