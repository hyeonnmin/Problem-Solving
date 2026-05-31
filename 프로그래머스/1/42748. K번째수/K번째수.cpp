#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto& e : commands)
    {
        int i = e[0] - 1;
        int j = e[1] - 1;
        int k = e[2] - 1;
        
        vector<int> partion;
        for(int s = i; s <= j; ++s)
            partion.push_back(array[s]);
        sort(partion.begin(), partion.end()); 
        
        answer.push_back(partion[k]);
    }
    
    return answer;
}