/*************************************************************************
 @Author: Garen
 @Created Time : Wed 13 Feb 2019 04:26:31 PM CST
 @File Name: P1041.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 305;
const int INF = 0x3f3f3f3f;
std::vector<int> G[maxn];
std::vector<int> help[maxn];
int dep[maxn], fa[maxn];
bool infected[maxn];
bool changed[maxn];
int n, m;
int lim;
int ans = INF;
void dfs1(int u, int f) {
    dep[u] = dep[f] + 1; fa[u] = f;
    for(auto v : G[u]) {
        if(v == f) continue;
        dfs1(v, u);
    }
}
void dfs(int t, int res) {
    if(res >= ans) return;
    if(t == lim + 1) {
        ans = std::min(ans, res);
        return;
    }
    int cnt = 0;
    for(auto u : help[t]) {
        if(infected[fa[u]]) {
            infected[u] = true;
            changed[u] = true;
            cnt++;
        }
    }
    if(cnt == 0) {
        ans = std::min(ans, res);
        return;
    }
    for(auto u: help[t]) {
        if(changed[u]) {
            infected[u] = false;
            dfs(t + 1, res + cnt - 1);
            infected[u] = true;
        }
    }
    for(auto u : help[t]) {
        if(changed[u]) {
            infected[u] = changed[u] = false;
        }
    }
}
int main() {
    cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    for(int i = 1; i <= n; i++) {
        lim = std::max(lim, dep[i]);
        help[dep[i]].push_back(i);
    }
    infected[1] = true;
    dfs(2, 1);
    cout << ans << endl;
    return 0;
}
