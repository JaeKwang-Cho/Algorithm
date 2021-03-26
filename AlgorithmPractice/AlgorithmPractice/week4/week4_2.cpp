#include <iostream>

using namespace std;
size_t paint_fence(__int32* arr, size_t start, size_t end, __int32 offset);


// use segment tree
int main()
{
	size_t n;
	cin >> n;
	__int32* a = new __int32[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << paint_fence(a, 0, n - 1, 0);

	return 0;
}

size_t paint_fence(__int32* arr, size_t start, size_t end, __int32 offset)
{
	size_t touches = 0;

	size_t num_of_fences = end - start + 1;

	if (num_of_fences == 1)
	{
		if (arr[start] == offset)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (num_of_fences == 2)
	{
		if (arr[start] == arr[end] && arr[start] - offset == 1)
		{
			return 1;
		}
		else if (arr[start] == offset && arr[end] == offset)
		{
			return 0;
		}
		else if (arr[start] == offset || arr[end] == offset)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}

	size_t min_index = 0;
	for (int i = start; i < end; i++)
	{
		if (arr[min_index] >= arr[i])
		{
			min_index = i;
		}
	}

	if (start == min_index)
	{
		touches += paint_fence(arr, min_index +1 ,end , arr[min_index]);
	}
	else if (end == min_index)
	{
		touches += paint_fence(arr, start, min_index-1, arr[min_index]);
	}
	else
	{
		touches += paint_fence(arr, start, min_index - 1, arr[min_index]);
		touches += paint_fence(arr, min_index + 1, end, arr[min_index]);
	}

	touches += (arr[min_index] - offset);

	if (touches >= num_of_fences)
	{
		return num_of_fences;
	}
	else
	{
		return touches;
	}
}
