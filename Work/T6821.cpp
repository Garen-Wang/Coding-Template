/*************************************************************************
 @Author: Garen
 @Created Time : Fri 01 Feb 2019 08:15:21 PM CST
 @File Name: T6821.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
#define ll long long
const int maxn = 505;
int G[maxn][maxn];
int n, m, q;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%1d", &G[i][j]);
    scanf("%d", &q);
    for(int t = 1; t <= q; t++) {
        int x, y; scanf("%d %d", &x, &y);
        if(G[x][y]) {
            printf("%d\n", t);
            return 0;
        }
    }
    printf("Good Game.\n");
    return 0;
}
