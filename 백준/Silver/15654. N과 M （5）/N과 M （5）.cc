#include <iostream>	
#include <vector>
#include <algorithm>

using namespace std;

void backtracking(vector<int>& numbers, vector<int>& visited, vector<int>& container, int count)
{
	if (count == container.size())
	{
		for (auto& v : container)
			cout << v << " ";
		cout << '\n';
		return;
	}
	else
	{
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (visited[i] == false)
			{
				container[count] = numbers[i];
				visited[i] = true;
				backtracking(numbers, visited, container, count + 1);
				visited[i] = false;
			}

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

	vector<int> numbers;
	vector<int> visited(N, false);
	vector<int> container(M);

	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		numbers.push_back(input);
	}
	std::sort(numbers.begin(), numbers.end());

	backtracking(numbers, visited, container, 0);
}