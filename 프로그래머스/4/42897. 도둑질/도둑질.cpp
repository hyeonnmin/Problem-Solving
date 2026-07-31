#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    int n = money.size();
    
    int pre = -1;
    int prepre = -1;
    for(int i = n - 2; i >= 0; --i)
    {
        if(i == n - 2)
            pre = money[i];
        else if (i == n - 3)
        {
            prepre = pre;
            pre = max(money[i], prepre);
        }
        else
        {
            int sub = pre;
            pre = max(money[i] + prepre, pre);
            prepre = sub;
        }
    }
    
    int pre_b;
    int prepre_b;
    for(int i = n - 1; i >= 1; --i)
    {
        if(i == n - 1)
            pre_b = money[i];
        else if (i == n - 2)
        {
            prepre_b = pre_b;
            pre_b = max(money[i], prepre_b);
        }
        else
        {
            int sub = pre_b;
            pre_b = max(money[i] + prepre_b, pre_b);
            prepre_b = sub;
        }
    }
    
    answer = max(pre, pre_b);
    
    return answer;
}