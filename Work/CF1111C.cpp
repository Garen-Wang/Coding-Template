/*************************************************************************
 @Author: Garen
 @Created Time : Mon 04 Feb 2019 09:29:28 PM CST
 @File Name: CF1111C.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxk = 100005;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
ll a[maxk];
ll n, k, A, B;

ll solve(ll l, ll r) {
    ll len = r - l + 1;
    ll pos1 = std::lower_bound(a + 1, a + k + 1, l) - a - 1;
    ll pos2 = std::upper_bound(a + 1, a + k + 1, r) - a - 1 - 1;
    ll cnt = pos2 - pos1 + 1;
    ll ans = INF;
    if(len >= 2 && cnt) {
        ll mid = (l + r) >> 1;
        ans = std::min(ans, solve(l, mid) + solve(mid + 1, r));
    }
    if(cnt == 0) ans = std::min(ans, A);
    else ans = std::min(ans, B * cnt * len);
    return ans;
}
int main() {
    cin >> n >> k >> A >> B;
    for(int i = 1; i <= k; i++) cin >> a[i];
    std::sort(a + 1, a + k + 1);
    ll temp = solve(1, 1ll << n);
    cout << temp << endl;
    return 0;
}
