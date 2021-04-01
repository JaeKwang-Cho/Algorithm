#include <iostream>

using namespace std;
__int16 maxA , maxB;
__int16 n, a, b, c;
__int16 countPieces(__int16 len, __int16 flags);

int main()
{
	cin >> n;
	// a is biggest
	int temp;
	for (int i = 0; i < 3; i++)
	{
		cin >> temp;
		if (i == 0)
		{
			a = temp;
		}
		else if (i == 1)
		{
			if (a < temp)
			{
				b = a;
				a = temp;
			}
			else
			{
				b = temp;
			}
		}
		else
		{
			if (a < temp)
			{
				c = b;
				b = a;
				a = temp;
			}
			else if (b < temp)
			{
				c = b;
				b = temp;
			}
			else
			{
				c = temp;
			}
		}

	}

	cout << countPieces(n, 3) << endl;

	return 0;
}
__int16 countPieces(__int16 len , __int16 flags)
{
	__int16 restLen = len;
	__int16 result = 0;
	__int16 max = 0;

	if (len <= 0)
	{
		return 0;
	}

	if (flags == 3)
	{
		maxA = len / a;
		int undercheck = 0;
		for (int i = 0; i <= maxA; i++)
		{
			restLen = len - a * i;
			result = i;
			
			__int16 tempResult = countPieces(restLen, flags - 1);
			if (tempResult == -1)
			{
				continue;
			}
			else
			{
				if (max < tempResult + i)
				{
					max = tempResult + i;
					undercheck = i;
				}
				else
				{
					continue;
				}
			}
		}
		if (undercheck == -1)
		{
			return result;
		}
		else
		{
			return max;
		}		
	}
	else if (flags == 2)
	{
		__int16 max = 0;
		maxB = len / b;
		for (int i = 0; i <= maxB; i++)
		{
			restLen = len - b * i;
			result = i;
			__int16 tempResult = countPieces(restLen, flags - 1);
			if (tempResult == -1)
			{
				continue;
			}
			else
			{
				
				if (max < tempResult + i)
				{
					max = tempResult;
					break;
				}
				else
				{
					continue;
				}
			}
		}
		if (restLen != 0 && max == 0)
		{
			return max;
		}
		else
		{
			result += max;
			return result;
		}
	}
	else
	{
		result += len / c;
		restLen = len % c;
		if (restLen != 0)
		{
			return -1;
		}
		else
		{
			return result;
		}
	}
}