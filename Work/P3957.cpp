#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 500005;
const int INF = 0x8f8f8f8f;
int a[maxn], dis[maxn];
int dp[maxn];
int n, d, k;
std::deque<int> q;// dan diao di jian
bool check(int g) {
    int lim1 = std::max(1, d - g), lim2 = d + g;
    memset(dp, 0x8f, sizeof dp);
    dp[0] = 0;
    q.clear();
    int j = 0;
    for(int i = 1; i <= n; i++) {
        /*for(int j = 0; j < i; j++) {
            if(dis[i] - dis[j] >= lim1 && dis[i] - dis[j] <= lim2) {
                dp[i] = std::max(dp[i], dp[j] + a[i]);
            }
        }*/
        while(j < i && dis[i] - dis[j] >= lim1) {
            if(dp[j] != INF) {
                while(!q.empty() && dp[q.back()] < dp[j]) q.pop_back();
                q.push_back(j);
            }
            j++;
        }
        while(!q.empty() && dis[i] - dis[q.front()] > lim2) q.pop_front();
        if(!q.empty()) dp[i] = dp[q.front()] + a[i];
    }
    int ans = 0x8f8f8f8f;
    for(int i = 1; i <= n; i++) ans = std::max(ans, dp[i]);// wrong here
    return ans >= k;
}
int main() {
    cin >> n >> d >> k;
    dis[0] = a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> dis[i] >> a[i];
    }
    int left = 0, right = std::max(dis[n], d), ans = -1;
    while(left <= right) {
        int mid = (left + right) >> 1;
        if(check(mid)) ans = mid, right = mid - 1;
        else left = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
