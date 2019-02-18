/*************************************************************************
 @Author: Garen
 @Created Time : Sat 02 Feb 2019 09:32:27 AM CST
 @File Name: T65466.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll MOD = 1e9 + 7;
ll n, k;
ll pow_mod(ll x, ll y, ll z) {
    ll ans = 1; x %= z;
    while(y) {
        if(y & 1) ans = ans * x % z;
        x = x * x % z;
        y >>= 1;
    }
    return ans % z;
}
ll inv(ll a, ll p) {
    return pow_mod(a, p - 2, p);
}
ll sigma(ll a) {
    return (1 + a) * a % MOD * 500000004 % MOD;
}
ll solve(ll t) {
    if(t == 1) return sigma(k);
    else return sigma(solve(t - 1));
}
int main() {
    cin >> n >> k;
    /*
    if(k == 1) {
       cout << n << endl; 
       return 0;
    }
    */
    //cout << solve(n) << endl;
    ll ans = sigma(k);
    for(int i = 2; i <= n; i++) {
        ans = sigma(ans);
    }
    cout << ans << endl;
    return 0;
}
