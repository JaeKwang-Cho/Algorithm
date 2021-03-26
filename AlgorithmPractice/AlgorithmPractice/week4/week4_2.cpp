#include <iostream>
#include <algorithm>

using namespace std;
size_t paint_fence(size_t start, size_t end);
__int32 arr[5001];

int main()
{
	size_t n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	cout << paint_fence(1, n);

	return 0;
}

size_t paint_fence(size_t start, size_t end)
{
	size_t num_of_fences = end - start + 1;

	size_t min_height = 0;
	__int32 min = arr[start];
	for (int i = start; i <= end; i++)
	{
		if (min >= arr[i])
		{
			min = arr[i];
		}
	}
	for (int i = start; i <= end; i++)
	{
		arr[i] -= min;
	}

	min_height += min;
	for (int i = start; i <= end;i++)
	{
		if (arr[i] == 0)
		{
			i++;
		}
		else
		{
			size_t new_start = i;
			while (arr[i] != 0)i++;
			min_height += paint_fence(new_start, i - 1);
		}
		i--;
	}

	if (min_height > num_of_fences)
	{
		return num_of_fences;
	}
	else
	{
		return min_height;
	}
}
