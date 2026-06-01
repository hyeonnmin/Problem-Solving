#include <vector>
#include <unordered_map> 
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int size = nums.size() / 2;
    
    unordered_map<int, bool> m; 
    
    int count = 0;
    for(auto& e : nums)
    {
        if (m.find(e) == m.end())
        {
            m[e] = true;
            ++count;
        }
    }
    answer = size > count ? count : size;
    
    return answer;
}