/*************************************************************************
 @Author: Garen
 @Created Time : Mon 04 Feb 2019 12:30:20 PM CST
 @File Name: P3378.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int maxn = 1000005;
int dist[maxn], fa[maxn], ch[maxn][2], val[maxn];
int n, m;
int mian;
int find(int x) {
    while(fa[x]) x = fa[x];
    return x;
}
int merge(int x, int y) {
    if(x == 0 || y == 0) return x + y;
    if(val[x] > val[y]) std::swap(x, y);
    else if(val[x] == val[y] && x > y) std::swap(x, y);
    ch[x][1] = merge(ch[x][1], y);
    fa[ch[x][1]] = x;
    if(dist[ch[x][0]] < dist[ch[x][1]]) std::swap(ch[x][0], ch[x][1]);
    dist[x] = dist[ch[x][1]] + 1;
    return x;
}
int main() {
    dist[0] = -1;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int opt, x;
        cin >> opt;
        if(opt == 1) {
            cin >> x;
            val[++n] = x;
            mian = merge(mian, n);
        } else if(opt == 2) {
            cout << val[mian] << endl;
        } else if(opt == 3) {
            val[mian] = -1;
            fa[ch[mian][0]] = fa[ch[mian][1]] = 0;
            mian = merge(ch[mian][0], ch[mian][1]);
        }
    }
    return 0;
}
