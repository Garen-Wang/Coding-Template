/*************************************************************************
 @Author: Garen
 @Created Time : Sun 10 Feb 2019 11:35:54 PM CST
 @File Name: P2343.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
const int maxn = 200005;

int read() {
    int ans = 0, s = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0') {
        if(ch == '-') s = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return s * ans;
}
int m, q;
int ch[maxn][2], val[maxn], fa[maxn], size[maxn], cnt[maxn];
int tot;
int all;
struct Splay {
    int root;
    int dir(int x) {
        return ch[fa[x]][1] == x;
    }
    void connect(int son, int f, int k) {
        fa[son] = f;
        ch[f][k] = son;
    }
    void pushup(int x) {
        size[x] = size[ch[x][0]] + size[ch[x][1]] + cnt[x];
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
    void insert(int x) {
        int now = root, f = 0;
        while(now && val[now] != x) {
            f = now;
            now = ch[now][x > val[now]];
        }
        if(now) cnt[now]++;
        else {
            now = ++tot;
            ch[now][0] = ch[now][1] = 0;
            size[now] = cnt[now] = 1;
            val[now] = x; fa[now] = f;
            if(f) ch[f][x > val[f]] = now;
        }
        splay(now, 0);
    }
    int kth(int k) {
        int now = root;
        while(233) {
            if(size[ch[now][0]] >= k) {
                now = ch[now][0];
            } else if(size[ch[now][0]] + cnt[now] < k) {
                k -= size[ch[now][0]] + cnt[now];
                now = ch[now][1];
            } else return now;
        }
    }
} sp;
void print(int u) {
    if(ch[u][0]) print(ch[u][0]);
    printf("%d ", val[u]);
    if(ch[u][1]) print(ch[u][1]);
}
int main() {
    m = read(), q = read();
    all = m;
    while(m--) {
        int val = read();
        sp.insert(val);
    }
    //print(sp.root);
    while(q--) {
        int c = read(), n = read();
        if(c == 1) printf("%d\n", val[sp.kth(all - n + 1)]);
        else if(c == 2) {
            sp.insert(n); all++;
        }
    }
    return 0;
}
