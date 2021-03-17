#include <iostream>

using namespace std;

int main()
{
	__int32 n;

	cin >> n;

	__int32 numOf3 = 0;
	__int32 numOf2 = 0;
	__int32 numOf1 = 0;

	__int32 numOfTaxi = 0;

	for (int i = 0; i < n; i++)
	{
		int input;

		cin >> input;
		switch (input)
		{
		case 1:
			numOf1++;
			break;
		case 2:
			numOf2++;
			break;
		case 3:
			numOf3++;
			break;
		case 4:
			numOfTaxi++;
			break;
		default:
			break;
		}
	}

	while (1)
	{
		if (numOf3 > 0 && numOf1 > 0)
		{
			numOfTaxi++;
			numOf3--;
			numOf1--;
		}
		else if (numOf1 >= 4)
		{
			numOfTaxi++;
			numOf1 -= 4;
		}
		else if (numOf2 >= 1 && numOf1 >= 2)
		{
			numOfTaxi++;
			numOf2--;
			numOf1 -= 2;
		}
		else if (numOf2 >= 2)
		{
			numOfTaxi++;
			numOf2 -= 2;
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		if (numOf3 > 0)
		{
			numOfTaxi++;
			numOf3--;
		}
		else if (numOf2 > 0 && numOf1 > 0)
		{
			numOf2--;
			numOf1--;
			numOfTaxi++;
		}
		else if (numOf1 > 2)
		{
			numOf1 -= 3;
			numOfTaxi++;
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		if (numOf2 > 0)
		{
			numOf2--;
			numOfTaxi++;
		}
		else if (numOf1 > 1)
		{
			numOf1-=2;
			numOfTaxi++;
		}
		else
		{
			break;
		}
	}
	if (numOf1 > 0)
	{
		numOf1--;
		numOfTaxi++;
	}

	cout << numOfTaxi;
	return 0;
}