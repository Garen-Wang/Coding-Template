/*************************************************************************
 @Author: Garen
 @Created Time : Fri 01 Feb 2019 10:07:00 PM CST
 @File Name: CF1106B.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll maxn = 100005;
struct Nodes {
    ll cost, idx;
} s[maxn];
ll a[maxn], c[maxn];
ll n, m;
ll pos;
bool cmp(Nodes A, Nodes B) {
    if(A.cost == B.cost) return A.idx < B.idx;
    return A.cost < B.cost;
}
int main() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= n; i++) {
        cin >> c[i];
        s[i].cost = c[i]; s[i].idx = i;
    }
    std::sort(s + 1, s + n + 1, cmp);
    while(m--) {
        ll t, d; cin >> t >> d;
        ll cost = 0;
        if(a[t] >= d) { // enough to serve
            cost = c[t] * d;
            a[t] -= d;
        } else { // not enough
            cost = c[t] * a[t];
            ll remain = d - a[t];
            a[t] = 0;
            for(ll i = pos; i <= n; i++) {
                if(remain == 0) break;
                ll idx = s[i].idx;
                if(i == pos && a[idx] == 0) {
                    pos++;
                    continue;
                }
                ll temp = std::min(a[idx], remain);
                cost += c[idx] * temp;
                a[idx] -= temp;
                remain -= temp;
            }
            if(remain) cost = 0;// leave angrily
        }
        cout << cost << endl;
    }
    return 0;
}
