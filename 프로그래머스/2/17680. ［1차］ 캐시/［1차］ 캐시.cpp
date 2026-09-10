#include <string>
#include <vector>
#include <map>
#include <iostream> 

using namespace std;

string convert_low(string& s)
{
    string input = s;
    int sub = 'a' - 'A';
    for(auto& e : input)
    {
        if (e < 'a')
            e += sub;
    }
    return input;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    map<string, int> m;
    
    if(cacheSize == 0)
        answer = cities.size() * 5;
    else
    {
        string lru = "";
        for(auto& e : cities)
        {

            e = convert_low(e);

            int max_value = 0;
            for(auto& k : m)
            {
                k.second++;
                if(max_value < k.second)
                {
                    max_value = k.second;
                    lru = k.first;
                }
            }

            if(m.find(e) != m.end())
            {
                answer += 1;
                m[e] = 0;
                int max_value = 0;
            }
            else
            {
                answer += 5;
                if(m.size() == cacheSize)
                {
                    m.erase(lru);
                    m[e] = 0;
                }
                else
                {
                    m[e] = 0;
                }
            }
        }
    }
    
    
    
    return answer;
}