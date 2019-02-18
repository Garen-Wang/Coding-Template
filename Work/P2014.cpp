/*************************************************************************
 @Author: Garen
 @Created Time : Fri 08 Feb 2019 09:41:26 PM CST
 @File Name: P2014.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 305;
std::vector<int> G[maxn];
int a[maxn];
int dp[maxn][maxn];
int size[maxn];
int n, m, rt;

void dfs(int u, int f) {
    size[u] = 1;
    for(auto v : G[u]) {
        if(v == f) continue;
        dfs(v, u);
        size[u] += size[v];
        for(int i = size[u]; i >= 1; i--) {
            for(int j = 0; j <= size[v]; j++) {
                if(i - j >= 1) dp[u][i] = std::max(dp[u][i], dp[u][i - j] + dp[v][j]);
            }
        }
    }
}
int main() {
    cin >> n >> m;
    rt = n + 1;
    for(int i = 1; i <= n; i++) {
        int f; cin >> f >> a[i];
        if(f == 0) f = rt;
        G[i].push_back(f);
        G[f].push_back(i);
        dp[i][1] = a[i];
    }
    dfs(rt, 0);
    cout << dp[rt][m + 1] << endl;
    return 0;
}
