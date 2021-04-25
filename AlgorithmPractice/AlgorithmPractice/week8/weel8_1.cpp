#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 219D

struct city
{
	vector<int> children;
	int num_child = 0;;
	vector<bool> direc_child;
	vector<int> child_flip;
	int root_flip_num = 0;
};

city cities [200000];

void make_tree(int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int to, from;
		cin >> to >> from;
		
		(cities + to - 1)->children.push_back(from - 1);
		(cities + to - 1)->direc_child.push_back(true);
		(cities + to - 1)->num_child++;

		(cities + from - 1)->children.push_back(to - 1);
		(cities + from - 1)->direc_child.push_back(false);
		(cities + from - 1)->num_child++;
	}
}
int count_tree(int n, int prev)
{
	for (auto var: (cities + n)->children)
	{
		if (var != prev)
		{
			int temp = count_tree(var, n);
			(cities + n)->child_flip.push_back(temp);
			(cities + n)->root_flip_num += temp;
		}
		else
		{
			(cities + n)->child_flip.push_back(-1);
		}
	}
	if (prev != -1)
	{
		for (int i = 0; i < (cities + n)->num_child; i++)
		{
			if ((cities + n)->children[i] == prev)
			{
				if ((cities + n)->direc_child[i] == true)
				{
					return (cities + n)->root_flip_num + 1;
				}
			}
		}
	}
	return (cities + n)->root_flip_num;
}
void select_tree(int n, int prev, bool direc)
{
	if (prev == -1)
	{
		for (int i =0; i< (cities + n)->num_child;i++)
		{
			select_tree((cities + n)->children[i], n, (cities + n)->direc_child[i]);
		}
	}
	else
	{
		(cities + n)->root_flip_num = 0;
		(cities + n)->root_flip_num += (cities + prev)->root_flip_num;
		if (direc == false)
		{
			(cities + n)->root_flip_num--;
		}
		else
		{
			(cities + n)->root_flip_num++;
		}
		for (int i = 0; i < (cities + n)->num_child; i++)
		{
			if ((cities + n)->children[i] != prev)
			{
				select_tree((cities + n)->children[i], n, (cities + n)->direc_child[i]);
			}
		}
		
		/*
		for (int i = 0; i < (cities + prev)->num_child; i++)
		{
			if ((cities + prev)->children[i] == n)
			{
				if ((cities + prev)->direc_child[i] == true)
				{
					(cities + n)->root_flip_num++;
				}
				select_tree(var, n);
			}
		}
		*/
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;


	make_tree(n);

	count_tree(0,-1);

	select_tree(0, -1, true);


	int min_flip = n+1;
	vector<int> capitals;

	for (int i = 0; i < n; i++)
	{
		if (min_flip > (cities + i)->root_flip_num)
		{
			vector<int>().swap(capitals);
			min_flip = (cities + i)->root_flip_num;
			capitals.push_back(i);
		}
		else if (min_flip == (cities + i)->root_flip_num)
		{
			capitals.push_back(i);
		}
	}


	cout << min_flip << "\n";
	for (auto var : capitals)
	{
		cout << var +1 << " ";
	}


	return 0;
}