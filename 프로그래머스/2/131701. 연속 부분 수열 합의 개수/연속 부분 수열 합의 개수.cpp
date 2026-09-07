#include <string>
#include <vector>
#include <map>
#include <iostream> 

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    map<int, bool> m;
    
    for(int i = 0; i < elements.size(); ++i)
    {
        int total_num = 0;
        for(int j = 0; j < elements.size(); ++j)
        {
            int idx = (i + j) % elements.size();
            total_num += elements[idx];
            m[total_num] = true;
        }
    }

    answer = m.size();
    return answer;
}