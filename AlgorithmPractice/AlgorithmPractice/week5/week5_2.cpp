#include <iostream>

using namespace std;
__int64 getSum(__int32* arr, bool eat);
__int32* input = NULL;
__int32* a = NULL;
__int32* adjoin = NULL;
__int32* checked = NULL;
__int32 n;
__int32 variety;

int main()
{
	
	cin >> n;
	input = new __int32[n+1];
	checked = new __int32[n + 1];
	variety = 0;
	for (int i = 0; i <= n; i++)
	{
		input[i] = 0;
		checked[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		__int32 temp;
		cin >> temp;
		input[temp] +=temp;
		if (checked[temp] == 0)
		{
			variety++;
			checked[temp] = temp;
		}
	}
	adjoin = new __int32[variety + 1];
	a = new __int32[variety + 1];
	int j = 1;
	a[0] = 0;
	adjoin[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (checked[i] != 0)
		{
			a[j] = input[i];
			adjoin[j] = checked[i];
			j++;
		}
	}

	
	__int64 result = getSum(a + 1, true);
	__int64 tempmax = getSum(a + 1, false);
	if (tempmax > result)
	{
		result = tempmax;
	}

	cout << result << endl;

	delete[] input;
	delete[] a;
	delete[] adjoin;
	delete[] checked;

	input = NULL;
	a = NULL;
	adjoin = NULL;
	checked = NULL;

	return 0;
} 
__int64 getSum(__int32* arr, bool eat)
{
	__int64 result = 0;

	if (eat)
	{
		result += *arr;
		if (arr - a >= variety)
		{
			return *arr;
		}
		if (adjoin[arr - a] + 1 == adjoin[arr - a + 1])
		{
			result += getSum(arr + 1, false);
		}
		else
		{
			__int64 tempmax = getSum(arr + 1, false);
			__int64 temp = getSum(arr + 1, true);
			if (tempmax < temp)
			{
				result += temp;
			}
			else
			{
				result += tempmax;
			}
		}
	}
	else
	{
		if (arr - a >= variety)
		{
			return 0;
		}
		__int64 tempmax = getSum(arr+1, false);
		__int64 temp = getSum(arr+1, true);
		if (tempmax < temp)
		{
			result += temp;
		}
		else
		{
			result += tempmax;
		}
	}
	return result;
}