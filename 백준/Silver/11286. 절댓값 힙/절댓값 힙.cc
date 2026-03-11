#include <iostream>
#include <set>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	multiset<int> positives;
	multiset<int, greater<int>> negatives;

	int input;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		if (input == 0)
		{
			if (positives.empty() && negatives.empty())
				cout << "0\n";
			else if (positives.empty())
			{
				cout << *negatives.begin() << '\n';
				negatives.erase(negatives.begin());
			}
			else if (negatives.empty())
			{
				cout << *positives.begin() << '\n';
				positives.erase(positives.begin());
			}
			else
			{
				int p = *positives.begin();
				int n = -(*negatives.begin());

				if (p >= n)
				{
					cout << -n << '\n';
					negatives.erase(negatives.begin());
				}
				else
				{
					cout << p << '\n';
					positives.erase(positives.begin());
				}

			}
		}
		else if (input > 0)
			positives.insert(input);
		
		else
			negatives.insert(input);
	}
}