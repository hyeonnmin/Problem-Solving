#include <iostream> 
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> m;
    
    for(auto& e : participant)
        m[e]++;
    
    for(auto& e : completion)
        m[e]--;
    
    for(auto& e : m)
    {
        if (e.second != 0)
            answer = e.first;
    }
    
    return answer;
}