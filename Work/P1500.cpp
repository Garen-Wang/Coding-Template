/*************************************************************************
 @Author: Garen
 @Created Time : Mon 28 Jan 2019 05:43:04 PM CST
 @File Name: P1500.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
const int maxn = 75;
const int INF = 0x3f3f3f3f;
// 邻接表
struct Edges {
    int next, to, weight, cost;
} e[1000005];
int head[maxn], tot = 1;
// 建图
int G[maxn][maxn];
std::pair<double,double> a[maxn];
std::map<string,int> mmp;
// 网络流
int last[maxn], pre[maxn];
int flow[maxn];
bool vis[maxn];
int dist[maxn];
int s, t;
int maxflow, maxcost;
int n;
double k;
void link(int u, int v, int w, int c) {
    e[++tot] = (Edges){head[u], v, w, c};
    head[u] = tot;
}
void add_edge(int u, int v, int c) {
    link(u, v, 1, c); link(v, u, 0, -c);
}
string lower(string str) {
    int len = str.length();
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
    }
    return str;
}
double dis(int u, int v) {
    return sqrt((a[u].first - a[v].first) * (a[u].first - a[v].first) + (a[u].second - a[v].second) * (a[u].second - a[v].second));
}
bool check(int u, int v) {
    if(dis(u, v) - k > 1e-5) return false;
    for(int i = 1; i <= 2 * n; i++) {
        if(i == u || i == v) continue;
        /*
        if(a[u].first < a[i].first && a[i].first < a[v].first)
            if(a[u].second < a[i].second && a[i].second < a[v].second) {
                double temp1 = (a[v].second - a[u].second) * (a[i].first - a[u].first);
                double temp2 = (a[v].first - a[u].first) * (a[i].second - a[u].second);
                if(fabs(temp1 - temp2) < 1e-5) return false;
            }
        */
        if(fabs(dis(u, i) + dis(i, v) - dis(u, v)) < 1e-5) return false;
    }
    return true;
}
bool spfa() {
    for(int i = 1; i <= t; i++) {
        flow[i] = last[i] = pre[i] = vis[i] = 0;
        dist[i] = -INF;
    }
    std::queue<int> q;
    dist[s] = 0; flow[s] = INF;
    q.push(s); vis[s] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop(); vis[u] = false;
        for(int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            if(e[i].weight > 0 && dist[u] + e[i].cost > dist[v]) {
                dist[v] = dist[u] + e[i].cost;
                last[v] = i;
                pre[v] = u;
                flow[v] = std::min(flow[u], e[i].weight);
                if(!vis[v]) {
                    q.push(v); vis[v] = true;
                }
            }
        }
    }
    return dist[t] != -INF;
}
void update() {
    maxflow += flow[t];
    maxcost += dist[t];
    for(int i = t; i != s; i = pre[i]) {
        e[last[i]].weight -= flow[t];
        e[last[i] ^ 1].weight += flow[t];
    }
}
void EK() {
    while(spfa()) update();
}
int main() {
    cin >> k;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = n + 1; j <= n + n; j++)
            G[i][j] = 1;
    for(int i = 1; i <= 2 * n; i++) {
        string name;
        cin >> a[i].first >> a[i].second >> name;
        name = lower(name);
        mmp[name] = i;
    }
    string one, two; int temp;
    while(233) {
        cin >> one;
        if(one == "End") break;
        cin >> two >> temp;
        one = lower(one); two = lower(two);
        G[mmp[one]][mmp[two]] = G[mmp[two]][mmp[one]] = temp;
    }
    for(int i = 1; i <= n; i++)// fixed
        for(int j = n + 1; j <= 2 * n; j++)// fixed
            if(check(i, j)) {
                add_edge(i, j, G[i][j]);
                //cout << "shit" << endl;
            }
    s = 2 * n + 1; t = s + 1;
    for(int i = 1; i <= n; i++) add_edge(s, i, 0), add_edge(n + i, t, 0);// fixed
    EK();
    cout << maxcost << endl;
    return 0;
}
