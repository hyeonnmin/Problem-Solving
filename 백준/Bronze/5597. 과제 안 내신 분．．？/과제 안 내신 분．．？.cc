#include <iostream>	

using namespace std;

int main()
{
	bool students[31]{ false };

	students[0] = true;
	for (int i = 0; i < 28; ++i)
	{
		int input;
		cin >> input;
		students[input] = true;
	}

	for (int i = 1; i < 31; ++i)
	{
		if (students[i] == false)
			cout << i << "\n";
	}
}