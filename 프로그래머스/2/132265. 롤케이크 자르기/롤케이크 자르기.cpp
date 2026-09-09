#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int, int> left;
    map<int, int> right;
    
    int mid = 1;
    
    for(int i = 0; i < mid; ++i)
        left[topping[i]]++;
    
    for(int i = mid; i < topping.size(); ++i)
        right[topping[i]]++;
    
    if(left.size() == right.size())
        ++answer;
    
    for(; mid < topping.size(); ++mid)
    {
        int value = topping[mid];
        
        left[value]++;
        right[value]--;
        
        if(right[value] == 0)
            right.erase(value);
        
        if(left.size() == right.size())
            ++answer;
    }
    
    return answer;
}