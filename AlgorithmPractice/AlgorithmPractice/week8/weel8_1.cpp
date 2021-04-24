#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 219D

struct city
{
	vector<int> children;
	vector<bool> direc_child;
	int* child;
	int prev;
	int select_flip_num = 0;
	int root_flip_num = 0;
};

city* cities;

void make_tree(int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int to, from;
		cin >> to >> from;

		cities[i].child = new int[n];
		
		(cities + to - 1)->children.push_back(from - 1);
		(cities + to - 1)->direc_child.push_back(true);

		(cities + from - 1)->children.push_back(to - 1);
		(cities + from - 1)->direc_child.push_back(false);
	}
}
int count_tree(int n, int prev)
{
	(cities + n)->prev = prev;
	for (auto var: (cities + n)->children)
	{
		if (var != prev)
		{
			(cities + n)->child[var] = (count_tree(var, n));
			(cities + n)->root_flip_num += (cities + n)->child[var];
		}
	}
	for (auto var : (cities + n)->direc_child)
	{
		if (var == true)
		{
			(cities + n)->root_flip_num++;
		}
	}
	return (cities + n)->root_flip_num;
}
void select_tree(int n, int prev)
{
	(cities + n)->select_flip_num += (cities + n)->root_flip_num;
	if (prev == -1)
	{
		for (auto var : (cities + n)->children)
		{
			select_tree(var, n);
		}
	}
	else
	{
		for (auto var : (cities + prev)->children)
		{
			if (var != n)
			{
				(cities + n)->select_flip_num += (cities + prev)->select_flip_num - (cities+prev)->child[n] + (cities + prev)->direc_child[n];
				select_tree(var, n);
			}
		}
	}
}



int main()
{
	int n;
	cin >> n;
	
	cities = new city[n];

	make_tree(n);

	count_tree(0,-1);

	select_tree(0, -1);

	int min_flip = n+1;
	vector<int> capitals;

	

	cout << min_flip << endl;
	for (auto var : capitals)
	{
		cout << var +1 << " ";
	}


	return 0;
}