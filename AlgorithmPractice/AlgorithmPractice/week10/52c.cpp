#include <iostream>

using namespace std;

#define LL long long

typedef struct node
{
	LL left;
	LL right;
	LL min;
	LL incre;	
}node;

LL input[200005];

LL n, m;
LL lf, rg, v;

node tree[1000005];

void buildTree(LL node, LL left, LL right)
{
	LL mid;
	tree[node].left = left;
	tree[node].right = right;
	if (left == right)
	{
		tree[node].min = input[left];
		return;
	}
	mid = left/2 + right/2;
	buildTree(node * 2, left, mid);
	buildTree(node * 2 + 1, mid + 1, right);

	if (tree[node * 2].min + tree[node * 2].incre < tree[node * 2 + 1].min + tree[node * 2 + 1].incre)
	{
		tree[node].min = tree[node * 2].min + tree[node * 2].incre;
	}
	else
	{
		tree[node].min = tree[node * 2 + 1].min + tree[node * 2 + 1].incre;
	}
	return;
}

LL query(LL node, LL left, LL right)
{
	LL mid, lRt, rRt;
	if (left <= tree[node].left && tree[node].right <= right)
	{
		return tree[node].min + tree[node].incre;
	}
	if (tree[node].right < left || right < tree[node].left)
	{
		return LLONG_MAX;
	}
	lRt = query(node * 2, left, right);
	rRt = query(node * 2 + 1, left, right);

	if (lRt > rRt)
	{
		return rRt + tree[node].incre;
	}
	else
	{
		return lRt + tree[node].incre;
	}
}

void update(LL node, LL left, LL right,LL value)
{
	LL lRt, rRt;
	if (left <= tree[node].left && tree[node].right <= right)
	{
		tree[node].incre += value;
		return;
	}
	if (tree[node].right < left || right < tree[node].left)
	{
		return;
	}
	update(node * 2, left, right, value);
	update(node * 2 + 1, left, right, value);

	lRt = tree[node * 2].min + tree[node * 2].incre;
	rRt = tree[node * 2 + 1].min + tree[node * 2 + 1].incre;
	if (lRt > rRt)
	{
		tree[node].min = rRt;
	}
	else
	{
		tree[node].min = lRt;
	}
}

int main()
{
	cin >> n;
	char temp;
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}

	buildTree(1, 1, n);

	cin >> m;
	for (int i = 0; i <= m; i++)
	{
		cin >> lf >> rg;
		lf++; 
		rg++;
		if (getchar() == '\n')
		{
			if (lf <= rg)
			{
				cout << query(1, lf, rg)<<"\n";
			}
			else
			{
				LL r1 = query(1, 1, rg);
				LL r2 = query(1, lf, n);

				if (r1 > r2)
				{
					cout << r2 << "\n";
				}else{
					cout << r1 << "\n";
				}
			}
			continue;
		}
		else
		{
			cin >> v;
			if (lf <= rg)
			{
				update(1, lf, rg, v);
			}
			else
			{
				update(1, 1, rg, v);
				update(1, lf, n, v);
			}
		}
		
	}

	return 0;
}