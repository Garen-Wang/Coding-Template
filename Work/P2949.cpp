/*************************************************************************
 @Author: Garen
 @Created Time : Thu 07 Feb 2019 08:02:31 PM CST
 @File Name: P2949.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll maxn = 100005;
struct Nodes {
    ll d, p;
    bool operator < (const Nodes &rhs) const {
        return p > rhs.p;
    }
} s[maxn];
std::priority_queue<Nodes> heap;
ll n;
int main() {
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> s[i].d >> s[i].p;
    }
    std::sort(s + 1, s + n + 1, [](Nodes A, Nodes B) {
        return A.d < B.d;
    });
    ll ans = 0, now = 0;
    for(ll i = 1; i <= n; i++) {
        if(now + 1 <= s[i].d) {
            now++;
            ans += s[i].p;
            heap.push(s[i]);
        } else {
            if(s[i].p > heap.top().p) {
                ans -= heap.top().p; heap.pop();
                ans += s[i].p; heap.push(s[i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
