#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;


auto comp_disk = [](const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] > v2[1];
};

auto comp_wq = [](const vector<int>& v1, const vector<int>& v2)
{
  if(v1[2] != v2[2])
      return v1[2] > v2[2];
  else if(v1[1] != v2[1])
      return v1[1] > v2[1];
    else
        return v1[0] > v2[0];
        
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp_disk)> disk(comp_disk);    
    
    int size = jobs.size();
    for(int i = 0; i < size; ++i)
    {
        vector<int> input;
        input.push_back(i);
        input.push_back(jobs[i][0]);
        input.push_back(jobs[i][1]);
        disk.push(input);
    }
    
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp_wq)> wait_queue(comp_wq);
    
    int time = 0;
    int count = 0;
    int idx = 0;
    while(idx != size)
    {   
        bool flag = true;
        while(!disk.empty() && flag)
        {
            vector<int> v = disk.top();
            if(v[1] <= time)
            {
                wait_queue.push(v);
                disk.pop();
            }
            else
                flag = false;
        }
        
        if(!wait_queue.empty())
        {
            vector<int> v = wait_queue.top();
            time += v[2];
            count += (time - v[1]);
            
            cout << v[0] << ' ' << v[1] << ' ' << time << endl;
             
            wait_queue.pop();
            ++idx;
        }
        else
            time += 1;
    }
    
    answer = count / size;
    return answer;
}