#include <iostream>

using namespace std;

int main()
{
	__int16 n, k;
	__int16* a = new __int16[5000];
	__int32* pa = new __int32[5001];

	cin >> n >> k;
	pa[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i-1];
		if (i == 1)
		{
			pa[i] = a[i-1];
		}
		else
		{
			pa[i] = pa[i - 1] + a[i-1];
		}
	}

	double top = 0.0;
	double cur = 0.0;
	for (int j = k; j <= n; j++)
	{
		for (int i = 0; i <= n - j; i++)
		{
			cur = ((double)pa[i + j] - (double)pa[i]) / (double)j;
			if (cur > top)
			{
				top = cur;
			}
		}
	}
	printf("%.15lf", top);

	delete[] a;
	delete[] pa;
	return 0;
}