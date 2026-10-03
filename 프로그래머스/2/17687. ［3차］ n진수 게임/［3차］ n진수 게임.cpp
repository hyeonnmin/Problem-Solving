#include <string>
#include <vector>
#include <iostream> 

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string record = "";
    vector<char> dict(n);
    for(int i = 0; i < n; ++i)
    {
        if(i < 10)
            dict[i] = '0' + i;
        else
            dict[i] = 'A' + (i - 10);
    }
    
    
    int cur_number = 0;
    int idx = 0;
    while(answer.size() < t)
    {
        string s = "";
        int cur = cur_number;
        s += dict[cur % n];
        cur /= n;
        while(cur != 0)
        {
            s += dict[cur % n];
            cur /= n;
        }
        
        for(int i = s.size() - 1; i >= 0; --i)
        {
            if((idx % m) + 1 == p)
            {
                answer += s[i];
            }
            ++idx;
        }
        
        ++cur_number;
    }
    
    answer.resize(t);
    
    return answer;
}