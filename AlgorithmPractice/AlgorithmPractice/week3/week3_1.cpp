#include <iostream>

using namespace std;

int main()
{
	__int32 k2, k3, k5, k6;

	cin >> k2 >> k3 >> k5 >> k6;

	__int8 arr32[2] = { 3, 2 };
	__int8 arr256[3] = { 2,5,6 };

	__int32 sum = 0;

	while (1)
	{
		if (k2 > 0 && k5 > 0 && k6 > 0)
		{
			sum += 256;
			k2--;
			k5--;
			k6--;
		}
		else if(k3 > 0 && k2 > 0)
		{
			sum += 32;
			k3--;
			k2--;
		}
		else
		{
			break;
		}
	}

	cout << sum;

	return 0;
}