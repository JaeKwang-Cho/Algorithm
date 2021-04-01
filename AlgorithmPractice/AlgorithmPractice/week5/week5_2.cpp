#include <iostream>
#include <algorithm>

using namespace std;
int n;
__int64 num_of_num[100002];
__int64 arr[100002];

int main()
{
	cin >> n;
	int value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		num_of_num[value]++;
	}
	arr[0] = 0;
	arr[1] = num_of_num[1] * 1;
	for (int i = 2; i <= 100000; i++)
	{
		arr[i] = max(arr[i - 1], arr[i - 2] + num_of_num[i] * i);
	}
	cout << arr[100000];
	return 0;
}