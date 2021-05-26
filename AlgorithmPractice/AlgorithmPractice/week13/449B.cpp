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
	bool isTrail;
};

vector<triple> ED[1000005];

long long ShortestPathLength[1000005];
bool Visit[1000005];

bool trailRefCount[5000005];

int ans = 0;

class pkt
{
public:
	long long l;
	int weight;
	int src;
	int des;
	int edgeNum;
	bool isTrail;
	bool operator < (const pkt& k) const
	{
		if (l > k.l)
		{
			return l > k.l;
		}
		else if (l == k.l)
		{
			if (!k.isTrail && isTrail)
			{
				return true;
			}
			if (k.isTrail && !isTrail)
			{
				return false;
			}
		}
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
	p.isTrail = false;

	Q.push(p);
	while (Q.empty() == false)
	{
		p = Q.top();
		Q.pop();
		if (Visit[p.des]) 
		{
			continue;
		}
		Visit[p.des] = true;

		if (p.isTrail)
		{
			trailRefCount[p.edgeNum] = true;
			ans++;
		}

		ShortestPathLength[p.des] = p.l;

		for (int i = 0; i < ED[p.des].size(); i++)
		{
			q.l = ShortestPathLength[p.des] + ED[p.des][i].weight;
			q.weight = ED[p.des][i].weight;
			q.src = p.des;
			q.des = ED[p.des][i].des;
			q.edgeNum = ED[p.des][i].edgeNum;
			q.isTrail = ED[p.des][i].isTrail;
			Q.push(q);
		}
	}
}

int n;
int m;
int k;
int s;
int y;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);

	int src;
	int des;
	int weight;
	triple temp;

	cin >> n >> m >>k;
	for (int i = 1; i <= m; i++)
	{
		cin >> src >> des >> weight;
		temp.des = des;
		temp.weight = des;
		temp.edgeNum = i;
		temp.isTrail = false;

		ED[src].push_back(temp);

		temp.des = src;
		temp.weight = weight;
		temp.edgeNum = i;
		temp.isTrail = false;

		ED[des].push_back(temp);
	}
	for (int i = m + 1; i <= m + k; i++)
	{
		cin >> des >> weight;
		temp.des = des;
		temp.weight = weight;
		temp.edgeNum = i;
		temp.isTrail = true;

		ED[1].push_back(temp);

		temp.des = 1;
		temp.weight = weight;
		temp.edgeNum = i;
		temp.isTrail = true;

		ED[des].push_back(temp);
	}
	
	Dij(1);
	cout << k - ans;
	return 0;
}