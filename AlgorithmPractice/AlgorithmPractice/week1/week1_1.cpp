#include <iostream>

using namespace std;

int main()
{
	int inputValue;
	cin >> inputValue;

	if (inputValue < 4)
	{
		cout << "NO";
	}
	else
	{
		if (inputValue % 2 == 0)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}

	return 0;

}