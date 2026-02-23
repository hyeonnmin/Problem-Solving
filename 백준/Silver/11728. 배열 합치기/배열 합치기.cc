#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int* a = new int[N];
	int* b = new int[M];

	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		a[i] = input;
	}

	for (int i = 0; i < M; ++i)
	{
		int input;
		cin >> input;
		b[i] = input;
	}

	int* sub = new int[N + M];
	int a_idx = 0;
	int b_idx = 0;
	for (int i = 0; i < N + M; ++i)
	{
		if (a_idx == N)
		{
			sub[i] = b[b_idx];
			++b_idx;
		}
		else if (b_idx == M)
		{
			sub[i] = a[a_idx];
			++a_idx;
		}
		else if (a[a_idx] < b[b_idx])
		{
			sub[i] = a[a_idx];
			++a_idx;
		}
		else
		{
			sub[i] = b[b_idx];
			++b_idx;
		}
	}
	for (int i = 0; i < N + M; ++i)
	{
		cout << sub[i] << " ";
	}
}