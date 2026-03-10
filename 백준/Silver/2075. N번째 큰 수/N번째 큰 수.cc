#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	set<int> s;

	for (int i = 0; i < N * N; ++i)
	{
		int input;
		cin >> input;
		
		if (s.size() == N)
		{
			if (*s.begin() < input)
			{
				s.erase(s.begin());
				s.insert(input);
			}
		}
		else
			s.insert(input);
	}
	
	

	cout << *s.begin();
}