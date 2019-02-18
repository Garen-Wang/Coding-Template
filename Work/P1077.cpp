#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 1005;
const int MOD = 1000007;
int dp[maxn][maxn];
int a[maxn];
int n, m;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 1;
    // dp[i][j] = sum{dp[i - 1][j - a[i] -> j}
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = j - a[i]; k <= j; k++) {
                if(k >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
