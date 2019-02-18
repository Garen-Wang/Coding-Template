#include<cstdio>
#include<stack>
const int maxn = 100005;
int to[maxn];
int w[maxn];
int dfn[maxn], low[maxn], dtot;
int col[maxn], ctot;
std::stack<int> sta;
bool vis[maxn];
int c[maxn];
int n;

void tarjan(int u)
{
	dfn[u] = low[u] = ++dtot;
	sta.push(u); vis[u] = true;
	int v = to[u];
	if(!dfn[v])
	{
		tarjan(v); low[u] = std::min(low[u], low[v]);
	}
	else if(vis[v]) low[u] = std::min(low[u], dfn[v]);
	if(dfn[u] == low[u])
	{
		ctot++;
		while(sta.top() != u)
		{
			int x = sta.top(); sta.pop(); vis[x] = false;
			col[x] = ctot;
		}
		int x = sta.top(); sta.pop(); vis[x] = false;
		col[x] = ctot;
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &to[i], &w[i]);
	}
	for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
	for(int i = 1; i <= n; i++)
	{
		c[col[i]] += w[i];
	}
	int maxv = -1;
	for(int i = 1; i <= ctot; i++) maxv = std::max(maxv, c[i]);
	printf("%d\n", maxv);
	return 0;
}
