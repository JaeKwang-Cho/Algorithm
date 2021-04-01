#include <iostream>

using namespace std;

int main()
{
	__int16 n;
	cin >> n;
	__int16 numOfOne = 0;
	__int16 temp = 0;
	__int16 max = -1;

	for (int i = 0; i < n; i++)
	{
		__int16 a;
		cin >> a;
		if (a == 0)
		{
			temp++;
			if (temp > max)
			{
				max = temp;
			}
		}
		else
		{
			numOfOne++;
			if (temp > 0)
			{
				temp--;
			}
		}
	}
	cout << max+numOfOne << endl;

	return 0;
}
