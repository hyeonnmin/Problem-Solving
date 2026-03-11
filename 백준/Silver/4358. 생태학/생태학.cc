#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, int> m;

	double count = 0.0;

	string input;
	while(getline(cin, input))
	{
		count += 1;
		m[input] += 1;
	}

	for (auto& e : m)
	{
		fixed(cout);
		cout.precision(4);
		cout << e.first << " " << (e.second / count) * 100 << endl;
	}
}