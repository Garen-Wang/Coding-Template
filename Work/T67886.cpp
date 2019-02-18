/*************************************************************************
 @Author: Garen
 @Created Time : Tue 05 Feb 2019 09:29:39 AM CST
 @File Name: T67886.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll MOD = 998244353;
const int maxn = 100005;
ll a[maxn];
bool vis[maxn];
ll frac[maxn];
ll ans;
ll n, m;
ll cnt[maxn];
ll pow_mod(ll x, ll y, ll z) {
    ll ans = 1; x %= z;
    while(y) {
        if(y & 1) ans = ans * x % z;
        x = x * x % z;
        y >>= 1;
    }
    return ans % z;
}
ll inv(ll a) {
    return pow_mod(a, MOD - 2, MOD);
}
ll C(ll n, ll m) {
    return frac[n] * inv(frac[m]) % MOD * inv(frac[n - m]) % MOD;
}
int main() {
    cin >> n;
    frac[0] = 1;
    for(int i = 1; i <= 100000; i++) frac[i] = frac[i - 1] * i % MOD;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        vis[a[i]] = true;
    }
    for(int i = 1; i <= n; i++) {
        int bound = sqrt(a[i]);
        for(int j = 1; j <= bound; j++) {
            if(a[i] % j == 0) {
                if(vis[j]) cnt[i]++;
            }
        }
        cnt[i]--;
        ans = (ans + a[i] * frac[cnt[i]] % MOD * frac[n - cnt[i] - 1] % MOD * C(n, n - cnt[i] - 1) % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}
