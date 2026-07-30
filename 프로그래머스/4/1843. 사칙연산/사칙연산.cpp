#include <vector>
#include <string>
#include <climits>
#include <iostream>

using namespace std;

void DP(vector<string>& arr, vector<vector<int>> &min_record, vector<vector<int>>& max_record, int start, int end)
{
    int count = end - start;
    for(int i = 0; i < count; ++i)
    {
        int idx = (start + i) * 2 + 1;
        if(arr[idx] == "+")
        {
            min_record[count][start] = min(min_record[count][start], min_record[i][start] + min_record[count - i - 1][start + i + 1]);
            max_record[count][start] = max(max_record[count][start], max_record[i][start] + max_record[count - i - 1][start + i + 1]);
        }
        else
        {
            min_record[count][start] = min(min_record[count][start], min_record[i][start] - max_record[count - i - 1][start + i + 1]);
            max_record[count][start] = max(max_record[count][start], max_record[i][start] - min_record[count - i - 1][start + i + 1]);
        }
    }
}

int solution(vector<string> arr)
{
    int answer = -1;
    
    int size = arr.size() / 2 + 1;
    vector<vector<int>> min_record(size, vector<int>(size, INT_MAX));
    vector<vector<int>> max_record(size, vector<int>(size, INT_MIN));
    
    for(int i = 0; i < size; ++i)
    {
        int cur = stoi(arr[i * 2]);
        min_record[0][i] = cur;
        max_record[0][i] = cur;
    }
    
    for(int i = 0; i < size - 1; ++i)
    {
        if(arr[i * 2 + 1] == "+")
        {
            min_record[1][i] = min_record[0][i] + min_record[0][i + 1];
            max_record[1][i] = max_record[0][i] + max_record[0][i + 1];
        }
        else
        {
            min_record[1][i] = min_record[0][i] - min_record[0][i + 1];
            max_record[1][i] = max_record[0][i] - max_record[0][i + 1];
        }
    }
    
    for(int i = 2; i < size; ++i)
    {
        for(int j = 0; j < size - i; ++j)
            DP(arr, min_record, max_record, j, j + i);
    }
    
    
    
    answer = max_record[size - 1][0];
    
    return answer;
}