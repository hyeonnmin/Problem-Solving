#include <string>
#include <vector>
#include <map> 
#include <iostream> 
#include <algorithm> 

using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
    return p1.second > p2.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    
    for(auto& e : tangerine)
        m[e]++;
    
    vector<pair<int, int>> v;
    for(auto& e : m)
        v.push_back(e);
    
    sort(v.begin(), v.end(), cmp);
    
    int count = 0;
    for(auto& e : v)
    {
        count += e.second;
        ++answer;
        
        if(k <= count)
            break;
    }
    
    return answer;
}