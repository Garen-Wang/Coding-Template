/*************************************************************************
 @Author: Garen
 @Created Time : Tue 05 Feb 2019 10:25:29 PM CST
 @File Name: P1433.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define pdd pair<double,double>
const int maxn = 20;
const double INF = 1e18;
const double delta = 0.88;
const double eps = 1e-6;
std::pdd s[maxn];
int b[maxn];
double G[maxn][maxn];
double ans;
int n;
double get_ans() {
    double res = 0;
    for(int i = 1; i <= n; i++) {
        res += G[b[i - 1]][b[i]];
    }
    return res;
}
void SA() {
    for(int i = 1; i <= n; i++) b[i] = i;
    ans = std::min(ans, get_ans());
    for(double T = 200005; T > eps; T *= delta) {
        for(int t = 1; t <= 1000; t++) {
        int x = rand() % n + 1, y = rand() % n + 1;
        while(x == y) x = rand() % n + 1, y = rand() % n + 1;
        std::swap(b[x], b[y]);
        double newans = get_ans();
        double DE = ans - newans;
        if(DE > 0) {
            ans = newans;
        } else if(exp(-DE / T) * RAND_MAX > rand()) {
            
        } else std::swap(b[x], b[y]);
        }
    }
}
int main() {
    int time_start = clock();
    srand(19260817);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i].first >> s[i].second;
    for(int i = 1; i <= n; i++) {
        G[0][i] = sqrt(s[i].first * s[i].first + s[i].second * s[i].second);
        G[i][i] = 0;
        for(int j = i + 1; j <= n; j++) {
            G[i][j] = G[j][i] = sqrt((s[i].first - s[j].first) * (s[i].first - s[j].first) + (s[i].second - s[j].second) * (s[i].second - s[j].second));
        }
    }
    ans = INF;
    while(clock() - time_start < 0.8 * CLOCKS_PER_SEC) SA();
    printf("%.2lf\n", ans);
    return 0;
}
