#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[100002];
int iA[100002];
int sub_value[100002];
int i_sub_value[100002];
int ans[100002];

vector<int> last;
vector<int> iLast;

int longest_increasing_subsequence(int n)
{
	int max_length = 1;
	vector<int>::iterator it;
	vector<int>::iterator iIt;
	vector<int>().swap(last);
	vector<int>().swap(iLast);
	last.push_back(-1);
	iLast.push_back(-1);
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		iA[n - i + 1] = 100002 - A[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (last.back() < A[i])
		{
			last.push_back(A[i]);
		}
		// get lesser than me : idea 1
		it = lower_bound(last.begin(), last.end(), A[i]);
		*it = A[i];
		sub_value[i] = it - last.begin();
		if (iLast.back() < iA[i])
		{
			iLast.push_back(iA[i]);
		}
		// reverse it : idea 2
		iIt = lower_bound(iLast.begin(), iLast.end(), iA[i]);
		*iIt = iA[i];
		i_sub_value[n-i+1] = iIt - iLast.begin();
		if (max_length <= sub_value[i])
		{
			max_length = sub_value[i];
		}
	}
	return max_length;
}


void discern_included(int n, int max_length)
{
	int Lmax = 0, Rmin = 100002;

	for (int i = 1; i <= n; i++)
	{
		if (sub_value[i] + i_sub_value[i] == max_length + 1)
		{
			ans[i] = 3;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] != 1)
		{
			if (A[i] <= Lmax)
			{
				ans[i] = 2;
			}
			Lmax = Lmax > A[i] ? Lmax : A[i];
		}
	}
	for (int i = n; i >= 1; i--)
	{
		if (ans[i] != 1)
		{
			if (A[i] >= Rmin)
			{
				ans[i] = 2;
			}
			Rmin = Rmin < A[i] ? Rmin : A[i];
		}
	}
}

int main()
{
	int n, max_length;
	
	cin >> n;
	
	max_length = longest_increasing_subsequence(n);

	fill_n(ans, sizeof(ans) / sizeof(int), 1);

	discern_included(n,max_length);

	

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i];
	}

	return 0;
}