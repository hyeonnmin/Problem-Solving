#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;

	stack<int> s;
	bool check = true;

	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == '(' || input[i] == '[')
			s.push(input[i] - 100);
		else
		{
			int count = 0;
			if (input[i] == ')')
			{
				while (!s.empty())
				{
					int top = s.top();
					s.pop();
					if (top == '(' - 100)
					{
						if (count != 0)
							s.push(count * 2);
						else
							s.push(2);
						break;
					}
					else if (top == ')' - 100 || top == '[' - 100 || top == ']' - 100)
					{
						check = false;
						break;
					}
					else
					{
						count += top;
					}
				}
				if (s.empty() || check == false)
				{
					check = false;
					break;
				}

			}
			if (input[i] == ']')
			{
				while (!s.empty())
				{
					int top = s.top();
					s.pop();
					if (top == '[' - 100)
					{
						if (count != 0)
							s.push(count * 3);
						else
							s.push(3);
						break;
					}
					else if (top == ')' - 100 || top == '(' - 100 || top == ']' - 100)
					{
						check = false;
						break;
					}
					else
					{
						count += top;
					}
				}
				if (s.empty() || check == false)
				{
					check = false;
					break;
				}

			}
		}
	}

	if (check == false)
		cout << 0;
	else 
	{
		int count = 0;
		while (!s.empty())
		{
			int top = s.top();
			s.pop();

			if (top == '[' - 100 || top == ']' - 100 || top == '(' - 100 || top == ')' - 100)
			{
				cout << 0;
				return 0;
			}

			count += top;
		}
		if (count != 0)
			cout << count;
	}

}