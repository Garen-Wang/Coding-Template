/*************************************************************************
 @Author: Garen
 @Created Time : Wed 30 Jan 2019 12:53:57 PM CST
 @File Name: P1312.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int maxn = 6, maxm = 8;
int G[maxn][maxm];
int backup[maxn][maxn][maxm];
struct Nodes {
    int x, y, g;
    Nodes(int x, int y, int g): x(x), y(y), g(g) {}
};
std::vector<Nodes> answers;
bool vis[maxn][maxm];
int n;

void copy_one(int t) {
    for(int i = 1; i <= 5; i++) for(int j = 1; j <= 7; j++) backup[t][i][j] = G[i][j];
}
void copy_two(int t) {
    for(int i = 1; i <= 5; i++) for(int j = 1; j <= 7; j++) G[i][j] = backup[t][i][j];
}
bool find() {
    bool flag = false;
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 7; j++) {
            if(G[i][j] && i - 1 >= 1 && i + 1 <= 5 && G[i][j] == G[i + 1][j] && G[i][j] == G[i - 1][j]) {
                flag = true;
                vis[i][j] = vis[i - 1][j] = vis[i + 1][j] = true;
                for(int k = i - 2; k >= 1; k--) {
                    if(G[i][j] == G[k][j]) vis[k][j] = true;
                    else break;
                }
                for(int k = i + 2; k <= 5; k++) {
                    if(G[i][j] == G[k][j]) vis[k][j] = true;
                    else break;
                }
            }
            if(G[i][j] && j - 1 >= 1 && j + 1 <= 7 && G[i][j] == G[i][j - 1] && G[i][j] == G[i][j + 1]) {
                flag = true;
                vis[i][j] = vis[i][j - 1] = vis[i][j + 1] = true;
                for(int k = j - 2; k >= 1; k--) {
                    if(G[i][j] == G[i][k]) vis[i][k] = true;
                    else break;
                }
                for(int k = j + 2; k <= 7; k++) {
                    if(G[i][j] == G[i][k]) vis[i][k] = true;
                    else break;
                }
            }
        }
    }
    if(!flag) return false;
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 7; j++) {
            if(vis[i][j]) {
                vis[i][j] = G[i][j] = 0;
            }
        }
    }
    return true;
}
void update() {
    for(int i = 1; i <= 5; i++) {
        int now = 0;
        for(int j = 1; j <= 7; j++) {
            if(!G[i][j]) now++;
            else {
                if(!now) continue;
                G[i][j - now] = G[i][j]; G[i][j] = 0;
            }
        }
    }
}
bool empty() {
    for(int i = 1; i <= 5; i++) if(G[i][1]) return false;
    return true;
}
void dfs(int t) {
    if(t == n) {
        if(empty()) {
            for(auto it : answers) cout << it.x << ' ' << it.y << ' ' << it.g << endl;
            exit(0);
        }
        return;
    }
    copy_one(t);
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 7; j++) {
            if(G[i][j]) {
                // right
                if(i + 1 <= 5 && G[i][j] != G[i + 1][j]) {
                    std::swap(G[i][j], G[i + 1][j]);
                    answers.push_back(Nodes(i - 1, j - 1, 1));
                    update();
                    while(find()) update();
                    dfs(t + 1);
                    copy_two(t);
                    answers.pop_back();
                }
                // left
                if(i - 1 >= 1 && G[i - 1][j] == 0) {
                    std::swap(G[i][j], G[i - 1][j]);
                    answers.push_back(Nodes(i - 1, j - 1, -1));
                    update();
                    while(find()) update();
                    dfs(t + 1);
                    copy_two(t);
                    answers.pop_back();
                }
            }
        }
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= 5; i++) {
        int temp;
        for(int j = 1; ; j++) {
            cin >> temp;
            if(temp) G[i][j] = temp;
            else break;
        }
    }
    dfs(0);
    cout << -1 << endl;
    return 0;
}
