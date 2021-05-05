#include <iostream>

using namespace std;

#define LL long long

typedef struct node_t
{
	LL cntOf4 = 0;
	LL cntOf7 = 0;
	LL s4to7 = 1;
	LL s7to4 = 1;
	bool isSwitched = false;
}node_t;

int input[100005];
string command;

const char* countCommand = "count";
const char* switchcommand = "switch";

LL n, m;
LL lf, rg, v;

node_t tree[1000005];

LL myMax(LL p1, LL p2)
{
	if (p1 > p2)
	{
		return p1;
	}
	else
	{
		return p2;
	}
}
void mySwap(node_t* t)
{
	LL temp = t->cntOf7;
	t->cntOf7 = t->cntOf4;
	t->cntOf4 = temp;

	temp = t->s4to7;
	t->s4to7 = t->s7to4;
	t->s7to4 = temp;

	t->isSwitched = !(t->isSwitched);
}

node_t coalesce(node_t n1, node_t n2)
{
	node_t result;
	result.cntOf4 = n1.cntOf4 + n2.cntOf4;
	result.cntOf7 = n1.cntOf7 + n2.cntOf7;

	result.s4to7 = myMax(n1.s4to7 + n2.cntOf7, myMax(n1.cntOf4 + n2.cntOf7, n1.cntOf4 + n2.s4to7));
	result.s7to4 = myMax(n1.s7to4 + n2.cntOf4, myMax(n1.cntOf7 + n2.cntOf4, n1.cntOf7 + n2.s7to4));

	return result;
}

void buildTree(LL node, LL left, LL right)
{
	LL mid;
	if (left == right)
	{
		tree[node].cntOf4 = (input[left] == 4);
		tree[node].cntOf7 = (input[left] == 7);
		return;
	}

	mid = left / 2 + right / 2;
	buildTree(node * 2, left, mid);
	buildTree(node * 2 + 1, mid + 1, right);

	tree[node] = coalesce(tree[node * 2], tree[node * 2 + 1]);
	return;
}

void revise(LL node, LL treeLeft, LL treeRight, LL left, LL right)
{
	LL mid;
	if (left <= treeLeft && treeRight <= right)
	{
		mySwap(tree + node);
		return;
	}

	if (tree[node].isSwitched == true)
	{
		mySwap(tree + (node * 2));
		mySwap(tree + (node * 2 + 1));
		tree[node].isSwitched = false;
	}


	mid = treeLeft / 2 + treeRight / 2;
	if (left <= m)
	{
		revise(node * 2, treeLeft, mid, left, right);
	}
	if (right > m)
	{
		revise(node * 2 + 1, mid + 1, treeRight, left, right);
	}
	tree[node] = coalesce(tree[node * 2], tree[node * 2 + 1]);
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		char x; cin >> x;
		input[i] = x - '0';
	}

	buildTree(1, 1, n);

	for (int i = 0; i < m; i++)
	{
		cin >> command;

		if (command == "count")
		{
			cout << tree[1].s4to7 << "\n";
		}
		else
		{
			cin >> lf >> rg;
			revise(1, 1, n, lf, rg);
		}

	}

	return 0;
}