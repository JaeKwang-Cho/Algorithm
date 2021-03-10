#include <iostream>

using namespace std;

int main()
{
	__int16 t,n;
	cin >> t;

	__int32** a = new __int32* [t];

	__int64 sum = 0;
	__int64 minsum = 0;
	
	bool* res = new bool[t];
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		a[i] = new __int32[n];
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
		for (int j = 0; j < n; j++)
		{
			sum += a[i][j];
			if (sum <= 0)
			{
				res[i] = false;
				goto POINT;
			}
		}
		sum = 0;
		for (int j = n-1; j >= 0; j--)
		{
			sum += a[i][j];
			if (sum <= 0)
			{
				res[i] = false;
				goto POINT;
			}
		}
		res[i] = true;
	POINT:
		sum = 0;
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