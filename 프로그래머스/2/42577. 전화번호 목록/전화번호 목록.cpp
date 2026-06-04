#include <string>
#include <vector>
#include <unordered_map>
#include <iostream> 

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, bool> m;
    for(auto& e : phone_book)
        m[e] = true;
    
    for(auto& e : m)
    {
        string sub = "";
        string cur = e.first;
        for(int i = 0; i < cur.size() - 1; ++i)
        {
            sub += cur[i];
            if (m.find(sub) != m.end())
                return false;
        }
    }
    
    return answer;
}