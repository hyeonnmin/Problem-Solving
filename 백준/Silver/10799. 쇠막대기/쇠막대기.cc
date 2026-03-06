#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;
	
	int cutting_count = 0;
	bool flag = false;
	stack<char> s;

	for (auto& e : input)
	{
		if (e == '(')
		{
			s.push(e);
			flag = true;
		}
		else if (e == ')')
		{
			if (flag)
			{
				flag = false;
				s.pop();
				cutting_count += s.size();
			}
			else
			{
				cutting_count += 1;
				s.pop();
			}
		}
	}

	cout << cutting_count;

}