/*************************************************************************
 @Author: Garen
 @Created Time : Sat 02 Feb 2019 09:26:53 PM CST
 @File Name: CF1096D.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll MOD = 998244353;
const int maxn = 100005;
const char* str = " hard";
char ch[maxn];
ll a[maxn];
int n;
ll dp[maxn][5];

int main() {
    cin >> n >> (ch + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= 4; i++) dp[0][i] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 4; j++) {
            if(ch[i] == str[j]) {
                dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j] + a[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(int i = 1; i <= 4; i++) ans = std::min(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
