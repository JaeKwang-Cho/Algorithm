#include <iostream>

using namespace std;

int main()
{
	int n;
	int x, y, z;
	int xs=0, ys=0, zs=0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		xs += x;
		ys += y;
		zs += z;
	}

	if (!xs && !ys && !zs)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}


	return 0;
}