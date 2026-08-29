#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int cur = 0;
    int itr = 1;
    while(cur < n)
    {
        cur += itr;
        ++itr;
    }
    
    for(int i = 1; i <= n; ++i)
    {
        cur -= (i - 1);
        
        while(cur < n)
        {
            cur += itr;
            ++itr;
        }
        if(cur == n)
            ++answer;
        
        
    }
    
    return answer;
}