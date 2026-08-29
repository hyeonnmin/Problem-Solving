#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int pre = 0;
    int cur = 1;
    
    for(int i = 2; i <= n; ++i)
    {
        int sub = (pre + cur) % 1234567;
        pre = cur;
        cur = sub;
    }
    
    answer = cur;
    
    return answer;
}