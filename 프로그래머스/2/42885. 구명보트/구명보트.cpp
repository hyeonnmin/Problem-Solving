#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    vector<int> peoples(241, 0);
    for(auto& e : people)
        peoples[e]++;
    
    for(int i = 240; i >= 1; --i)
    {
        int restWeight = limit - i;
        
        
        if(peoples[i] != 0)
        {
            for(int j = restWeight; j >= 1; --j)
            {
                if (j == i)
                {
                    while(peoples[j] >= 2)
                    {
                        peoples[j] -= 2;
                        answer++;
                    }
                }
                else
                {
                    while(peoples[j] != 0 && peoples[i] != 0)
                    {
                        peoples[j]--;
                        peoples[i]--;
                        answer++;
                    }
                }
            }
            while(peoples[i] != 0)
            {
                peoples[i]--;
                answer++;
            }
        }
    }
    
    return answer;
}