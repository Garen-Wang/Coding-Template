/*************************************************************************
 @Author: Garen
 @Created Time : Wed 13 Feb 2019 04:57:44 PM CST
 @File Name: U61329.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 100005;
const ll MOD = 104857601;
int frac[maxn];
int n;
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
ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}
ll cal(ll i, ll j) {
    ll g = gcd(i, j);
    ll lcm = i / g * j;
    return lcm * inv(g) % MOD;
}
ll solve(ll n) {
    ll ans = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans = ans * cal(i, j) % MOD;
        }
    }
    return ans;
}
int main() {
    //freopen("out.txt", "w", stdout);
    frac[0] = 1;
    for(int i = 1; i <= 100000; i++) frac[i] = frac[i - 1] * i % MOD;
    // fenzi = a(n) = (n!)^(2*n).
    for(int n = 1; n <= 5; n++) {
        ll ans = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                ans = ans * gcd(i, j) * gcd(i, j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
