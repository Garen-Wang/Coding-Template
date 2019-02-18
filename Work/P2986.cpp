#include<iostream>
#define ll long long
const ll maxn = 100005;
struct Edges
{
    ll next, to, weight;
} e[maxn << 1];
ll head[maxn], tot;

ll c[maxn], cc;
ll w[maxn];
ll dist[maxn];
ll cost[maxn];
ll n;

void link(ll u, ll v, ll w)
{
    e[++tot] = (Edges){head[u], v, w};
    head[u] = tot;
}
void dfs1(ll u, ll f)
{
    w[u] = c[u];
    for(ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if(v == f) continue;
        dist[v] = dist[u] + e[i].weight;
        dfs1(v, u);
        w[u] += w[v];
    }
}
void dfs2(ll u, ll f)
{
    for(ll i = head[u]; i; i = e[i].next)
    {
        ll v = e[i].to;
        if(v == f) continue;
        cost[v] = cost[u] - e[i].weight * w[v] + e[i].weight * (cc - w[v]);
        dfs2(v, u);
    }
}
int main()
{
    std::cin >> n;
    for(ll i = 1; i <= n; i++)
    {
       std::cin >> c[i]; 
       cc += c[i];
    }
    for(ll i = 1; i < n; i++)
    {
        ll u, v, w; std::cin >> u >> v >> w;
        link(u, v, w); link(v, u, w);
    }
    dfs1(1, 0);
    for(ll i = 1; i <= n; i++) cost[1] += dist[i] * c[i];
    //std::cout << cost[1] << std::endl;
    dfs2(1, 0);
    ll minv = 0x7fffffffffffffff;
    for(ll i = 1; i <= n; i++)
    {
        //std::cout << cost[i] << std::endl;
        minv = std::min(minv, cost[i]);
    }
    std::cout << minv << std::endl;
    return 0;
}
