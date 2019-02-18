#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using std::cin;
using std::cout;
using std::endl;
const int maxn = 100005;
int a[maxn];
int fa[maxn];
bool del[maxn];
int n, m;
struct Nodes {
    int val, idx;
    Nodes(int val, int idx): val(val), idx(idx){}
    bool operator < (const Nodes &rhs) const {
        if(val == rhs.val) return idx > rhs.idx;
        return val > rhs.val;
    }
};
__gnu_pbds::priority_queue<Nodes> heap[maxn];
int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        heap[i].push(Nodes(a[i], i));
        fa[i] = i;
    }
    while(m--) {
        int opt, x, y; cin >> opt;
        if(opt == 1) {
            cin >> x >> y;
            if(del[x] || del[y]) continue;
            x = find(x), y = find(y);
            if(x == y) continue;
            heap[x].join(heap[y]);
            fa[y] = x;
        } else if(opt == 2) {
            cin >> x;
            if(del[x] || heap[find(x)].empty()) {
                cout << -1 << endl;
            } else {
                x = find(x);
                Nodes sb = heap[x].top(); heap[x].pop();
                del[sb.idx] = true;
                cout << sb.val << endl;
            }
        }
    }
    return 0;
}