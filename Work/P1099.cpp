#include<bits/stdc++.h>
const int maxn = 305;
const int INF = 0x3f3f3f3f;
std::vector<std::pair<int,int> > G[maxn];
int dist[maxn][maxn];
int fa[maxn], weight[maxn];
bool vis[maxn];
int pxj[maxn];
int id1, id2;
int n, S;
void dfs1(int idx, int u, int f, int dep) {
    dist[idx][u] = dep;
    for(std::vector<std::pair<int,int> >::iterator it = G[u].begin(); it != G[u].end(); ++it) {
        int v = it->first, w = it->second;
        if(v == f) continue;
        dfs1(idx, v, u, dep + w);
    }
}
void dfs(int u, int f) {
    fa[u] = f;
    for(std::vector<std::pair<int,int> >::iterator it = G[u].begin(); it != G[u].end(); ++it) {
        int v = it->first, w = it->second;
        if(v == f) continue;
        weight[v] = w;
        dfs(v, u);
    }
}
void init() {
    for(int i = 1; i <= n; i++) {
        dfs1(i, i, 0, 0);
    }
    int maxdep = -1, idx = -1;
    for(int i = 1; i <= n; i++) {
        if(dist[1][i] > maxdep) {
            maxdep = dist[1][i]; idx = i;
        }
    }
    id1 = idx;
    maxdep = idx = -1;
    for(int i = 1; i <= n; i++) {
        if(dist[id1][i] > maxdep) {
            maxdep = dist[id1][i]; idx = i;
        }
    }
    id2 = idx;
    dfs(id1, 0);
}
int cal_pxj() {
    memset(pxj, 0x3f, sizeof pxj);
    for(int i = 1; i <= n; i++) if(vis[i]) {
        for(int j = 1; j <= n; j++) {
            pxj[j] = std::min(pxj[j], dist[i][j]);
        }
    }
    int ret = -INF;
    for(int i = 1; i <= n; i++) if(!vis[i]) ret = std::max(ret, pxj[i]);
    return ret;
}
void solve() {
    std::vector<int> points, edges;
    int size = 0;
    for(int i = id2; i; i = fa[i]) {
        points.push_back(i);
        edges.push_back(weight[i]);// weight[id1] = 0
        //printf("points[%d]: %d, edges[%d]: %d\n", size, points[size], size, edges[size]);
        size++;
    }
    int len = 0, left = 0, right = 0; vis[points[0]] = true;
    int ans = INF;
    while(right < size) {
        //printf("(left, right): %d %d, len = %d\n", points[left], points[right], len);
        if(len >= 0 && len <= S) ans = std::min(ans, cal_pxj());
        while(len + edges[right] <= S && right + 1 < size) {
            len += edges[right];
            right++;
            vis[points[right]] = true;
            //printf("(left, right): %d %d, len = %d\n", points[left], points[right], len);
            if(len >= 0 && len <= S) ans = std::min(ans, cal_pxj());
        }
        len -= edges[left];
        vis[points[left]] = false;
        left++;
        if(left == size) break;
    }
    printf("%d\n", ans);
}
int main() {
    scanf("%d %d", &n, &S);
    for(int i = 1; i < n; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        G[u].push_back(std::make_pair(v, w));
        G[v].push_back(std::make_pair(u, w));
    }
    init();
    solve();
    return 0;
}
