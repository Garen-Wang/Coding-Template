#include<bits/stdc++.h>
#define ll long long
const int maxn = 50005;
std::vector<std::pair<int,int> > G[maxn];
std::multiset<int> s[maxn];
int n, m;

// get the diameter of tree
int dep[maxn];
void bfs(int s, int &maxdep, int &idx) {
    std::queue<int> q;
    memset(dep, -1, sizeof dep);
    dep[s] = 0; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(dep[u] > maxdep) {
            maxdep = dep[u]; idx = u;
        }
        for(auto it : G[u]) {
            int v = it.first, w = it.second;
            if(dep[v] == -1) {
                dep[v] = dep[u] + w; q.push(v);
            }
        }
    }
}
int get_diameter() {
    int maxdep = -1, idx = -1;
    bfs(1, maxdep, idx);
    int temp = idx;
    maxdep = idx = -1;
    bfs(temp, maxdep, idx);
    return maxdep;
}
int res;
int dfs(int u, int f, int mid) {
    s[u].clear();
    for(auto it : G[u]) {
        int v = it.first, w = it.second;
        if(v == f) continue;
        int temp = dfs(v, u, mid) + w;
        if(temp >= mid) {
            res++;
        } else {
            s[u].insert(temp);
        }
    }
    int ret = 0;
    while(!s[u].empty()) {
        int temp = *s[u].begin();
        if(s[u].size() == 1) {
            ret = std::max(ret, temp);
            break;
        }
        auto it = s[u].lower_bound(mid - temp);
        if(it == s[u].begin() && s[u].count(*it) == 1) ++it;
        if(it == s[u].end()) {
            ret = std::max(ret, temp);
            s[u].erase(s[u].find(temp));
        } else {
            res++;
            s[u].erase(s[u].find(temp));
            s[u].erase(s[u].find(*it));
        }
    }
    return ret;
}
bool check(int mid) {
    res = 0;
    dfs(1, 0, mid);
    return res >= m;
}
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i < n; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        G[u].push_back(std::make_pair(v, w));
        G[v].push_back(std::make_pair(u, w));
    }
    int left = 0, right = get_diameter(), ans = -1;
    while(left <= right) {
        int mid = (left + right) >> 1;
        if(check(mid)) ans = mid, left = mid + 1;
        else right = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}
