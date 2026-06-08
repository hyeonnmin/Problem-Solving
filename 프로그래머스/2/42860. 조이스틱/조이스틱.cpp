#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int count = 0;
    for(auto& e : name)
    {
        int up = e - 'A';
        int down = 'Z' - e + 1;
        count += min(up, down);
    }
    
    int leftRightCount = name.size() - 1;
    vector<bool> visits(name.size(), false);
    
    for(int i = 0; i < name.size(); ++i)
    {
        if (name[i] == 'A' && visits[i] == false)
        {
            visits[i] = true;
            int left_idx = i;
            int right_idx = i;
            for(int j = 0; j < name.size(); ++j)
            {
                left_idx = (left_idx - 1 + name.size()) % name.size();
                if(name[left_idx] != 'A')
                    break;
                visits[left_idx] = true;   
            }
            for(int j = 0; j < name.size(); ++j)
            {
                right_idx = (right_idx + 1) % name.size();
                if(name[right_idx] != 'A')
                    break;
                visits[right_idx] = true;   
            }
            if (left_idx >= right_idx)
            {
                leftRightCount = min(leftRightCount, left_idx);
                leftRightCount = min(leftRightCount, int(name.size()) - right_idx);
            }
            else
            {
                leftRightCount = min(leftRightCount, left_idx * 2 + (int(name.size()) - right_idx));
                leftRightCount = min(leftRightCount, left_idx  + (int(name.size()) - right_idx) * 2);
            }
        }

    }
    
    answer = count + leftRightCount;
    
    return answer;
}