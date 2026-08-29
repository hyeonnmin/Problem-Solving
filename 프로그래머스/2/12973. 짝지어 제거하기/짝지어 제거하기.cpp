#include <iostream>
#include <string>
#include <stack> 

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    stack<char> sub;
    sub.push(s[0]);
    for(int i = 1; i < s.size(); ++i)
    {
        if(!sub.empty())
        {
            char t = sub.top();

            if(t == s[i])
                sub.pop();
            else
                sub.push(s[i]);
        }
        else
            sub.push(s[i]);
    }
    
    if(sub.empty())
        answer = 1;

    return answer;
}