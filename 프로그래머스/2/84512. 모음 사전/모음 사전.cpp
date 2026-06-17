#include <string>
#include <vector>
#include <iostream> 

using namespace std;

int solution(string word) {
    int answer = 0;
    
    int count = 0;
    vector<char>dict = {' ', 'A', 'E', 'I', 'O', 'U'};
    vector<int> digit(5, 0);
    
    string comp = "";
    while(comp != word)
    {
        ++count;
        digit[4] += 1;
        
        if (digit[3] == 0)
            swap(digit[3], digit[4]);
        if (digit[2] == 0)
            swap(digit[2], digit[3]);
        if (digit[1] == 0)
            swap(digit[1], digit[2]);
        if (digit[0] == 0)
            swap(digit[0], digit[1]);
        
        if (digit[4] == 6)
        {
            digit[4] = 0;
            digit[3] += 1;
            if (digit[3] == 6)
            {
                digit[3] = 0;
                digit[2] += 1;
                if (digit[2] == 6)
                {
                    digit[2] = 0;
                    digit[1] += 1;
                    if (digit[1] == 6)
                    {
                        digit[1] = 0;
                        digit[0] += 1;
                    }
                }
            }
        }
        comp = "";
        for(int i = 0; i <5; ++i)
        {
            if(dict[digit[i]] != ' ')
                comp += dict[digit[i]];
        }
    }
    answer = count;
    
    return answer;
}