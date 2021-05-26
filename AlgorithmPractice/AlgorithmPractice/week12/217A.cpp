#include <iostream>
#include <vector>

using namespace std;

vector <int> E[1000];
int X[1000], Y[1000];
int n;
int V[1000];

void dfs(int nd)
{
	int s;
	V[nd] = 1;
	s = E[nd].size();
	for (int i = 0; i < s; i++)
	{
		if (V[E[nd][i]] != 1)
		{
			dfs(E[nd][i]);
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> X[i] >> Y[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				if (X[i] == X[j] || Y[i] == Y[j])
				{
					E[i].push_back(j);
					E[j].push_back(i);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (V[i] == 0)
		{
			ans++;
			dfs(i);
		}
	}
	cout << ans - 1;
	return 0;
}