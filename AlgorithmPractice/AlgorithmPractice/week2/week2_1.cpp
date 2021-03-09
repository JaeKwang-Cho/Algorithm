#include <iostream>

using namespace std;

int main()
{
	char n[1001];

	cin >> n;
	int num = atoi(n);

	char* p = n;

	if (num % 4 == 0 || num % 7 == 0)
	{
		cout << "YES";
		return 0;
	}
	else
	{
		while (*p != '\n' && *p != '\0')
		{
			if (*p != '4' && *p != '7')
			{
				cout << "NO";
				return 0;
			}
			p++;
		}
	}
	cout << "YES";

	return 0;
}