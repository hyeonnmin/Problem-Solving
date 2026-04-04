#include <iostream> 
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Edge {
    string airport;
    bool visit;
    
    bool operator < (const Edge& others) const
    {
        return airport < others.airport;
    }
};


bool BackTracking(unordered_map<string, vector<Edge>>& m, vector<string>& airport, string cur, int count, int ticket_count)
{
   if (count == ticket_count)
   {
       for(auto & e : airport)
           cout << e << " ";
       return true;
   }
    
    for(auto& e : m[cur])
    {
        if (e.visit == false)
        {
            e.visit = true;
            airport.push_back(e.airport);
            if (BackTracking(m, airport, e.airport, count + 1, ticket_count))
                return true;
            e.visit = false;
            airport.pop_back();
        }
    }
    
    return false;
    
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    unordered_map<string, vector<Edge>> m;
    
    for(auto& e : tickets)
    {
        m[e[0]].push_back({e[1], false});
    }
    
    for(auto& e : m)
        sort(e.second.begin(), e.second.end());

    answer.push_back("ICN");
    BackTracking(m, answer, "ICN", 0, tickets.size());
    
    return answer;
}