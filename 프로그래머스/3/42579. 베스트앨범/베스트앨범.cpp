#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, vector<pair<int, int>>> m;
    map<string, int> genre_m;
    map<int, string, greater<int>> sorted_genre_m;
    
    int size = genres.size();
    
    for(int i = 0; i < size; ++i)
    {
        m[genres[i]].push_back({plays[i], i});
        genre_m[genres[i]] += plays[i];
    }
    
    for(auto& e : genre_m)
    {
        sorted_genre_m[e.second] = e.first;
    }
    
    for(auto& e : sorted_genre_m)
    {
        vector<pair<int, int>> &v = m[e.second];
        sort(v.begin(), v.end(), comp);
        for(int i = 0; i < v.size(); ++i)
        {
            if (i == 2)
                break;
            
            answer.push_back(v[i].second);
        }
    }
    
    for(auto& e : m)
    {
        cout << e.first << ' ';
        for(auto& s : e.second)
            cout << s.first << ' ';
        cout << endl;
    }
    
    return answer;
}