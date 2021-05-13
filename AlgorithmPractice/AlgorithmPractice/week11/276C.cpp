#include <iostream>
#include <algorithm>

using namespace std;

int n, q, l, r;
int arr[200005];
int index[200005];
long long sum = 0;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
	
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r;
		index[l - 1] += 1;
		index[r] -= 1;
	}
	for (int i = 1; i < n; i++)
	{
		index[i] += index[i - 1];
	}

	sort(arr, arr + n);
	sort(index, index + n);

	for (int i = 0; i< n; i++)
	{
		sum += (long long)arr[i] * (long long)index[i];
	}

	printf("%I64d\n", sum);

	return 0;
}