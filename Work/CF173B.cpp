/*************************************************************************
 @Author: Garen
 @Created Time : Mon 04 Feb 2019 10:04:03 PM CST
 @File Name: CF173B.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 1005;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
struct Nodes {
    int x, y, dir, d;
    Nodes(int x, int y, int dir, int d): x(x), y(y), dir(dir), d(d){}
};
bool G[maxn][maxn];
int dist[maxn][maxn][4];
bool vis[maxn][maxn][4];
int n, m;
std::deque<Nodes> q;

int main() {
    scanf("%d%d", &n, &m);
    char ch;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf(" %c", &ch);
            G[i][j] == (ch == '#');
        }
    }
    memset(dist, 0x3f, sizeof dist);
    dist[n][n][2] = 0;
    q.push_back(Nodes(n, n, 2, 0));
    while(!q.empty()) {
        Nodes sb = q.front(); q.pop();
        if(vis[sb.x][sb.y][sb.dir]) continue;
        vis[sb.x][sb.y][sb.dir] = true;

    }
}
