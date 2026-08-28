#include <string>
#include <vector>
#include <iostream> 
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    
    s += ' ';
    string sub = "";
    int max_value = INT_MIN;
    int min_value = INT_MAX;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] != ' ')
            sub += s[i];
        else
        {
            int cur = stoi(sub);
            
            max_value = max(cur, max_value);
            min_value = min(cur, min_value);
            
            sub = "";
        }
    }
    
    answer += to_string(min_value);
    answer += ' ';
    answer += to_string(max_value);
    
    return answer;
}