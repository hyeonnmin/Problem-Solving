#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int size = nums.size() / 2;
    
    vector<bool> visit(2000001, false);
    int count = 0;
    for(auto& e : nums)
    {
        if (visit[e] == false)
        {
            ++count;
            visit[e] = true;
        }
    }
    
    answer = size > count ? count : size;
    
    return answer;
}