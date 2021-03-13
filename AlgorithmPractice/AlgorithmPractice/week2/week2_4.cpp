#include <iostream>

using namespace std;

int main()
{
	__int32 t,n;
	cin >> t;

	__int32** a = new __int32* [t];

	__int64 sum = 0;
	__int64 minsum = 0;
	
	bool* res = new bool[t];
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		a[i] = new __int32[n];
		__int64 l = 0, r = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
		res[i] = true;
		for (int j = 0; j < n; j++)
		{
			l += a[i][j];
			r += a[i][n - 1 - j];

			if (l <= 0 || r <= 0)
			{
				res[i] = false;
			}
		}
	}
	for (int i = 0; i < t; i++)
	{
		if (res[i] == true)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}