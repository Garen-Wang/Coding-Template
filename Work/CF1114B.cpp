/*************************************************************************
 @Author: Garen
 @Created Time : Mon 11 Feb 2019 07:49:40 PM CST
 @File Name: CF1114B.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll maxn = 200005;
std::pair<int,int> a[maxn];
ll idx[maxn];
ll n, m, k;
ll ans;
std::vector<int> answers;
int main() {
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i].first; a[i].second = i;
    }
    std::sort(a + 1, a + n + 1, std::greater<std::pair<int,int>>());

    for(ll i = 1; i <= m * k; i++) {
        ans += a[i].first;
        idx[i] = a[i].second;
    }
    std::sort(idx + 1, idx + m * k + 1);
    for(ll i = 1; i < k; i++) {
        answers.push_back(idx[i * m]);
    }
    cout << ans << endl;
    for(auto it: answers) cout << it << ' ';
    cout << endl;
    return 0;
}
