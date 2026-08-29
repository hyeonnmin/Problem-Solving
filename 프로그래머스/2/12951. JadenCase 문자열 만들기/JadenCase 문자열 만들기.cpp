#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    char pre = ' ';
    for(auto& e : s)
    {
        if(pre == ' ')
        {
            if(int(e) >= int('a') && int(e) <= int('z'))
            {
                e += (int('A') - int('a'));
            }
        }
        else
        {
            if(int(e) >= int('A') && int(e) <= int('Z'))
                e -= (int('A') - int('a'));
        }
        pre = e;
    }
    answer = s;
    
    return answer;
}