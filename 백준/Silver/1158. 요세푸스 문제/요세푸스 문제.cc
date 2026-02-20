#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	queue<int> q;

	for (int i = 1; i <= n; ++i)
		q.push(i);

	cout << '<';
	int count = 0;
	while (!q.empty())
	{
		int sub = q.front();
		if (count == k - 1)
		{
			cout << sub;
			q.pop();
			if (!q.empty())
				cout << ", ";
			count = 0;
		}
		else
		{
			q.pop();
			q.push(sub);
			++count;
		}
	}
	cout << '>';
}