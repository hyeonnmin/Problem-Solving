#include <iostream>

using namespace std;

int main()
{
	string vps;

	int n;
	cin >> n;

	for (int t = 0; t < n; ++t)
	{
		int left = 0;
		int right = 0;

		cin >> vps;

		for (int i = 0; i < vps.size(); ++i)
		{
			if (vps[i] == '(')
				left += 1;
			else 
				right += 1;

			if (right > left)
				break;
		}

		if (right == left)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}