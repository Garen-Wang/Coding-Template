/*************************************************************************
 @Author: Garen
 @Created Time : Tue 29 Jan 2019 09:28:06 PM CST
 @File Name: P1868.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 150005;
const int maxm = 3000005;
struct Nodes {
    int x, y;
} s[maxn];
int dp[maxm];
int n, maxv, ans;

bool cmp(Nodes a, Nodes b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i].x >> s[i].y;
        maxv = std::max(maxv, s[i].y);
    }
    std::sort(s + 1, s + n + 1, cmp);
    int j = 1;
    for(int i = 0; i <= maxv; i++) {
        if(i) dp[i] = std::max(dp[i], dp[i - 1]);
        while(i == s[j].x && j <= n) {
            dp[s[j].y] = std::max(dp[s[j].y], dp[s[j].x - 1] + s[j].y - s[j].x + 1);
            j++;
        }
        ans = std::max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
