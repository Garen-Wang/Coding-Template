/*************************************************************************
 @Author: Garen
 @Created Time : Fri 01 Feb 2019 10:39:01 PM CST
 @File Name: CF1106D.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 100005;
std::vector<int> G[maxn];
std::priority_queue<int, std::vector<int>, std::greater<int> > heap;
bool vis[maxn];
int n, m;
bool first = true;
void dfs(int u) {
    if(first) {
        cout << u; first = false;
    } else cout << ' ' << u;
    for(auto v : G[u]) {
        if(!vis[v]) {
            heap.push(v);
            vis[v] = true;
        }
    }
    if(heap.empty()) return;
    int uu = heap.top(); heap.pop();
    dfs(uu);
}
int main() {
    cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    vis[1] = true;
    dfs(1);
    cout << endl;
    return 0;
}
