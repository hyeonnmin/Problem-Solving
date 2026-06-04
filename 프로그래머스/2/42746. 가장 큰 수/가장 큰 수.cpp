#include <string>
#include <vector>
#include <algorithm>
#include <iostream> 

using namespace std;

bool comp(int i1, int i2)
{
    string s1 = to_string(i1);
    string s2 = to_string(i2);
    
    string mix_s1 = s1 + s2;
    string mix_s2 = s2 + s1;
    
    int mix_i1 = stoi(mix_s1);
    int mix_i2 = stoi(mix_s2);
    
    return mix_i1 > mix_i2;
    int size_s1 = s1.size();
    int size_s2 = s2.size();
    
    if (size_s1 < size_s2)
    {
        for(int i = 0; i < size_s2 - size_s1; ++i)
            s1 += s2[i];
    }
    else if (size_s1 > size_s2)
    {
        for(int i = 0; i < size_s1 - size_s2; ++i)
            s2 += s1[i];
    }

    for(int i = 0; i < s1.size(); ++i)
    {
        if (s1[i] != s2[i])
            return s1[i] > s2[i];
    }
    return true;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), comp);
    
    for(auto& e : numbers)
        answer += to_string(e);
    
    if (answer[0] == '0')
        answer = "0";
    
    return answer;
}