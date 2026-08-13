#include <string>
#include <vector>
#include <limits.h>
#include <deque>
#include <iostream>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> answer(2, 0);
    
    vector<vector<int>> area(m, vector<int>(n, INT_MAX));
    
    int count = 1;
    for(auto& e : drops)
    {
        int row = e[0];
        int col = e[1];
        
        area[row][col] = count;
        ++count;
    }
    
    vector<vector<int>> row_area(m, vector<int>(n - (w - 1), 0));
    
    for(int r = 0; r < m; ++r)
    {
        deque<int> dq;
        dq.push_back(0);
        for(int i = 1; i < w; ++i)
        {
            int pre = dq.back();
            int cur = area[r][i];
            while(!dq.empty() && area[r][dq.back()] > cur)
            {
                dq.pop_back();
            }
            dq.push_back(i);
            
        }
        row_area[r][0] = area[r][dq.front()];
        
        for(int c = 0; c < n - (w - 1) - 1; ++c)
        {
            if(dq.front() == c)
                dq.pop_front();
            int cur = area[r][c + w];
            
            while(!dq.empty() && area[r][dq.back()] > cur)
            {
                dq.pop_back();
            }
            dq.push_back(c + w);
            
            row_area[r][c + 1] = area[r][dq.front()];
        }
    }
    
    vector<vector<int>> col_area(m - (h - 1), vector<int>(n - (w - 1), 0));
    
    for(int c = 0; c < n - (w - 1); ++c)
    {
        deque<int> dq;
        dq.push_back(0);
        for(int i = 1; i < h; ++i)
        {
            int pre = dq.back();
            int cur = row_area[i][c];
            while(!dq.empty() && row_area[dq.back()][c] > cur)
            {
                dq.pop_back();
            }
            dq.push_back(i);
            
        }
        col_area[0][c] = row_area[dq.front()][c];
        
        for(int r = 0; r < m - (h - 1) - 1; ++r)
        {
            if(dq.front() == r)
                dq.pop_front();
            int cur = row_area[r + h][c];
            
            while(!dq.empty() && row_area[dq.back()][c] > cur)
            {
                dq.pop_back();
            }
            dq.push_back(r + h);
            
            col_area[r + 1][c] = row_area[dq.front()][c];
        }
    }
    
    int cur = -1;
    for(int r = 0; r < col_area.size(); ++r)
    {
        for(int c = 0; c < col_area[r].size(); ++c)
        {
            if(col_area[r][c] == INT_MAX)
            {
                answer[0] = r;
                answer[1] = c;
                return answer;
            }
            else if (col_area[r][c] > cur)
            {
                answer[0] = r;
                answer[1] = c;
                cur = col_area[r][c];
            }
        }
    }
    
    return answer;
}