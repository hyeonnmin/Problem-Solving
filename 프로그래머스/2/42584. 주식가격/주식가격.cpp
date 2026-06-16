#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    for(int i = 0; i < prices.size(); ++i)
    {
        int count = 0;
        int cur_num = prices[i];
        for(int j = i + 1; j < prices.size(); ++j)
        {
            count++;
            if (cur_num > prices[j])
                break;
        }
        answer[i] = count;
    }
    
    return answer;
}