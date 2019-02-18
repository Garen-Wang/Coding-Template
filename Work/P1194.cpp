/*************************************************************************
 @Author: Garen
 @Created Time : Tue 12 Feb 2019 04:37:42 PM CST
 @File Name: P1194.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll maxn = 505;
struct Nodes {
    ll u, v, w;
};
std::vector<Nodes> a;
ll fa[maxn];
ll n, m;
ll find(ll x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
ll kruskal() {
    std::sort(a.begin(), a.end(), [](Nodes A, Nodes B) { return A.w < B.w; });
    for(ll i = 0; i <= m; i++) fa[i] = i;
    ll ans = 0;
    for(ll i = 0; i < a.size(); i++) {
        ll u = find(a[i].u), v = find(a[i].v);
        if(u != v) {
            ans += a[i].w;
            fa[v] = u;
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;
    ll temp;
    for(ll i = 1; i <= m; i++) {
        for(ll j = 1; j <= m; j++) {
            cin >> temp;
            if(temp && i < j) {
                a.push_back((Nodes){i, j, temp});
            }
        }
    }
    for(ll i = 1; i <= m; i++) a.push_back((Nodes){0, i, n});
    cout << kruskal() << endl;
    return 0;
}
