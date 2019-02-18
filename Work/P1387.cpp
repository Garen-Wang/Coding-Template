/*************************************************************************
 @Author: Garen
 @Created Time : Sat 09 Feb 2019 11:10:20 AM CST
 @File Name: P1387.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 105;
int a[maxn][maxn];
int dp[maxn][maxn];
int n, m;
int ans;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
            cin >> a[i][j];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == 1) {
                dp[i][j] = std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
            ans = std::max(ans, dp[i][j]);
            printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
