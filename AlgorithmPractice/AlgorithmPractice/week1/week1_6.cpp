#include <iostream>

using namespace std;

int main()
{
	int n, m, a;
	__int64 res;
	cin >> n >> m >> a;

	if (n % a != 0)
	{
		res = n / a + 1;
	}
	else
	{
		res = n / a;
	}

	if (m % a != 0)
	{
		res *= m / a + 1;
	}
	else
	{
		res *= m / a;
	}

	cout << res;
}