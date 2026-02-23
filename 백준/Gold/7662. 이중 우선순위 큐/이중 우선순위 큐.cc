#include <iostream>	
#include <queue>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		priority_queue<int, vector<int>, greater<int>> minQueue;
		priority_queue<int> maxQueue;
		map<int, int> m;

		int k;
		cin >> k;

		for (int j = 0; j < k; ++j)
		{
			char c;
			cin >> c;

			if (c == 'I')
			{
				int input;
				cin >> input;

				minQueue.push(input);
				maxQueue.push(input);
				m[input]++;
			}
			else if (c == 'D')
			{
				int input;
				cin >> input;

				if (maxQueue.empty() || minQueue.empty())
					continue;

				if (input == 1)
				{
					if (maxQueue.empty())
						continue;

					m[maxQueue.top()]--;
					maxQueue.pop();
				}

				else if (input == -1)
				{
					if (minQueue.empty())
						continue;

					m[minQueue.top()]--;
					minQueue.pop();
				}

				while (!maxQueue.empty() && m[maxQueue.top()] == 0)
				{
					maxQueue.pop();
				}
				while (!minQueue.empty() && m[minQueue.top()] == 0)
				{
					minQueue.pop();
				}
			}
		}

		if (maxQueue.empty() && minQueue.empty())
			cout << "EMPTY\n";
		else
			cout << maxQueue.top() << " " << minQueue.top() << '\n';
	}
}