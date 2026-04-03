#include <iostream>
#include<vector>
#include <queue>

using namespace std;

struct robot
{
    int r, c;
    int count = 0;
};


int solution(vector<vector<int> > maps)
{
    int answer = -1;
    
    int row = maps.size();
    int col = maps[0].size();
    
    vector<vector<bool>> visits (row, vector<bool>(col, false));
    queue<robot> s;
    
    s.push({0, 0, 1});
    visits[0][0] = true;
    
    while(!s.empty())
    {
        robot r = s.front();
        s.pop();

        if (r.r == row - 1 && r.c == col - 1)
        {
            return r.count;
        }
        
        if (r.r + 1 < row && visits[r.r + 1][r.c] == false && maps[r.r + 1][r.c] == 1)
        {
            s.push({r.r + 1, r.c, r.count + 1});
            visits[r.r + 1][r.c] = true;
        }
        
        if (r.r - 1 >= 0 && visits[r.r - 1][r.c] == false && maps[r.r - 1][r.c] == 1)
        {
            s.push({r.r - 1, r.c, r.count + 1});
            visits[r.r - 1][r.c] = true;
        }
        
        if (r.c + 1 < col && visits[r.r][r.c + 1] == false && maps[r.r][r.c + 1] == 1)
        {
            s.push({r.r, r.c + 1, r.count + 1});
            visits[r.r][r.c + 1] = true;
        }
        
        if (r.c - 1 >= 0 && visits[r.r][r.c - 1] == false && maps[r.r][r.c - 1] == 1)
        {
            s.push({r.r, r.c - 1, r.count + 1});
            visits[r.r][r.c - 1] = true;
        }
    }
    
    return answer;
}