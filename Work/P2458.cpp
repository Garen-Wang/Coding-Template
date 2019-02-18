#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 1505;
const int INF = 0x3f3f3f3f;
std::vector<int> G[maxn];
int a[maxn];
int dp[maxn][3];
int n;
// 1：当前节点有保安
// 2：当前节点没保安，但是父亲有
// 3：当前节点没保安，但是某个儿子有
void dfs(int u, int f) {
    dp[u][1] = a[u];
    int sum = 0;
    for(auto v : G[u]) {
        if(v == f) continue;
        dfs(v, u);
        dp[u][1] += std::min(dp[v][1], std::min(dp[v][2], dp[v][3]));
        dp[u][2] += std::min(dp[v][1], dp[v][3]);
        sum += std::min(dp[v][1], dp[v][3]);
    }
    dp[u][3] = INF;
    for(auto v : G[u]) {
        if(v == f) continue;
        dp[u][3] = std::min(dp[u][3], sum - std::min(dp[v][1], dp[v][3]) + dp[v][1]);
    }
}
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int u, m, v;
		cin >> u;
		cin >> a[u] >> m;
		while(m--) {
			cin >> v;
			G[u].push_back(v); G[v].push_back(u);
		}
	}
	dfs(1, 0);
    cout << std::min(dp[1][1], dp[1][3]) << endl;
	return 0;
}
