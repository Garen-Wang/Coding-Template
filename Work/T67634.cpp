/*************************************************************************
 @Author: Garen
 @Created Time : Sat 02 Feb 2019 10:13:30 AM CST
 @File Name: T67634.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
const int maxn = 10005;
struct Edges {
    int next, to, weight, tim;
} e[maxn << 1];
int head[maxn], tot;
struct Heapnodes {
    int d, u;
    Heapnodes(int d, int u): d(d), u(u){}
    bool operator < (const Heapnodes &rhs) const {
        return d > rhs.d;
    }
};
bool done[maxn];
int dist[maxn];
int wei[maxn];
int n, m, t, Q, S, T;
void link(int u, int v, int w, int p) {
    e[++tot] = (Edges){head[u], v, w, p};
    head[u] = tot;
}
void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    memset(wei, 0x3f, sizeof wei);
    std::priority_queue<Heapnodes> heap;
    dist[S] = 0; wei[S] = 0; heap.push(Heapnodes(dist[S], S));
    while(!heap.empty()) {
        Heapnodes sb = heap.top(); heap.pop();
        int d = sb.d, u = sb.u;
        if(done[u]) continue;
        done[u] = true;
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(dist[u] + e[i].tim < dist[v]) {
                dist[v] = dist[u] + e[i].tim;
                wei[v] = wei[u] + e[i].weight;
                heap.push(Heapnodes(dist[v], v));
            }
        }
    }
}
void solve1() {
    dijkstra();
    if(dist[T] > t) {
        printf("-1\n");
    } else {
        printf("%d\n", wei[T]);
    }
}
int main() {
    scanf("%d %d %d %d %d %d", &n, &m, &t, &Q, &S, &T);
    while(m--) {
        int u, v, p, w; scanf("%d %d %d %d", &u, &v, &p, &w);
        link(u, v, w, p); link(v, u, w, p);
    }
    if(Q == 0) solve1();
    else {
        
    }
    return 0;
}
