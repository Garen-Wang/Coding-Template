/*************************************************************************
 @Author: Garen
 @Created Time : Tue 12 Feb 2019 10:19:25 AM CST
 @File Name: P2627.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
#define ll long long
const ll maxn = 100005;
ll dp[maxn];
ll a[maxn], sum[maxn];
ll n, k;
std::deque<ll> q;
ll d[maxn];
ll update(ll i) {
    d[i] = dp[i - 1] - sum[i];
    while(!q.empty() && d[q.back()] < d[i]) q.pop_back();
    q.push_back(i);
    while(!q.empty() && q.front() < i - k) q.pop_front();
    return d[q.front()];
}
int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    /*
    for(ll i = 1; i <= k; i++) dp[i] = sum[i];
    for(ll i = k + 1; i <= n; i++) {
        for(ll j = i - k; j <= i; j++) {
            dp[i] = std::max(dp[i], dp[j - 1] + sum[i] - sum[j]);
        }
        // dp[i] = sum[i] + std::max(dp[j - 1] - sum[j]));
    }
    */
    q.push_back(0);
    for(ll i = 1; i <= n; i++) {
        dp[i] = sum[i] + update(i);
    }
    printf("%lld\n", dp[n]);
    return 0;
}
