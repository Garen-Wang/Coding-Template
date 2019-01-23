#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
const int maxn = 205;
const double INF = 1e15;
struct Edges
{
	int next, to; double weight;
} e[100005];
int head[maxn], tot;

double x[maxn], y[maxn];
int n, m;

bool vis[maxn];
double dist[maxn];

int pre[maxn];

double dis(int u, int v)
{
	return sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}
void link(int u, int v, double w)
{
    e[++tot] = (Edges){head[u], v, w};
    head[u] = tot;
}
void spfa()
{
	std::queue<int> q;
	for(int i = 1; i <= n; i++) dist[i] = INF;
	dist[1] = 0; q.push(1); vis[1] = true;
	while(!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = false;
		for(int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if(dist[u] + e[i].weight < dist[v])
			{
				dist[v] = dist[u] + e[i].weight;
				// tag
				pre[v] = u;
				if(!vis[v])
				{
					q.push(v); vis[v] = true;
				}
			}
		}
	}
}
void spfa2(int nou, int nov)
{
	memset(vis, false, sizeof vis);
	for(int i = 1; i <= n; i++) dist[i] = INF;
	std::queue<int> q;
	dist[1] = 0; q.push(1); vis[1] = true;
	while(!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = false;
		for(int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].to;
			if((u == nou && v == nov) || (u == nov && v == nou)) continue;
			if(dist[u] + e[i].weight < dist[v])
			{
				dist[v] = dist[u] + e[i].weight;
				if(!vis[v])
				{
					q.push(v); vis[v] = true;
				}
			}
 		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf%lf", &x[i], &y[i]);
	}
	while(m--)
	{
		int u, v; scanf("%d%d", &u, &v);
		link(u, v, dis(u, v)); link(v, u, dis(v, u));
	}
	spfa();
	double ans = INF, mem = dist[n];
	for(int i = n; i != 1; i = pre[i])
	{
		spfa2(i, pre[i]);
        ans = std::min(ans, dist[n]);
	}
	//printf("%.2lf\n", mem);
    if(ans == INF) printf("-1\n");
	printf("%.2lf\n", ans);
	return 0;
}
