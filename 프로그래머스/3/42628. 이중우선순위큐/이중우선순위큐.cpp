#include <string>
#include <vector>
#include <set>
#include <iostream> 

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    multiset<int> ms;
    for(auto& e : operations)
    {
        char order = e[0];
        
        string s = "";
        for(int i = 2; i < e.size(); ++i)
            s += e[i];
        int num = stoi(s);
        
        if(order == 'I')
            ms.insert(num);
        else if(num == -1 && !ms.empty())
            ms.erase(ms.begin());
        else if (!ms.empty())
            ms.erase(--ms.end());
    }
    
    if(ms.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*(--ms.end()));
        answer.push_back(*ms.begin());
    }
    
    return answer;
}