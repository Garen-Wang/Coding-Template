/*************************************************************************
 @Author: Garen
 @Created Time : Sun 03 Feb 2019 01:37:47 PM CST
 @File Name: P5022.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
#define pii pair<int,int>
const int maxn = 5005;
std::vector<int> G[maxn];
bool vis[maxn];
int n, m;
int dfn[maxn], low[maxn], dtot;
int col[maxn], ctot;
std::stack<int> sta;
std::vector<int> answers, results;
std::pii edges[maxn];
bool zidianxu() {
    if(answers.size() == 0) return true;
    for(int i = 0; i < n; i++) {
        if(results[i] < answers[i]) return true;
        if(results[i] > answers[i]) return false;
    }
    return false;
}
void dfs(int u, int f, int nou, int nov) {
    results.push_back(u);
    for(auto v : G[u]) if(v != f) {
        if(u == nou && v == nov) continue;
        if(v == nou && u == nov) continue;
        dfs(v, u, nou, nov);
    }
}
void tarjan(int u, int f) {
    dfn[u] = low[u] = ++dtot;
    sta.push(u); vis[u] = true;
    for(auto v : G[u]) {
        if(v == f) continue;
        if(!dfn[v]) {
            tarjan(v, u); low[u] = std::min(low[u], low[v]);
        } else if(vis[v]) low[u] = std::min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) {
        // print
        //cout << "circle is below:" << endl;
        ctot++;
        while(sta.top() != u) {// only enter here is circle
            int sb = sta.top(); sta.pop(); vis[sb] = false;
            col[sb] = ctot;
            //cout << sb.first << ' ' << sb.second << endl;
        }
        int sb = sta.top(); sta.pop(); vis[sb] = false;
        col[sb] = ctot;
        //cout << sb.first << ' ' << sb.second << endl;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v); G[v].push_back(u);
        edges[i] = std::make_pair(u, v);
    }
    for(int i = 1; i <= n; i++) std::sort(G[i].begin(), G[i].end());
    if(m == n - 1) {
        dfs(1, 0, 0, 0);// tree don't need vis
        if(zidianxu()) answers = results;
    } else if(m == n) {
        for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i, 0);
        //for(auto it : circle) cout << it.first << ' ' << it.second << endl;
        // change one edge
        for(int i = 1; i <= m; i++) {
            if(col[edges[i].first] == col[edges[i].second]) {
                results.clear();
                dfs(1, 0, edges[i].first, edges[i].second);
                // print
                //for(auto it : results) cout << it << ' ';
                //cout << endl;
                if(zidianxu()) answers = results;
            }
        }
    } else {
        assert(true);
    }
    bool first = true;
    for(auto it : answers) {
        if(first) first = false;
        else printf(" ");
        printf("%d", it);
    }
    printf("\n");
    return 0;
}
