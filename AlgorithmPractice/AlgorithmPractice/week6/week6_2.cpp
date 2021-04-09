#include <iostream>
#include <vector>
#include <algorithm>

//607A
using namespace std;
vector<pair<__int32, __int32>> beacon;
vector<__int32> alive;

bool cmp(pair<__int32, __int32> a1, pair<__int32, __int32> a2);
__int32 getSurvivor(__int32 start, __int32 end, __int32 key);

int main()
{
	__int32 n;
	cin >> n;
	
	beacon.resize(n);
	alive.resize(n);

	beacon.begin();
	for (int i = 0; i < n; i++)
	{
		__int32 a, b;
		cin >> a;
		cin >> b;
		beacon[i]=(make_pair(a,b));
	}

	sort(beacon.begin(), beacon.end(),cmp);

	__int32 max = 1;
	for (int i = 1; i < n; i++)
	{
		alive[0] = 1;
		__int32 index = getSurvivor(0, n, beacon[i].first - beacon[i].second);
		if (index == -1)
		{
			alive[i] = 1;
		}
		else
		{
			alive[i] = alive[index] + 1;
		}

		if (max < alive[i])
		{
			max = alive[i];
		}
	}
	cout << n - max << endl;

	return 0;
}
bool cmp(pair<__int32, __int32> a1, pair<__int32, __int32> a2)
{
	if (a1.first >= a2.first)
	{
		return false;
	}
	else
	{
		return true;
	}
}
__int32 getSurvivor(__int32 left , __int32 right, __int32 key)
{
	while (left < right){
		__int32 mid = (left + right) / 2;
		if (beacon[mid].first >= key)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (beacon[left].first >= key)
	{
		left--;
	}
	return left;
}