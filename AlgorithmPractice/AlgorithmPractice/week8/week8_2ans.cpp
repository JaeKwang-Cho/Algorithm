#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;

struct node
{
    int v;
    int next;
};

node edge[2 * maxn];
int first[maxn], p[maxn], dis1[maxn], dis2[maxn];
int n, m, d, num, p1, p2;

void addedge(int u, int v)
{
    edge[num].v = v;
    edge[num].next = first[u];
    first[u] = num++;
}

void dfs(int* dis, int cur, int fa)
{
    int i, v;
    for (i = first[cur]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if (v != fa)
        {
            dis[v] = dis[cur] + 1;
            dfs(dis, v, cur);
        }
    }
}

int main()
{
    int i, u, v, maxx, ans;
    cin >> n >> m >> d;
    for (i = 1; i <= m; i++) cin >> p[i];
    memset(first, -1, sizeof(first));
    num = 0;
    for (i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
    }
    dis1[p[1]] = 0;
    dfs(dis1, p[1], 0);
    maxx = -1;
    for (i = 1; i <= m; i++)
    {
        if (maxx < dis1[p[i]])
        {
            maxx = dis1[p[i]], p1 = p[i];
        }
    }
    dis1[p1] = 0;
    dfs(dis1, p1, 0);
    maxx = -1;
    for (i = 1; i <= m; i++)
    {
        if (maxx < dis1[p[i]])
        {
            maxx = dis1[p[i]], p2 = p[i];
        }
    }
    dis2[p2] = 0;
    dfs(dis2, p2, 0);

    ans = 0;
    for (i = 1; i <= n; i++)
    {
        if (dis1[i] <= d && dis2[i] <= d) ans++;
    }
    printf("%d\n", ans);
    return 0;
}