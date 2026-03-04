#include <iostream>	
#include <queue>
#include <vector>

using namespace std;

int find_priority(vector<int>& v)
{
	for (int i = v.size() - 1; i >= 0; --i)
	{
		if (v[i] != 0)
			return i;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	int N, M;

	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		cin >> N >> M;
		
		queue<pair<int, bool>> q;
		vector<int> v(10, 0);
		for (int j = 0; j < N; ++j)
		{
			int input;
			cin >> input;
			if (j == M)
				q.push(make_pair(input, true));
			else
				q.push(make_pair(input, false));
			v[input] += 1;
		}

		int priority_number = find_priority(v);
		int count = 0;
		while (!q.empty())
		{
			pair<int, bool> p = q.front();
			if (p.first == priority_number)
			{
				q.pop();
				++count; 
				v[p.first] -= 1;
				if (p.second == true)
				{
					cout << count << '\n';
					break;
				}
				if (v[p.first] == 0)
					priority_number = find_priority(v);
			}
			else
			{
				q.pop();
				q.push(p);
			}
		}
	}
}