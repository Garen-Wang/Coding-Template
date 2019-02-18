#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll maxn = 100005;
const ll INF = 0x3f3f3f3f;
struct Edges {
    ll next, to;
} e[maxn << 1];
ll head[maxn], tot;
ll n;
ll w[maxn];
ll a[maxn];
ll dep[maxn];
bool gg;
void link(ll u, ll v) {
    e[++tot] = (Edges){head[u], v};
    head[u] = tot;
}
void dfs(ll u, ll f, ll up) {
    dep[u] = dep[f] + 1;
    if(w[u] != -1 && dep[u] % 2 == 0) {
        gg = true; return;
    }
    if(w[u] != -1 && w[u] < up) {
        gg = true; return;
    }
    for(ll i = head[u]; i; i = e[i].next) {
        ll v = e[i].to;
        if(v == f) continue;
        dfs(v, u, (w[u] == -1 ? up : w[u]));
    }
}
void dfs2(ll u, ll f, ll sum) {
    if(w[u] == -1) {
        a[u] = INF;
        for(ll i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(v == f) continue;
            a[u] = std::min(a[u], w[v] - sum);
        }
        if(a[u] == INF) a[u] = 0;
    }
    else a[u] = w[u] - sum;
    for(ll i = head[u]; i; i = e[i].next) {
        ll v = e[i].to;
        if(v == f) continue;
        dfs2(v, u, sum + a[u]);
    }
}
int main() {
    cin >> n;
    for(ll i = 2; i <= n; i++) {
        ll v; cin >> v;
        link(i, v); link(v, i);
    }
    for(ll i = 1; i <= n; i++) {
        cin >> w[i];
    }
    dfs(1, 0, 0);
    if(gg) {
        cout << -1 << endl;
        return 0;
    }
    dfs2(1, 0, 0);
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        //cout << i << ": " << a[i] << endl;
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
