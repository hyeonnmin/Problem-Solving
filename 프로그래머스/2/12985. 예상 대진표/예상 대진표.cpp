#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    int start = 1;
    int mid = n / 2;
    int end = n;
    
    int depth = 0;
    while(n != 1)
    {
        n /= 2;
        ++depth;
    }
    
    int min_value = min(a, b);
    int max_value = max(a, b);
    
    while(mid != 0)
    {
        if(min_value > mid)
            start = mid + 1;
        else if (max_value <= mid)
            end = mid;
        else
            break;
        --depth;
        mid = (start + end) / 2;
    }
    answer = depth;
    
    return answer;
}