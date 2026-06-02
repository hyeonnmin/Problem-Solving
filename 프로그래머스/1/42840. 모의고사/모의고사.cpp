#include <string>
#include <vector>
#include <algorithm>
#include <iostream> 


using namespace std;

int grading(vector<int> &answers, vector<int> &input)
{
    int count = 0;
    int idx = 0;
    for(auto& e : answers)
    {
        if (e == input[idx])
            ++count;
        
        idx = (idx + 1) % input.size();
    }
    return count;
}

bool comp(pair<int, int>& p1, pair<int, int>& p2)
{
    return p1.first > p2.first;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<pair<int, int>> score;
    
    vector<int> one_answer{1, 2, 3, 4, 5};
    vector<int> two_answer{2, 1, 2, 3, 2, 4, 2, 5}; 
    vector<int> three_answer{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    score.push_back({grading(answers, one_answer), 1});
    score.push_back({grading(answers, two_answer), 2});
    score.push_back({grading(answers, three_answer), 3});

    sort(score.begin(), score.end(), comp);
    
    
    
    int sub = score[0].first;
    for(auto& e : score)
    {
        if (sub == e.first)
            answer.push_back(e.second);
    }
    return answer;
}