#include <iostream>

using namespace std;

int main()
{
	__int32 n;

	cin >> n;

	__int32* a = new __int32[n+1];
	__int64* pa = new __int64[n+1];

	pa[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pa[i] = pa[i - 1] + a[i];
	}
	if (pa[n] % 3!= 0)
	{
		cout << 0;
	}
	else
	{
		__int64 partition1 = pa[n] / 3;
		__int64 partition2 = pa[n] / 3 *2;
		__int64 counter1 = 0;
		__int64 counter2 = 0;
		if (pa[1] == partition1)
		{
			counter1++;
		}
		for (int i = 2; i < n; i++)
		{
			if (pa[i] == partition2)
			{
				counter2 += counter1;
			}
			if (pa[i] == partition1)
			{
				counter1++;
			}
		}
		cout << counter2;
	}

	delete[] a;
	return 0;
}