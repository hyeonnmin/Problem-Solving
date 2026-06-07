#include <string>
#include <vector>
#include <iostream>
#include <unordered_set> 

using namespace std;

void backTracking(vector<int>& nums, vector<bool>& visits, unordered_set<int>& s, int count, int cur_count, int cur_value)
{
    if(count == cur_count)
    {
        s.insert(cur_value);
        return;
    }
    
    for(int i = 0; i < nums.size(); ++i)
    {
        if(visits[i] == false)
        {
            visits[i] = true;
            cur_value *= 10;
            cur_value += nums[i];
            backTracking(nums, visits, s, count, cur_count + 1, cur_value);
            cur_value /= 10;
            visits[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    vector<int> nums;
    for(auto& e : numbers)
        nums.push_back(e - '0');
    
    int count = 0;
    unordered_set<int> s;
    vector<bool> visits(nums.size(), false);
    
    for(int i = 1; i <= nums.size(); ++i)
        backTracking(nums, visits, s, i, 0, 0);
    
    for(auto& e : s)
    {
        bool check = true;
        if(e >= 2)
        {
            for(int i = 2; i < e; ++i)
            {
                if((e % i) == 0)
                {
                    check = false;
                    break;
                }
            }
        }
        else
            check = false;
        
        count += (check == true ? 1 : 0);
    }
    answer = count;
    return answer;
}