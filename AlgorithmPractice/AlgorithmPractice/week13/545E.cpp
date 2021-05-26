#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class triple
{
public:
	int des;
	int weight;
	int edgeNum;
};

vector<triple> ED[300005];

long long ShortestPathLength[300005];
int EdgeNums[300005];
int EdgeLengths[300005];
bool Visit[300005];

class pkt
{
public:
	long long l;
	int weight;
	int src;
	int des;
	int edgeNum;
	bool operator < (const pkt& k) const
	{
		return l > k.l;
	}
};

priority_queue<pkt> Q;

void Dij(int source)
{
	pkt p;
	pkt q;
	p.l = 0;
	p.weight = 0;
	p.src = 0;
	p.des = source;
	p.edgeNum = 0;

	Q.push(p);
	while (Q.empty() == false)
	{
		p = Q.top();
		Q.pop();
		if (Visit[p.des])
		{
			if (p.l==ShortestPathLength[p.des] && p.weight < EdgeLengths[p.des])
			{
				EdgeNums[p.des] = p.edgeNum;
				EdgeLengths[p.des] = p.weight;
			}
			continue;
		}
		Visit[p.des] = true;
		ShortestPathLength[p.des] = p.l;

		EdgeNums[p.des] = p.edgeNum;
		EdgeLengths[p.des] = p.weight;

		for (int i = 0; i < ED[p.des].size(); i++)
		{
			q.l = ShortestPathLength[p.des] + ED[p.des][i].weight;
			q.weight = ED[p.des][i].weight;
			q.src = p.des;
			q.des = ED[p.des][i].des;
			q.edgeNum = ED[p.des][i].edgeNum;
			Q.push(q);
		}
	}

}

int n;
int m;
int u;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	int A;
	int B;
	int W;
	long long ans = 0;
	triple temp;

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> A >> B >> W;
		temp.des = B;
		temp.weight = W;
		temp.edgeNum = i;

		ED[A].push_back(temp);

		temp.des = A;
		temp.weight = W;
		temp.edgeNum = i;

		ED[B].push_back(temp);
	}
	cin >> u;
	Dij(u);

	for (int i = 1; i <= n; i++)
	{
		if (i != u)
		{
			ans += EdgeLengths[i];
		}
	}
	cout << ans << "\n";
	for (int i = 1; i <= n; i++)
	{
		if (i != u)
		{
			cout << EdgeNums[i]<<" ";
		}
	}
	return 0;
}