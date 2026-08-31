#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    vector<int> record(n + 1);
    
    for(int i = n; i >= 0; --i)
    {
        if(i == n)
            record[i] = 1;
        else if (i == n - 1)
            record[i] = 1;
        else
            record[i] = (record[i + 1] + record[i + 2]) % 1234567;
    }
    
    answer = record[0];
    
    return answer;
}