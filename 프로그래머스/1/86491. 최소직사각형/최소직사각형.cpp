#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int w = 0;
    int h = 0;
    for(auto& e : sizes)
    {
        int max_value = max(e[0], e[1]);
        int min_value = min(e[0], e[1]);
        
        w = w < max_value ? max_value : w;
        h = h < min_value ? min_value : h;
    }
    
    answer = w * h;
    
    return answer;
}