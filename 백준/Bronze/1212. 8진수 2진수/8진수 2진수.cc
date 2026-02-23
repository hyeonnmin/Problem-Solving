#include <iostream>	
#include <stack>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string input;
	cin >> input;

	stack<int> s;

	for (int i = input.size() - 1; i >= 0; --i)
	{
		int sub = input[i] - '0';
		
		for(int j = 0; j < 3; ++j)
		{
			if (i == 0 && sub == 0)
				break;
			if (sub % 2 == 1)
				s.push(1);
			else
				s.push(0);
			sub /= 2;
		}
	}

	if (s.empty())
		cout << "0";
	else
	{
		while (!s.empty())
		{
			cout << s.top();
			s.pop();
		}
	}
};