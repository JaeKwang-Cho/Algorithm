#include <iostream>

using namespace std;
bool IsPrime(__int64 input);

int main()
{
	char notPrime[1000001] = { 0 };
	for (int i = 2; i <= 1000000; i++)
	{
		if (notPrime[i] == 0)
		{
			for (int j = 2; i * j <= 1000000; j++)
			{
				notPrime[i * j] = 1;
			}
		}
	}

	int n;
	cin >> n;
	__int64 nums;
	__int64 prime;

	for (int i = 0; i < n; i++)
	{
		cin >> nums;
		if (nums > 3)
		{
			prime = sqrt(nums);
			if (prime * prime == nums && notPrime[prime] == 0)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}