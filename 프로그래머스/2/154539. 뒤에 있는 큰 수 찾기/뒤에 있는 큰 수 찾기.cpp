#include <string>
#include <vector>
#include <stack> 

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    int length = numbers.size();
    vector<int> answer(length, -1);
    
    stack<int> s;
    
    for(int i = length - 1; i >= 0; i--)
    {
        if(s.empty())
        {
            s.push(numbers[i]);
        }
        else
        {
            int cur = numbers[i];
            int top = s.top();
            
            while(cur >= top)
            {
                s.pop();
                if(s.empty())
                    break;
                else
                {
                    top = s.top();
                }
            }
            
            if(!s.empty())
                answer[i] = top;
            
            s.push(cur);
        }
    }
    
    return answer;
}