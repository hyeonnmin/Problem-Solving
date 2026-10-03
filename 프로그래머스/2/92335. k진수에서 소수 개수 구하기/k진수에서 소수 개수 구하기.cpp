#include <string>
#include <vector>
#include <iostream> 
#include <cmath>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    vector<int> record;
    record.push_back(0);

    while(n != 0)
    {
        record.push_back(n % k);
        n /= k;
    }
    
    long long number = 0;
    for(int i = record.size() - 1; i >= 0; --i)
    {
        int cur = record[i];
        
        if(cur != 0)
        {
            number *= 10;
            number += cur;
        }
        else
        {
            if (number != 0)
            {
                if(number > 1)
                {
                    bool check = true;
                    for(int i = 2; i <= sqrt(number); ++i)
                    {
                        if(number % i == 0)
                        {
                            check = false;
                            break;
                        }
                    }
                    if(check)
                        ++answer;
                }
                number = 0;
            }
        }
    }
    
    return answer;
}