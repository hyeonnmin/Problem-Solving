#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<int> container;
    for(auto& e : s)
    {
        if(e == '(')
            container.push(e);
        else
        {
            if (container.empty())
                return false;
            else
                container.pop();
        }
    }
    
    if(!container.empty())
        return false;
    
    return answer;
}