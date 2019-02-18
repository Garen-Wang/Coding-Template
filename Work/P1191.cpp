/*************************************************************************
 @Author: Garen
 @Created Time : Sun 03 Feb 2019 08:57:56 PM CST
 @File Name: P1191.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
#define ll long long
const ll maxn = 155;
char ch[maxn][maxn];
ll sum[maxn][maxn];
ll n;
ll cnt;
int main() {
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++) scanf("%s", ch[i] + 1);
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (ch[i][j] == 'W' ? 1 : 0);
            //printf("(%d, %d) : %d\n", i, j, sum[i][j]);
        }
    }
    
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            for(ll k = i; k <= n; k++) {
                for(ll l = j; l <= n; l++) {
                    ll temp = sum[k][l] - sum[i - 1][l] - sum[k][j - 1] + sum[i - 1][j - 1];
                    ll temp2 = (k - i + 1) * (l - j + 1);
                    if(temp == temp2) cnt++;
                }
            }
        }
    }
    printf("%lld\n", cnt);
    return 0;
}
