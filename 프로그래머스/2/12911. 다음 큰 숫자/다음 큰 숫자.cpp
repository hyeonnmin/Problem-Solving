#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<char> binary;
    vector<char> rev_binary;
    
    while(n != 0)
    {
        if(n % 2 == 0)
            rev_binary.push_back('0');
        else
            rev_binary.push_back('1');
        n /= 2;
    }
    binary.push_back('0');
    for(int i = rev_binary.size() - 1; i >= 0; --i)
        binary.push_back(rev_binary[i]);
    
    char pre = '0';
    int count = 0;
    for(int i = binary.size() - 1; i >= 0; --i)
    {
        if(pre == '1' && binary[i] == '0')
        {
            binary[i] = '1';
            --count;
            
            for(int j = binary.size() - 1; j > binary.size() - 1 - count; --j)
                binary[j] = '1';
            for(int j = binary.size() - 1 - count; j > i; --j)
                binary[j] = '0';
            
            break;
        }
        
        if(binary[i] == '1')
            ++count;
        
        pre = binary[i];
    }
    
    int itr = 1;
    for(int i = binary.size() - 1; i >= 0; --i)
    {
        if(binary[i] == '1')
            answer += itr;
        itr *= 2;
    }

    return answer;
}