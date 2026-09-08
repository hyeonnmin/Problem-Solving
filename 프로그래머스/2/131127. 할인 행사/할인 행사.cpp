#include <string>
#include <vector>
#include <unordered_map> 
#include <iostream> 

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> m;
    
    for(int i = 0; i < 10; ++i)
    {
        m[discount[i]]++;
    }
    
    bool check = true;
    for(int i = 0; i < want.size(); ++i)
    {
        if(m[want[i]] != number[i])
        {
            check = false;
            break;
        }
    }
    if(check)
        ++answer;
    
    for(int i = 10; i < discount.size(); ++i)
    {
        int del_idx = i - 10;
        m[discount[del_idx]]--;
        m[discount[i]]++;
        
        bool check = true;
        for(int i = 0; i < want.size(); ++i)
        {
            if(m[want[i]] != number[i])
            {
                check = false;
                break;
            }
        }
        if(check)
            ++answer;
    }
    
    return answer;
}