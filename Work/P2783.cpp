/*************************************************************************
 @Author: Garen
 @Created Time : Thu 31 Jan 2019 05:21:10 PM CST
 @File Name: P2783.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 50005, maxm = 100005;
struct Edges {
    int next, to;
} e[maxm << 1], e2[maxn << 1];
int head[maxn], tot;
int head2[maxn], tot2;
int n, m, q;
//
int dfn[maxn], low[maxn], dtot;
int stack[maxn << 1], stop;
bool vis[maxn];
int col[maxn], ctot;
//
int dep[maxn], fa[maxn], size[maxn], wson[maxn];
int top[maxn];
void link(int u, int v) {
    e[++tot] = (Edges){head[u], v};
    head[u] = tot;
}
void link2(int u, int v) {
    e2[++tot2] = (Edges){head2[u], v};
    head2[u] = tot2;
}
void tarjan(int u, int f) {
    dfn[u] = low[u] = ++dtot;
    stack[++stop] = u; vis[u] = true;
    for(int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if(v == f) continue;
        if(!dfn[v]) {
            tarjan(v, u); low[u] = std::min(low[u], low[v]);
        } else if(vis[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]) {
        ctot++;
        int sb;
        do {
            sb = stack[stop--]; vis[sb] = false;
            col[sb] = ctot;
        } while(sb != u);
    }
}
void dfs1(int u, int f) {
    dep[u] = dep[f] + 1; fa[u] = f; size[u] = 1;
    for(int i = head2[u]; i; i = e2[i].next) {
        int v = e2[i].to;
        if(v == fa[u]) continue;
        dfs1(v, u);
        size[u] += size[v];
        if(size[v] > size[wson[u]]) wson[u] = v;
    }
}
void dfs2(int u, int topf) {
    top[u] = topf;
    if(wson[u]) dfs2(wson[u], topf);
    for(int i = head2[u]; i; i = e2[i].next) {
        int v = e2[i].to;
        if(v == wson[u] || v == fa[u]) continue;
        dfs2(v, v);
    }
}
int get_lca(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) std::swap(u, v);
        u = fa[top[u]];
    }
    if(dep[u] > dep[v]) std::swap(u, v);
    return u;
}
void print(int x) {
    std::vector<int> buf;
    while(x) {
        buf.push_back(x & 1);
        x >>= 1;
    }
    for(int i = buf.size() - 1; i >= 0; i--) cout << buf[i];
}
int main() {
    cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        link(u, v), link(v, u);
    }
    for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i, 0);
    // print array col
    //for(int i = 1; i <= n; i++) cout << col[i] << ' ';
    //cout << endl;
    for(int u = 1; u <= n; u++) {
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(col[u] != col[v]) {
                link2(col[u], col[v]);
                // print the new tree
                //cout << col[u] << ' ' << col[v] << endl;
            }
        }
    }
    dfs1(1, 0); dfs2(1, 1);
    cin >> q;
    while(q--) {
        int u, v; cin >> u >> v;
        u = col[u], v = col[v];
        int lca = get_lca(u, v);
        //cout << dep[u] - dep[lca] + dep[v] - dep[lca] + 1 << endl;
        print(dep[u] - dep[lca] + dep[v] - dep[lca] + 1);
        cout << endl;
    }
    return 0;
}
