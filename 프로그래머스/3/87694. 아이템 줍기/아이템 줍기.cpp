#include <string>
#include <vector>
#include <queue>

using namespace std;

struct pos {
    int x;
    int y;
};

bool check_boundary(vector<vector<int>>& rectangle, pos p)
{
    int count = 0;
    for(int i = 0; i < rectangle.size(); ++i)
    {
        int left_x = rectangle[i][0] * 2;
        int left_y = rectangle[i][1] * 2;
        int right_x = rectangle[i][2] * 2;
        int right_y = rectangle[i][3] * 2;
        
        if (p.x < right_x && p.x > left_x && p.y < right_y && p.y > left_y)
            return false;
        else if (p.x <= right_x && p.x >= left_x && p.y <= right_y && p.y >= left_y)
            ++count;
    }
    if (count == 0)
        return false;
    
    return true;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    vector<vector<int>> maps(102, vector<int>(102, -1));
    
    queue<pos> q;
    q.push({characterX * 2, characterY * 2});
    maps[characterX * 2][characterY * 2] = 0;
    while(!q.empty())
    {
        pos cur = q.front();
        q.pop();
        
        if (cur.x == itemX * 2 && cur.y == itemY * 2)
            return maps[cur.x][cur.y] / 2;
        
        vector<pos> p;
        p.push_back({cur.x + 1, cur.y});
        p.push_back({cur.x - 1, cur.y});
        p.push_back({cur.x, cur.y + 1});
        p.push_back({cur.x, cur.y - 1});

        for(auto & e : p)
        {
            if (maps[e.x][e.y] == -1 && check_boundary(rectangle, e))
            {
                q.push(e);
                maps[e.x][e.y] = maps[cur.x][cur.y] + 1;
            }
        }

    }
    
    return answer;
}