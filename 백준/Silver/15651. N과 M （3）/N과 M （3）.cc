#include <iostream>

using namespace std;

int container[7];
bool visited[7];

void backtracking(int N, int M, int counter)
{
	if (counter == M)
	{
		for (int i = 0; i < M; ++i)
			cout << container[i] << " ";
		cout << "\n";
		return;
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			container[counter] = i + 1;
			backtracking(N, M, counter + 1);
		}
		return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	backtracking(N, M, 0);
}