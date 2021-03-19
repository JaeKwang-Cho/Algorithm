#include <iostream>
#include <map>

using namespace std;

int main()
{
	int t;
	cin >> t; 

	while (t--)
	{
		int n, m;
		cin >> n >> m;
		map<int, int> cnt;
		while (n--)
		{
			int x;
			cin >> x;
			cnt[x % m]++;
		}
		int ans = 0;

		for (auto &c : cnt)
		{
			if (c.first == 0)
			{
				cout << "1. " << c.first << "/ "<<c.second<< endl;
				ans++;
			}
			else if(2*c.first == m){
				cout << "2. " << c.first << "/ " << c.second << endl;;
				ans++;
			}
			else if (2 * c.first < m || cnt.find(m - c.first) == cnt.end())
			{
				cout << "3. " << c.first << "/ " << c.second << endl;
				int x = c.second;
				int y = cnt[m - c.first];
				cout << "x is " << x << " y is " << y << endl;
				ans += 1 + max(0, abs(x - y) - 1);
			}
		}
		cout << ans << endl;
		// 2, 2, 0, 2, 1, 0
	}
	return 0;
}