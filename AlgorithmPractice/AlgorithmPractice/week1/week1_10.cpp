#include <iostream>
#include <algorithm>
#define MY_EPSILON (10^-9)

using namespace std;
int compare(int a, int b);

int main()
{
	int n, l;
	cin >> n;
	cin >> l;
	 
	double res = 0.0;
	int* a = new int[n];
	
	if (a != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n, compare);
		
		for (int j = 0; j < n-1; j++)
		{
			int gap = abs(a[j] - a[j + 1]);
			if (gap >= res)
			{
				res = gap;
			}
			else
			{
				continue;
			}
		}
		if (abs(a[n-1] - l) > res/2 && a[n-1] != l)
		{
 			res = abs(a[n-1] - l)*2;
		}
		if(abs(a[0]-0)>res/2 && a[0]!=0)
		{
			res = abs(a[0] - 0)*2;
		}
	}
	if (a != NULL)
	{
		delete[] a;
	}
	

	printf("%.10lf", res/2);
	
	return 0;
}
int compare(int a, int b)
{
	return a < b;
}