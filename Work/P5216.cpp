/*************************************************************************
 @Author: Garen
 @Created Time : Sat 09 Feb 2019 09:02:14 PM CST
 @File Name: P5216.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll maxn = 100005;
const ll MOD = 998244353;
ll a[maxn];
ll b[maxn];
ll frac[maxn];
ll n, ans;
ll pow_mod(ll x, ll y) {
    ll ans = 1; x %= MOD;
    while(y) {
        if(y & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ans % MOD;
}
ll inv(ll a) {
    return pow_mod(a, MOD - 2);
}
ll C(ll n, ll m) {
    return frac[n] * inv(frac[m]) % MOD * inv(frac[n - m]) % MOD;
}
int main() {
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    frac[0] = 1;
    for(ll i = 1; i <= n; i++) frac[i] = frac[i - 1] * i % MOD;
    for(ll i = 1; i <= n; i++) {
        ll bound = sqrt(a[i]);
        ll cnt = 0;
        for(ll j = 1; j <= bound; j++) {
            if(a[i] % j == 0) {
                cnt += b[j];
                if(a[i] / j != j) {
                    cnt += b[a[i] / j];
                }
            }
        }
        cnt--;
        //ll temp = a[i] * frac[cnt] % MOD * frac[n - cnt - 1] % MOD * C(n, cnt + 1) % MOD;
        ll temp = a[i] * frac[n] % MOD * inv(cnt + 1) % MOD;
        ans = (ans + temp) % MOD;
    }
    cout << ans << endl;
    return 0;
}
