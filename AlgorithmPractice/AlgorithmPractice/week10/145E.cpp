#include <iostream>

using namespace std;

#define LL long long

typedef struct node_t
{
	LL left;
	LL right;
	LL cntOf4;
	LL cntOf7;
	LL s4to7;
	LL s7to4;
	bool isSwitched;
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
	tree[node].left = left;
	tree[node].right = right;
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
		swap(tree[node].cntOf4, tree[node].cntOf7);
		swap(tree[node].s4to7, tree[node].s7to4);
		tree[node].isSwitched = !tree[node].isSwitched;
		return;
	}
	swap(tree[node * 2].cntOf4, tree[node * 2].cntOf7);
	swap(tree[node * 2].s4to7, tree[node * 2].s7to4);
	tree[node * 2].isSwitched = !tree[node * 2].isSwitched;
	swap(tree[node * 2 + 1].cntOf4, tree[node * 2 + 1].cntOf7);
	swap(tree[node * 2 + 1].s4to7, tree[node * 2 + 1].s7to4);
	tree[node * 2 + 1].isSwitched = !tree[node * 2 + 1].isSwitched;
	tree[node].isSwitched = false;

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

	for (int i = 0; i <= m; i++)
	{
		cin >> command;

		if (command == "count")
		{
			cout << tree[1].cntOf4 << "\n";
		}
		else
		{
			cin >> lf >> rg;
			revise(1, 1, n, lf, rg);
		}

	}

	return 0;
}