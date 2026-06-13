#include <string>
#include <vector>
#include <cmath> 
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int sqrtYellow = sqrt(yellow);
    cout << sqrtYellow;
    
    for(int i = 1; i <= sqrtYellow; ++i)
    {
        if (yellow % i == 0)
        {
            int h = i;
            int w = yellow / h;
            
            int brownCount = 2 * (h + w) + 4;
            
            if(brownCount == brown)
            {
                answer.push_back(w + 2);
                answer.push_back(h + 2);
                return answer;
            }
        }
    }
    
    return answer;
}