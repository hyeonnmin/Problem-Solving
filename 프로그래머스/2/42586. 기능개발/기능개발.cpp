#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int cur_idx = 0;
    
    int size = progresses.size();
    
    while(cur_idx < size)
    {
        int count = 0;
        for(int i = 0; i < size; ++i)
            progresses[i] += speeds[i];
        while(progresses[cur_idx] >= 100 && cur_idx < size)
        {
            ++count;
            ++cur_idx;
        }
        if (count != 0)
            answer.push_back(count);
    }
    
    return answer;
}