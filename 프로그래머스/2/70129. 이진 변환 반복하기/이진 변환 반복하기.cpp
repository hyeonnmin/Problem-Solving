#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int idx = 0;
    int count = 0;
    while(s != "1")
    {
        ++idx;
        string sub;
        for(auto& e : s)
        {
            if(e == '1')
                sub += '1';
            else
                count++;
        }
        int length = sub.size();
        sub = "";
        while(length != 0)
        {
            int rest = (length % 2);
            if(rest == 1)
                sub += '1';
            else
                sub += '0';
            length /= 2;
        }
        
        s = "";
        for(int i = sub.size() - 1; i >= 0; --i)
        {
            s += sub[i];
        }
    }
    
    answer.push_back(idx);
    answer.push_back(count);
    
    return answer;
}