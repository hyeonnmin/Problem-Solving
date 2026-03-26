#include <iostream>
#include <vector>

using namespace std;

bool check(int input)
{
	int count = 0;
	for (int i = 1; i <= input; ++i)
	{
		if ((input % i) == 0)
			++count;
	}
	if (count == 2)
		return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M, N;

	cin >> M >> N;

	int sum = 0;
	int min = 0;
	for (int i = M; i <= N; ++i)
	{
		if (check(i) == true)
		{
			sum += i;
			if(min == 0)
				min = i;
		}
	}

	if (min == 0)
		cout << -1;
	else
		cout << sum << '\n' << min;
	
}