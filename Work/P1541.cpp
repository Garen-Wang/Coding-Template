/*************************************************************************
 @Author: Garen
 @Created Time : Mon 11 Feb 2019 04:27:42 PM CST
 @File Name: P1541.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int maxn = 351, maxm = 121;
const int INF = 0x3f3f3f3f;
int dp[maxm][maxm][maxm][maxm];
int card[5];
int a[maxn];
int ans = -INF;
int n, m;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    while(m--) {
        int temp; cin >> temp;
        card[temp]++;
    }
    dp[0][0][0][0] = a[1];
    for(int i = 0; i <= card[1]; i++) {
        for(int j = 0; j <= card[2]; j++) {
            for(int k = 0; k <= card[3]; k++) {
                for(int l = 0; l <= card[4]; l++) {
                    int now = 1 * i + 2 * j + 3 * k + 4 * l + 1;
                    if(now - 1 >= 1 && i - 1 >= 0) {
                        dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i - 1][j][k][l] + a[now]);
                    }
                    if(now - 2 >= 1 && j - 1 >= 0) {
                        dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j - 1][k][l] + a[now]);
                    }
                    if(now - 3 >= 1 && k - 1 >= 0) {
                        dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j][k - 1][l] + a[now]);
                    }
                    if(now - 4 >= 1 && l - 1 >= 0) {
                        dp[i][j][k][l] = std::max(dp[i][j][k][l], dp[i][j][k][l - 1] + a[now]);
                    }
                }
            }
        }
    }
    cout << dp[card[1]][card[2]][card[3]][card[4]] << endl;
    return 0;
}
