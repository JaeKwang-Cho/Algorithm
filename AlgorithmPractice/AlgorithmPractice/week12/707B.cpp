#include <iostream>

using namespace std;

int E[100005][3];
int F[100005];
int j, n, m, k, ans;


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		cin >> E[i][0] >> E[i][1] >> E[i][2];
	}
	for (int i = 0; i < k; i++)
	{
		cin >> j;
		F[j] = 1;
	}
	ans = INT_MAX;
	for (int i = 0; i < m; i++)
	{
		if ((F[E[i][0]] == 1) && (F[E[i][1]] == 0)
			|| (F[E[i][0]] == 0) && (F[E[i][1]] == 1))
		{
			ans = ans < E[i][2] ? ans : E[i][2];
		}
	}
	if (ans == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	
	return 0;
}