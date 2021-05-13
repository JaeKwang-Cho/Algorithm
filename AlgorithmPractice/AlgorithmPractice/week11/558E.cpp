#include <iostream>

using namespace std;

struct Node
{
	int left;
	int right;
	int count;
	int lazy;
};

char S[1000005];
int n, q;
Node T[26][400000];

int pullUp(int treenum, int rootnode)
{
	T[treenum][rootnode].count = T[treenum][rootnode * 2].count + T[treenum][rootnode * 2 + 1].count;
	return 0;
}

int build(int treenum, int rootnode, int left, int right)
{
	int mid;
	T[treenum][rootnode].left = left;
	T[treenum][rootnode].right = right;
	T[treenum][rootnode].lazy = -1;
	if (left == right)
	{
		if (S[left] - 'a' == treenum)
		{
			T[treenum][rootnode].count = 1;
		}
		else
		{
			T[treenum][rootnode].count = 0;
		}
		return 0;
	}
	mid = (left + right) / 2;
	build(treenum, rootnode * 2, left, mid);
	build(treenum, rootnode * 2 + 1, mid + 1, right);

	pullUp(treenum, rootnode);
	return 0;
}
int pushDown(int treenode, int rootnode)
{
	int lazy = T[treenode][rootnode].lazy;
	if (lazy == 1)
	{
		T[treenode][rootnode * 2].lazy = 1;
		T[treenode][rootnode * 2].count
			= T[treenode][rootnode * 2].right - T[treenode][rootnode * 2].left + 1;
		T[treenode][rootnode * 2 + 1].lazy = 1;
		T[treenode][rootnode * 2 + 1].count
			= T[treenode][rootnode * 2 + 1].right - T[treenode][rootnode * 2 + 1].left + 1;
	}
	else if (lazy == 0)
	{
		T[treenode][rootnode * 2].lazy = 0;
		T[treenode][rootnode * 2].count = 0;
		T[treenode][rootnode * 2 + 1].lazy = 0;
		T[treenode][rootnode * 2 + 1].count = 0;
	}
	T[treenode][rootnode].lazy = -1;
	return 0;
}

int query(int treenode, int rootnode, int left, int right)
{
	int mid, lrt, rrt;
	if (T[treenode][rootnode].left >= left && T[treenode][rootnode].right <= right)
	{
		return T[treenode][rootnode].count;
	}
	if (T[treenode][rootnode].left > right || T[treenode][rootnode].right < left)
	{
		return 0;
	}
	pushDown(treenode, rootnode);

	lrt = query(treenode, rootnode * 2, left, right);
	rrt = query(treenode, rootnode * 2 + 1, left, right);
	return lrt + rrt;

}

int update(int treenode, int rootnode, int left, int right, int value)
{
	if (T[treenode][rootnode].left >= left && T[treenode][rootnode].right <= right)
	{
		if (value == 1)
		{
			T[treenode][rootnode].count 
				= T[treenode][rootnode].right - T[treenode][rootnode].left + 1;
			T[treenode][rootnode].lazy = 1;
		}
		else
		{
			T[treenode][rootnode].lazy = 0;
			T[treenode][rootnode].count = 0;
		}
		return 0;
	}
	if (T[treenode][rootnode].left > right || T[treenode][rootnode].right < left)
	{
		return 0;
	}
	pushDown(treenode, rootnode);
	update(treenode,rootnode * 2, left, right, value);
	update(treenode, rootnode * 2+1, left, right, value);
	pullUp(treenode, rootnode);
	return 0;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	cin >> S + 1;

	int num[26];

	for (int i = 0; i < 26; i++)
	{
		build(i, 1, 1, n);
	}
	int l, r, v, iter;
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r >> v;
		for (int j = 0; j < 26; j++)
		{
			num[j] = query(j, 1, l, r);
			update(j, 1, l, r, 0);
		}
		if (v == 1)
		{
			iter = l;
			for (int j = 0; j < 26; j++)
			{
				if (num[j] > 0)
				{
					update(j, 1, iter, iter + num[j] - 1, 1);
				}
				iter += num[j];
			}
		}
		else
		{
			iter = l;
			for (int j = 0; j < 26; j++)
			{
				if (num[25 - j] > 0)
				{
					update(25 - j, 1, iter, iter + num[25 - j] - 1, 1);
				}
				iter += num[25 - j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (query(j, 1, i, i) == 1)
			{
				putchar('a' + j);
			}
		}
	}
	cout << "\n";

	return 0;
}