#include <iostream>
#include <vector>

using namespace std;
char temp[100000];
vector<string> arr;
vector<string> rev;
vector<__int64> costs;

__int64 result[2][100000];

bool strCompare(string latter, string former)
{
	__int32 len1 = latter.size(), len2 = former.size();
	if (len1 >= len2)
	{
		for (int i = 0; i < len1; i++)
		{
			if (latter[i] < former[i])
			{
				return false;
			}
			else if (latter[i] > former[i])
			{
				return true;
			}
		}
		return true;
	}
	else
	{
		for (int i = 0; i < len2; i++)
		{
			if (latter[i] < former[i])
			{
				return false;
			}
			else if (latter[i] > former[i])
			{
				return true;
			}
		}
		return false;
	}
}

int main()
{
	__int32 n;
	__int64 ans;

	cin >> n;
	arr.resize(n);
	rev.resize(n);
	costs.resize(n);

	for (int i = 0; i < n; i++)
	{
		__int64 c;
		cin >> c;
		costs[i] = c ;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		__int32 len = strlen(temp);
		arr[i].resize(len);
		rev[i].resize(len);
		arr[i].assign(temp);
		rev[i].assign(temp);
		reverse(rev[i].begin(), rev[i].end());
	}
	result[0][0] = 0;
	result[1][0] = costs[0];

	for (int i = 1; i < n; i++)
	{
		result[0][i] = LONG_MAX;
		result[1][i] = LONG_MAX;
		if (strCompare(arr[i], arr[i - 1]) )
		{
			result[0][i] = result[0][i - 1];
		}
		if (strCompare(arr[i],rev[i - 1]))
		{
			if (result[0][i] < result[1][i - 1])
			{
				result[0][i] = result[0][i];
			}
			else
			{
				result[0][i] = result[1][i - 1];
			}
		}
		if (strCompare(rev[i],arr[i - 1]))
		{
			result[1][i] = result[0][i - 1] + costs[i];
		}
		if (strCompare(rev[i],rev[i - 1]))
		{
			if (result[1][i] >( result[1][i - 1] + costs[i]))
			{
				result[1][i] = result[1][i - 1] + costs[i];
			}
			else
			{
				result[1][i] = result[1][i];
			}
		}
	}
	
	if (result[1][n-1] > result[0][n-1])
	{
		ans = result[0][n - 1];
	}
	else
	{
		ans = result[1][n - 1];
	}
	if (ans >= LONG_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
	}

	return 0;
}

