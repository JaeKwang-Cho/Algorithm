#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	__int16 n;

	cin >> n;

	__int16* coins = new __int16[n];
	__int16 sum = 0;
	__int16 meget = 0;
	__int16 min = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
		sum += coins[i];
	}
	sort(coins, coins + n, 
		[](__int16 a, __int16 b) { return (a > b ? true : false); });

	while (meget < sum && min < n)
	{
 		meget += coins[min++];
		if (meget > ceil(sum / 2))
		{
			break;
		}
	}
	cout << min;

	delete[]coins;

	return 0;
}