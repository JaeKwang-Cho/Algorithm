#include <iostream>
#include <vector>

using namespace std;
// 602B
vector<__int32> arr;

int main()
{
	__int32 n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		__int32 temp;
		cin >> temp;
		arr[i] = temp;
	}

	__int32 former = 0;
	__int32 temp = 0;
	__int32 firstCount = 0;
	__int32 secondCount = 1;

	__int32 max_len = 2;

	temp = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == arr[i-1])
		{
			secondCount++;
		}
		else if(arr[i] == former){
			firstCount += secondCount;
			former = temp;
			temp = arr[i];
			secondCount = 1;
		}
		else
		{
			if (max_len < secondCount + firstCount)
			{
				max_len = secondCount + firstCount;
			}

			former = temp;
			firstCount = secondCount;
			temp = arr[i];
			secondCount = 1;
		}
	}
	if (max_len < secondCount + firstCount)
	{
		max_len = secondCount + firstCount;
	}

	cout << max_len;

	return 0;
}