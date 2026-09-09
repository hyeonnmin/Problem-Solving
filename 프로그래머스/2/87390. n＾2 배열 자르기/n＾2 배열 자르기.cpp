#include <string>
#include <vector>
#include <iostream> 

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    
    for(long long i = left; i <= right; ++i)
    {
        int r = i / n;
        int c = i % n;
        
        answer.push_back(max(r, c) + 1);
    }
    
    return answer;
}