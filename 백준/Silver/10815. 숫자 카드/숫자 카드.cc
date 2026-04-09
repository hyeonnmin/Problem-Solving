#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	map<int, bool> m;

	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;

		m.insert({input, true});
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int input;
		cin >> input;

		if (m.find(input) == m.end())
			cout << "0 ";
		
		else if (m.find(input)->second == true)
			cout << "1 ";
	}

}