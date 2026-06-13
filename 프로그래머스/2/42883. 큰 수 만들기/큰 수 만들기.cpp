#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<char> s;
    s.push(number[0]);
    for(int i = 1; i < number.size(); ++i)
    {
        char top = s.top();
        
        while(top < number[i] && k > 0)
        {
            s.pop();
            --k;
            
            if (s.empty())
                break;
            top = s.top();
        }
        s.push(number[i]);
    }
    while(k > 0)
    {
        s.pop();
        --k;
    }
    
    stack<char> sub;
    while(!s.empty())
    {
        sub.push(s.top());
        s.pop();
    }
    while(!sub.empty())
    {
        answer += sub.top();
        sub.pop();
    }
    return answer;
}