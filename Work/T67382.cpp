/*************************************************************************
 @Author: Garen
 @Created Time : Sat 02 Feb 2019 10:28:33 AM CST
 @File Name: T67382.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll maxn = 16;
const ll MOD = 998244353;
ll value[maxn], weight[maxn];
ll dp[1005];
ll n, V;
ll per[maxn];
ll cnt;
ll pow_mod(ll x, ll y, ll z) {
    ll ans = 1; x %= z;
    while(y) {
        if(y & 1) ans = ans * x % z;
        x = x * x % z;
        y >>= 1;
    }
    return ans % z;
}
ll backpack(ll status) {
    memset(dp, 0, sizeof dp);
    for(ll i = 1; i <= n; i++) {
        if((1 << (i - 1)) & status) {
            for(ll j = V; j >= value[i]; j--) {
                dp[j] = std::max(dp[j], dp[j - value[i]] + weight[i]);
            }
        }
    }
    return dp[V];
}
void solve(ll status, ll ans1) {
    for(ll i = 1; i <= n; i++) per[i] = i;
    do {
        ll now = 0, ans = 0;
        for(ll i = 1; i <= n; i++) {
            if(((1 << (per[i] - 1)) & status) && now + value[per[i]] <= V) {
                now += value[per[i]]; ans += weight[per[i]];
            }
        }
        if(ans1 == ans) cnt = (cnt + 1) % MOD;
        // print
        //for(ll i = 1; i <= n; i++) cout << per[i] << ' ';
        //cout << "ans = " << ans << endl;
    } while(std::next_permutation(per + 1, per + n + 1));
}
ll frac(ll x) {
    if(x == 0) return 1ll;
    return frac(x - 1) * x % MOD;
}
int main() {
    cin >> n >> V;
    for(ll i = 1; i <= n; i++) cin >> value[i] >> weight[i];
    for(ll S = (1 << n) - 1; S >= 0; S--) {
        ll ans1 = backpack(S);
        //cout << "(" << S << ")" << " god: " << ans1 << endl;
        solve(S, ans1);
    }
    ll ans = cnt * pow_mod(frac(n), MOD - 2, MOD) % MOD;
    cout << ans << endl;
    return 0;
}
