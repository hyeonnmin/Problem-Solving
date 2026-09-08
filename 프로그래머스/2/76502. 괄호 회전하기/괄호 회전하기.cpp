#include <string>
#include <vector>
#include <stack> 
#include <iostream> 

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size(); ++i)
    {
        stack<char> sub;
        bool check = true;
        for(int j = 0; j < s.size(); ++j)
        {
            int idx = (i + j) % s.size();
            if(s[idx] == '[' || s[idx] == '(' || s[idx] == '{')
            {
                sub.push(s[idx]);
            }
            else
            {
                if (sub.empty())
                {
                    check = false;
                    break;
                }
                else
                {
                    if(s[idx] == ']' && sub.top() == '[')
                    {
                        sub.pop();
                    }
                    else if(s[idx] == '}' && sub.top() == '{')
                    {
                        sub.pop();
                    }
                    else if(s[idx] == ')' && sub.top() == '(')
                    {
                        sub.pop();
                    }
                }
            }
        }
        if(check && sub.empty())
            answer++;
    }

    
    return answer;
}