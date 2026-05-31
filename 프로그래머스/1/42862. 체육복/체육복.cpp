#include <string>
#include <vector>
#include <algorithm> 
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(), lost.end()); 
    
    answer = n - lost.size(); 
    vector<bool> check(n, false);
    
    for(auto& e : reserve)
        check[e - 1] = true;
    
    vector<int> sub;
    for(auto& e : lost)
    {
        if (check[e - 1] == true)
        {
            ++answer; 
            check[e - 1] = false;
        }
        else
            sub.push_back(e - 1);
    }
    
    for(auto& e : sub)
    {
        
        if (e - 1 >= 0)
        {
            int pre_idx = e - 1;
            if (check[pre_idx] == true)
            {
                answer++;
                check[pre_idx] = false;
                continue;
            }
        }
        if (e + 1 < n)
        {
            int next_idx = e + 1;
            if (check[next_idx] == true)
            {
                answer++;
                check[next_idx] = false;
                continue;
            }
        }
    }
    
    return answer;
}