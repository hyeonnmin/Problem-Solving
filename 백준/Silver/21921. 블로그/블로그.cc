#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, X;
	cin >> N >> X;

	queue<int> q;
	int max = 0;
	int cur = 0;
	int count = 1;

	for (int i = 0; i < N; ++i)
	{
		int visiters;
		cin >> visiters;

		if (q.size() < X)
		{
			q.push(visiters);
			max += visiters;
			cur += visiters;
		}
		else
		{
			int pre = q.front();
			q.pop();
			q.push(visiters);

			cur -= pre;
			cur += visiters;
			if (max < cur)
			{
				max = cur;
				count = 1;
			}
			else if (max == cur)
				count += 1;
		}
	}

	if (max == 0)
		cout << "SAD";
	else
		cout << max << '\n' << count;
}