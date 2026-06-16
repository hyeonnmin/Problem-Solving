#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());    
    
    int size = citations.size();
    vector<int> record(citations[size - 1] + 1, 0);
    int count = size;
    
    int pre = -1;
    for(auto& e : citations)
    {
        int cur = e;
        for(int i = pre + 1; i <= cur; ++i)
        {
            if (i == count)
                return i;
            record[i] = count;
        }
        pre = cur;
        --count;
    }
    
    for(int i = 0; i < record.size(); ++i)
        answer = max(answer, min(i, record[i]));   
    
    return answer;
}