#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long

int solve(ll l, ll r) {
    ll ans = 0;
    for(ll i = l; i <= r; i++) {
        ll temp = i;
        while(temp) {
            temp /= 10; ans = ans * 10 % 9;
        }
        ans = (ans + i % 9) % 9;
    }
    return ans;
}
int main() {
    ll T; cin >> T;
    while(T--) {
        ll l, r; cin >> l >> r;
        ll diff = (r - l) % 9;
        r = l + diff;
        cout << solve(l, r) << endl;
    }
    return 0;
}
