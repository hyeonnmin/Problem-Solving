#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	set<string> s;

	for (int i = 0; i < N; ++i)
	{
		string input;
		cin >> input;
		s.insert(input);
	}

	int count = 0;
	for (int i = 0; i < M; ++i)
	{
		string input;
		cin >> input;
		if (s.find(input) != s.end())
			++count;
	}
	cout << count;
}