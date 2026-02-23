#include <iostream>	
#include <vector>	

using namespace std;

void backtracking(vector<int>& v, vector<bool>& visited, int count, vector<int>& sub)
{
	if (count == sub.size())
	{
		for (int i = 0; i < sub.size(); ++i)
			cout << sub[i] << " ";
		cout << '\n';
		
		return;
	}
	for (int i = 0; i < v.size(); ++i)
	{
		if (visited[i] == false)
		{
			sub[count] = v[i];
			visited[i] = true;
			backtracking(v, visited, count + 1, sub);
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N >> M;

	vector<int> v;
	vector<bool> visited(N,false);
	for (int i = 1; i <= N; ++i)
		v.push_back(i);

	vector<int> sub(M);
	backtracking(v, visited, 0, sub);
}