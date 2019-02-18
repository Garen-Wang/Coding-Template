/*************************************************************************
 @Author: Garen
 @Created Time : Tue 29 Jan 2019 09:56:30 PM CST
 @File Name: P1026.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#define ll long long
const int maxn = 205;
string str;
string word[8];
int dp[maxn][maxn];
int pd[maxn];
int p, m, s, n;
int sum[maxn][maxn];
int check(int l, int r) {
    l--; r--;
    string ch = str.substr(l, r - l + 1);
    for(int i = 1; i <= s; i++) {
        if(ch.find(word[i]) == 0) return 1;
    }
    return 0;
}
int main() {
    cin >> p >> m;
    string temp;
    while(p--) {
        cin >> temp;
        str = str + temp;
        n += temp.length();
    }
    cin >> s;
    for(int i = 1; i <= s; i++) cin >> word[i];
    for(int j = n; j >= 1; j--) {
        for(int i = j; i >= 1; i--) {
            sum[i][j] = sum[i + 1][j] + check(i, j);
        }
    }
    for(int i = 1; i <= m; i++) dp[i][i] = dp[i - 1][i - 1] + sum[i][i];
    for(int i = 1; i <= n; i++) dp[i][1] = sum[1][i];
    for(int i = 1; i <= n; i++) {
        for(int j = 2; j <= m && j < i; j++) {
            for(int k = j; k < i; k++) {
                dp[i][j] = std::max(dp[i][j], dp[k][j - 1] + sum[k + 1][i]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
