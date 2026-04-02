#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;

	vector<int> count_a(26, 0);
	vector<int> count_b(26, 0);
	
	for (auto& e : a)
		count_a[e - 'a']++;
	for (auto& e : b)
		count_b[e - 'a']++;

	int count = 0;
	for (int i = 0; i < count_a.size(); ++i)
	{
		count += abs(count_a[i] - count_b[i]);
	}

	cout << count;

}