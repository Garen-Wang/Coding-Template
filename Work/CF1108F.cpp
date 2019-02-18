/*************************************************************************
 @Author: Garen
 @Created Time : Wed 30 Jan 2019 09:33:09 PM CST
 @File Name: Work/CF1108F.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int maxn = 200005;
const int INF = 0x3f3f3f3f;
// 原图
struct Edge {
    int u, v, w;
} edge[maxn];
int father[maxn], siz[maxn];
bool used[maxn];
int n, m;
// 最小生成树
struct Edges {
    int next, to, weight;
} e[maxn << 1];
int head[maxn], tot;
// 倍增
int dep[maxn];
int fa[maxn][20], maxv[maxn][20];

int find(int x) {
    if(father[x] == x) return x;
    return father[x] = find(father[x]);
}
void link(int u, int v, int w) {
    e[++tot] = (Edges){head[u], v, w};
    head[u] = tot;
}
void dfs(int u, int f, int w) {
    //cout << u << endl;
    dep[u] = dep[f] + 1; fa[u][0] = f; maxv[u][0] = w;
    for(int i = 1; (1 << i) <= dep[u]; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        maxv[u][i] = std::max(maxv[u][i - 1], maxv[fa[u][i - 1]][i - 1]);
    }
    for(int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == f) continue;
        dfs(v, u, e[i].weight);
    }
}
int querymin(int u, int v) {
    //cout << u << ' ' << v << endl;
    int ans = -INF;
    while(dep[u] != dep[v]) {
        if(dep[u] < dep[v]) std::swap(u, v);
        int delta = dep[u] - dep[v];
        for(int i = 19; i >= 0; i--) {
            if((1 << i) & delta) {
                ans = std::max(ans, maxv[u][i]);
                u = fa[u][i];
            }
        }
    }
    if(u != v) {
        for(int i = 19; i >= 0; i--) {
            if(fa[u][i] != fa[v][i]) {
                ans = std::max(ans, maxv[u][i]);
                ans = std::max(ans, maxv[v][i]);
                u = fa[u][i]; v = fa[v][i];
            }
        }
        ans = std::max(ans, maxv[u][0]);
        ans = std::max(ans, maxv[v][0]);
    }
    //cout << ans << endl;
    return ans;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    std::sort(edge + 1, edge + 1 + m, [](Edge A, Edge B) {
        return A.w < B.w;
    });
    for(int i = 1; i <= n; i++) father[i] = i, siz[i] = 1;
    //cout << endl;
    for(int i = 1; i <= m; i++) {
        int u = find(edge[i].u), v = find(edge[i].v);
        if(u == v) continue;
        used[i] = true;
        if(siz[u] < siz[v]) std::swap(u, v);
        father[v] = u; siz[u] += siz[v];
        link(edge[i].u, edge[i].v, edge[i].w), link(edge[i].v, edge[i].u, edge[i].w);
        //cout << edge[i].u << ' ' << edge[i].v << ' ' << edge[i].w << endl;
    }
    dfs(1, 0, 0);
    int ans = 0;
    for(int i = 1; i <= m; i++) if(!used[i]) {
        int res = querymin(edge[i].u, edge[i].v);
        if(edge[i].w <= res) {
            ans += res - edge[i].w + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
