#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll maxn = 100005;
__gnu_pbds::priority_queue<ll> heap[maxn];
ll c[maxn], l[maxn];
ll sum[maxn], fa[maxn];
ll n, m;
ll ans;
int main() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) {
        cin >> fa[i] >> c[i] >> l[i];
    }
    for(ll i = n; i >= 1; i--) {
        heap[i].push(c[i]); sum[i] += c[i];
        while(sum[i] > m) {
            ll x = heap[i].top(); heap[i].pop();
            sum[i] -= x;
        }
        ans = std::max(ans, (ll)(heap[i].size()) * l[i]);
        heap[fa[i]].join(heap[i]);
        sum[fa[i]] += sum[i];
    }
    cout << ans << endl;
    return 0;
}
