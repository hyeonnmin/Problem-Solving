#include <string>
#include <vector>
#include <unordered_map>
#include <iostream> 

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, int> m;
    for(auto& e : clothes)
    {
        m[e[1]]++;
    }
    
    answer = 1;
    for(auto& e : m)
        answer *= (e.second + 1);
    answer--;
    
    return answer;
}