#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int k;
		cin >> k;;

		multiset<int> s;
		for (int j = 0; j < k; ++j)
		{
			char order;
			int input;

			cin >> order >> input;

			if (order == 'I')
			{
				s.insert(input);
			}
			else
			{
				if (!s.empty())
				{
					if (input == -1)
						s.erase(s.begin());
					else
						s.erase(prev(s.end()));
				}
			}
		}
		if (s.empty())
			cout << "EMPTY\n";
		else
			cout << *prev(s.end()) << " " << *s.begin() << '\n';
	}
}