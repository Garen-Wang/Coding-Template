#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1005;
vector<int> G[maxn];

int father[maxn], siz[maxn];
int fa[maxn];
int midpoint[maxn];
int cnt[maxn];
int maxd, idx;
int n, m;

int find(int x){
    if(father[x] == x) return x;
    return father[x] = find(father[x]);
}
void dfs(int u, int f, int dep) {
    fa[u] = f;
    if(dep > maxd) maxd = dep, idx = u;
    for(auto v: G[u]) {
        if(v == f) continue;
        dfs(v, u, dep + 1);
    }
}
void solve(int s) {
    maxd = idx = -1;
    dfs(s, 0, 0);
    int temp = idx;
    //cout << temp << endl;
    maxd = idx = -1;
    dfs(temp, 0, 0);
    //cout << maxd << endl;
    int mid = idx;
    for(int i = 1; i <= maxd / 2; i++) mid = fa[mid];
    midpoint[s] = mid;
}
int get_diameter() {
    maxd = idx = -1;
    dfs(1, 0, 0);
    int temp = idx;
    maxd = idx = -1;
    dfs(temp, 0, 0);
    return maxd;
}
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) father[i] = i, siz[i] = 1;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
        int uu = find(u), vv = find(v);
        if(uu == vv) continue;
        if(siz[uu] < siz[vv]) std::swap(uu, vv);
        father[vv] = uu; siz[uu] += siz[vv];
    }
    //for(int i = 1; i <= n; i++) cout << father[i] << endl;
    for(int i = 1; i <= n; i++) if(find(i) == i) {
        solve(i);
    }
    //cout << midpoint[5] << endl;
    int ans = 0x7fffffff, rt = -1;
    for(int now = 1; now <= n; now++) {
        for(int i = 1; i <= n; i++) {
            int temp = find(i), temp2 = find(now);
            if(temp != temp2 && temp == i) {
                //cout << now << ' ' << midpoint[temp] << endl;
                G[now].push_back(midpoint[temp]); cnt[now]++;
                G[midpoint[temp]].push_back(now); cnt[midpoint[temp]]++;
            }
        }
        int res = get_diameter();
        if(res < ans) {
            ans = res, rt = now;
        }
        for(int i = 1; i <= n; i++)
        {
            while(cnt[i]--) {
                G[i].pop_back();
            }
            //cout << "test: " << cnt[i] << endl;
            cnt[i]++;
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++) {
        int temp = find(i), temp2 = find(rt);
        if(temp != temp2 && temp == i) {
            cout << rt << ' ' << midpoint[temp] << endl;
        }
    }
    return 0;
}
