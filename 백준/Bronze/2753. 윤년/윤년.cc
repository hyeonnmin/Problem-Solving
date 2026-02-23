#include <iostream>	

using namespace std;

int main()
{
	int input;
	cin >> input;

	bool check1 = (input % 4 == 0) ? true : false;
	bool check2 = (input % 100 != 0) || (input % 400 == 0);
	if (check1 && check2)
		cout << "1\n";
	else
		cout << "0\n";
}