#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<bool>> maps(m, vector<bool>(n, true));
    for(int i = 0; i < puddles.size(); ++i)
    {
        maps[puddles[i][0] - 1][puddles[i][1] - 1] = false;
    }
    
    vector<vector<int>> visits(m, vector<int>(n, 0));
    visits[0][0] = 1;
    
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if (maps[i][j] != false)
            {
                if (i - 1 >= 0)
                    visits[i][j] += visits[i - 1][j];
                if (j - 1 >= 0)
                    visits[i][j] += visits[i][j - 1];
                visits[i][j] %= 1000000007;
            }
        }
    }
    answer = visits[m - 1][n - 1];
    
    return answer;
}