#include <string>
#include <vector>

using namespace std;

void backTracking(vector<int>& numbers, int target, int idx, int curNumber, int& count)
{
    if(numbers.size() == idx)
    {
        if (target == curNumber)
            ++count;
        return;
    }
    
    backTracking(numbers, target, idx + 1, curNumber + numbers[idx], count);
    backTracking(numbers, target, idx + 1, curNumber - numbers[idx], count);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    backTracking(numbers, target, 0, 0, answer);
    
    
    
    return answer;
}