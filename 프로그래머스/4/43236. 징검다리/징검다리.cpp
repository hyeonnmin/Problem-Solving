#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int check_rock(vector<int>& rocks, int distance, int end_point)
{
    int count = 0;
    int start = 0;
    for(auto& e : rocks)
    {
        int cur_dis = e - start;
        if(cur_dis < distance)
            count++;
        else
            start = e;
    }
    
    if(end_point - start < distance)
        ++count;
    
    return count;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    
    int start = 0;
    int end = distance;
    
    while(start <= end)
    {
        int mid = (start + end) / 2;
        int count = check_rock(rocks, mid, distance);
        
        if(count > n)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            answer = mid;
        }
    }
    
    return answer;
}