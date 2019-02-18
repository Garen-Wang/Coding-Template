/*************************************************************************
 @Author: Garen
 @Created Time : Wed 30 Jan 2019 01:35:50 PM CST
 @File Name: P5097.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int maxn = 25005;
int ch[maxn][2], val[maxn], minv[maxn], fa[maxn], size[maxn];

int a[maxn];
int n, m;
struct Splay {
    int root;
    int dir(int x) {
        return ch[fa[x]][1] == x;
    }
    void connect(int son, int f, int k) {
        fa[son] = f; ch[f][k] = son;
    }
    void pushup(int x) {
        minv[x] = val[x];
        if(ch[x][0]) minv[x] = std::min(minv[x], minv[ch[x][0]]);
        if(ch[x][1]) minv[x] = std::min(minv[x], minv[ch[x][1]]);
        size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
    }
    void rotate(int x) {
        int y = fa[x];
        int z = fa[y];
        int yk = dir(x);
        int zk = dir(y);
        int b = ch[x][yk ^ 1];
        connect(b, y, yk);
        connect(y, x, yk ^ 1);
        connect(x, z, zk);
        pushup(y);
        pushup(x);
    }
    void splay(int x, int goal) {
        while(fa[x] != goal) {
            int y = fa[x];
            int z = fa[y];
            if(z != goal) dir(x) == dir(y) ? rotate(y) : rotate(x);
            rotate(x);
        }
        if(goal == 0) root = x;
    }
    int build(int l, int r, int f) {
        if(l > r) return 0;
        else if(l == r) {
            minv[l] = val[l] = a[l];
            size[l] = 1;
            fa[l] = f;
            ch[l][0] = ch[l][1] = 0;
            return l;
        } else {
            int mid = (l + r) >> 1;
            fa[mid] = f;
            val[mid] = a[mid];
            ch[mid][0] = build(l, mid - 1, mid);
            ch[mid][1] = build(mid + 1, r, mid);
            pushup(mid);
            return mid;
        }
    }
    int kth(int k) {
        int now = root;
        while(233) {
            if(k > size[ch[now][0]] + 1) {
                k -= size[ch[now][0]] + 1; now = ch[now][1];
            } else if(k <= size[ch[now][0]]) now = ch[now][0];
            else return now;
        }
    }
    int split(int l, int r) {
        int pre = kth(l), suf = kth(r);
        splay(pre, 0); splay(suf, pre);
        return ch[suf][0];
    }
} sp;

int main() {
    cin >> n >> m;
    a[1] = a[n + 2] = 0;
    for(int i = 1 + 1; i <= n + 1; i++) cin >> a[i];
    sp.root = sp.build(1, n + 2, 0);
    while(m--) {
        int l, r; cin >> l >> r;
        int temp = sp.split(l, r + 2);
        cout << minv[temp] << endl;
    }
    return 0;
}
