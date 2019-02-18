/*************************************************************************
 @Author: Garen
 @Created Time : Mon 04 Feb 2019 02:16:41 PM CST
 @File Name: P1456.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
#define ll long long
const int maxn = 100005;
int val[maxn], dist[maxn], fa[maxn], ch[maxn][2];
int n, m;

void clearlove() {
    memset(dist, 0, sizeof dist);
    memset(fa, 0, sizeof fa);
    memset(ch, 0, sizeof ch);
}
int find(int x) {
    while(fa[x]) x = fa[x];
    return x;
}
int merge(int x, int y) {
    if(x == 0 || y == 0) return x + y;
    if(val[x] < val[y]) std::swap(x, y);
    else if(val[x] == val[y] && x < y) std::swap(x, y);
    ch[x][1] = merge(ch[x][1], y);
    fa[ch[x][1]] = x;
    if(dist[ch[x][0]] < dist[ch[x][1]]) std::swap(ch[x][0], ch[x][1]);
    dist[x] = dist[ch[x][1]] + 1;
    return x;
}
int fight(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return -1;
    int temp1 = val[x], temp2 = val[y];
    val[x] >>= 1;
    fa[ch[x][0]] = fa[ch[x][1]] = 0;
    int temp_1 = merge(ch[x][0], ch[x][1]);
    ch[x][0] = ch[x][1] = 0;
    int newtemp_1 = merge(temp_1, x);
    
    val[y] >>= 1;
    fa[ch[y][0]] = fa[ch[y][1]] = 0;
    int temp_2 = merge(ch[y][0], ch[y][1]);
    ch[y][0] = ch[y][1] = 0;
    int newtemp_2 = merge(temp_2, y);
    int sb = merge(newtemp_1, newtemp_2);
    return val[sb];
}
int main() {
    while(scanf("%d", &n) == 1) {
        clearlove();
        dist[0] = -1;
        for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
        scanf("%d", &m);
        while(m--) {
            int x, y; scanf("%d%d", &x, &y);
            printf("%d\n", fight(x, y));
        }
    }
    return 0;
}
