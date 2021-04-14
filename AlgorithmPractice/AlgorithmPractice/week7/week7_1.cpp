#include <iostream>
#include <vector>

using namespace std;
// 839 C

typedef struct _node
{
	__int32 parent;
	__int32 nChild;
}node;

node nodes[100000];
vector<__int32> arr[100000];
__int32 n;

void startNode(__int32 node , __int32 parent)
{
	nodes[node].parent = parent;
	nodes[node].nChild = 0;

	for (auto i:arr[node])
	{
		if (i != parent)
		{
			nodes[node].nChild++;
			startNode(i, node);
		}
	}
}

double getNode(__int32 node)
{
	double mean = 0;
	if (nodes[node].nChild == 0)
	{
		return 0.0;
	}
	for (auto i : arr[node])
	{
		if (i != nodes[node].parent)
		{
			mean += getNode(i)+1;
		}
	}
	return mean / nodes[node].nChild;
}

int main()
{
	cin >> n;
	double ans;

	for (int i = 0; i < n-1; i++)
	{
		
		__int32 u, v;
		cin >> u >> v;
		arr[u-1].push_back(v-1);
		arr[v-1].push_back(u-1);
	}
	startNode(0,0);
	ans = getNode(0);

	cout.precision(15);
	cout << ans;
	return 0;
}