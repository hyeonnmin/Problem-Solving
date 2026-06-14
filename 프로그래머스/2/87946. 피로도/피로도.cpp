#include <string>
#include <vector>

using namespace std;

void backTracking(vector<vector<int>>& dungeons, int k, vector<bool>& visits, int count, int& maxCount)
{
    for(int i = 0; i < dungeons.size(); ++i)
    {
        int limitHP = dungeons[i][0];
        int demage = dungeons[i][1];
        
        if(visits[i] == false)
        {
            if (limitHP <= k)
            {
                visits[i] = true;
                backTracking(dungeons, k - demage, visits, count + 1, maxCount);
                visits[i] = false;
            }
            
        }
    }
    maxCount = max(count, maxCount);

}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<bool> visits(dungeons.size(), false);
    answer = 0;
    
    backTracking(dungeons, k, visits, 0, answer);
    
    return answer;
}