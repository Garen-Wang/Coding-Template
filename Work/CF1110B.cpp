/*************************************************************************
 @Author: Garen
 @Created Time : Sat 09 Feb 2019 03:27:53 PM CST
 @File Name: CF1110B.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll maxn = 100005;
ll n, m, k;
ll a[maxn], b[maxn];
ll ans;
int main() {
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; i++) cin >> b[i];
    for(ll i = 1; i < n; i++) a[i] = b[i + 1] - b[i];
    std::sort(a + 1, a + n);
    for(ll i = 1; i <= n - k; i++) {
        ans += a[i];
    }
    ans += k;
    cout << ans << endl;
    return 0;
}
