#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 1000005;
int val[maxn], dist[maxn], fa[maxn], ch[maxn][2];
int n, m;

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int merge(int x, int y) {
    if(x == 0 || y == 0) return x + y;
    if(val[x] > val[y]) std::swap(x, y);
    ch[x][1] = merge(ch[x][1], y);
    fa[ch[x][1]] = x;
    if(dist[ch[x][0]] < dist[ch[x][1]]) std::swap(ch[x][0], ch[x][1]);
    dist[x] = dist[ch[x][1]] + 1;
    fa[x] = fa[ch[x][0]] = fa[ch[x][1]] = x;
    return x;
}
int main() {
    dist[0] = -1;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> val[i], fa[i] = i;
    cin >> m;
    while(m--) {
        char opt[2]; int x, y;
        cin >> opt >> x;
        if(opt[0] == 'M') {
            cin >> y;
            if(val[x] == -1 || val[y] == -1) continue;
            x = find(x), y = find(y);
            if(x == y) continue;
            fa[x] = fa[y] = merge(x, y);
        } else if(opt[0] == 'K') {
            if(val[x] == -1) {
                cout << 0 << endl;
                continue;
            }
            x = find(x);
            cout << val[x] << endl;
            val[x] = -1;
            fa[ch[x][0]] = ch[x][0];
            fa[ch[x][1]] = ch[x][1];
            fa[x] = merge(ch[x][0], ch[x][1]);
        }
    }
    return 0;
}