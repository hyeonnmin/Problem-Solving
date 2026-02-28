#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	deque<int> d;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		string input;
		cin >> input;

		if (input == "push_front")
		{
			int i;
			cin >> i;
			d.push_front(i);
		}
		else if (input == "push_back")
		{
			int i;
			cin >> i;
			d.push_back(i);
		}
		else if (input == "pop_front")
		{
			if (d.empty())
				cout << "-1\n";
			else
			{
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (d.empty())
				cout << "-1\n";
			else
			{
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (input == "size")
			cout << d.size() << '\n';
		else if (input == "empty")
		{
			if (d.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (input == "front")
		{
			if (d.empty())
				cout << "-1\n";
			else
				cout << d.front() << '\n';
		}
		else if (input == "back")
		{
			if (d.empty())
				cout << "-1\n";
			else
				cout << d.back() << '\n';
		}
	}
}