#include <iostream>
#include <vector>

using namespace std;

struct settlement
{
	vector<int> link;
	int num_link = 0;
	int num_evil = 0;
	bool isEvil = false;
};

settlement settlements[100001];

int* max_dis_up;
int* max_dis_down;

void set_evil(int m)
{
	for (int i = 0; i < m; i++)
	{
		int p;
		cin >> p;
		(settlements + p-1)->isEvil = true;
	}
}

void make_link(int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int to, from;
		cin >> to >> from;

		(settlements + to - 1)->link.push_back(from - 1);
		(settlements + to - 1)->num_link++;

		(settlements + from - 1)->link.push_back(to - 1);
		(settlements + from - 1)->num_link++;
	}
}

int get_farthest(int node, int prev)
{
	*(max_dis_down + node) = (settlements + node)->isEvil ? 0 : -1;
	for (auto var : (settlements + node)->link)
	{
		if (prev != var)
		{
			int distance = get_farthest(var, node);
			if (distance > -1)
			{
				*(max_dis_down + node) = (*(max_dis_down + node) > (distance+1) ) ? *(max_dis_down + node) : (distance + 1);
			}
		}
	}
	if ((settlements + node)->num_link == 1)
	{
		if (prev != -1 && *(max_dis_down + node) == -1)
		{
			*(max_dis_down+node) = *(max_dis_down + prev) + 1;
			return -1;
		}
	}
	return *(max_dis_down + node);
}

void get_farthest_pair(int node, int prev)
{
	int temp1 = -1, temp2 = -1;
	for (auto var : (settlements + node)->link)
	{
		if (prev != var)
		{
			if (*(max_dis_down+var) > temp1)
			{
				temp2 = temp1;
				temp1 = *(max_dis_down + var);
			}
			else if (*(max_dis_down+var)>temp2)
			{
				temp2 = *(max_dis_down + var);
			}
		}
	}

	for (auto var : (settlements + node)->link)
	{
		if (prev != var)
		{
			int linkDistance = *(max_dis_down + var) == temp1 ? temp2 : temp1;

			if (linkDistance != -1)
			{
				linkDistance += 2;
			}
			*(max_dis_up+var) = linkDistance;

			if (*(max_dis_up + node) != -1)
			{
				*(max_dis_up+var)= (*(max_dis_up + var) > *(max_dis_up + node) + 1) ? *(max_dis_down + var) : *(max_dis_up + node) + 1;
			}
			if ((settlements + var)->isEvil)
			{
				*(max_dis_up+var) = (*(max_dis_up + var) > 0) ? *(max_dis_down + node) : 0;
			}
			get_farthest_pair(var, node);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, d;

	cin >> n >> m >> d;

	max_dis_up = new int[n];
	max_dis_down = new int[n];

	set_evil(m);

	make_link(n);

	get_farthest(0, -1);

	max_dis_up[0] = settlements[0].isEvil ? 0 : -1;

	get_farthest_pair(0, -1);

	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		num += (*(max_dis_down + i) <= d && *(max_dis_up + i) <= d   ? 1 : 0);
	}

	cout << num - m;
	return 0;
}