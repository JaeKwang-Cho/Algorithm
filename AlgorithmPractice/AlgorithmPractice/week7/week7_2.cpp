#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 1336 A

typedef struct _node
{
	__int32 parent;
	__int32 rootDist;
	__int32 nChild;
}node;
node nodes[200000];
vector<__int32> arr[200000];
__int32 result[200000];
__int32 n,k;

__int32 startNode(__int32 node, __int32 parent, __int32 rootDist)
{
	nodes[node].parent = parent;
	nodes[node].rootDist = rootDist+1;
	nodes[node].nChild = 0;

	for (auto i : arr[node])
	{
		if (i != parent)
		{
			nodes[node].nChild+=startNode(i, node, nodes[node].rootDist)+1;
		}
	}
	result[node] = nodes[node].rootDist - nodes[node].nChild;
	return nodes[node].nChild;
}

int main()
{
	cin >> n >> k;
	__int64 ans = 0;

	for (int i = 0; i < n - 1; i++)
	{

		__int32 u, v;
		cin >> u >> v;
		arr[u - 1].push_back(v - 1);
		arr[v - 1].push_back(u - 1);
	}
	startNode(0, 0,-1);

	sort(result+1,result+n);

	for (int i = n-1; i > n - k-1; i--)
	{
		ans += result[i];
	}

	cout.setf(ios_base::dec);
	cout << ans;
	return 0;
}