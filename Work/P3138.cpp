#include<iostream>
#include<algorithm>
const int maxn = 1005;
struct Nodes {
    int x, y;
    int xx, yy;
} s[maxn];
int X[maxn], Y[maxn];
int posx, posy;
int G[maxn][maxn];
int sum[maxn][maxn];
int n;

int getsum(int x, int y, int xx, int yy) {
    return sum[xx][yy] - sum[x - 1][yy] - sum[xx][y - 1] + sum[x - 1][y - 1];
}
int main() {
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> X[i] >> Y[i];
        s[i].x = X[i], s[i].y = Y[i];
    }
    std::sort(X + 1, X + n + 1);
    posx = std::unique(X + 1, X + n + 1) - X - 1;
    //for(int i = 1; i <= posx; i++) std::cout << X[i] << ' ';
    //std::cout << std::endl;
    std::sort(Y + 1, Y + n + 1);
    posy = std::unique(Y + 1, Y + n + 1) - Y - 1;
    //for(int i = 1; i <= posy; i++) std::cout << Y[i] << ' ';
    //std::cout << std::endl;
    for(int i = 1; i <= n; i++) {
        s[i].xx = std::lower_bound(X + 1, X + posx + 1, s[i].x) - X;
        s[i].yy = std::lower_bound(Y + 1, Y + posy + 1, s[i].y) - Y;
        //std::cout << s[i].xx << ' ' << s[i].yy << std::endl;
        G[s[i].xx][s[i].yy]++;
    }
    for(int i = 1; i <= posx; i++) {
        for(int j = 1; j <= posy; j++) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + G[i][j];
        }
    }
    /*
    for(int i = 1; i <= posx; i++) {
        for(int j = 1; j <= posy; j++) {
            std::cout << i << ' ' << j << " = " << sum[i][j] << std::endl;
        }
    }
    */
    /*
    int ekx, eky;
    while(std::cin >> ekx >> eky) {
        std::cout << getsum(2, 2, ekx, eky) << std::endl;
    }
    */
    int ans = 0x7fffffff;
    for(int i = 1; i < posx; i++) { // divide i and i + 1 
        for(int j = 1; j < posy; j++) { // divide j and j + 1
            int temp1 = getsum(1, 1, i, j);
            int temp2 = getsum(i + 1, 1, posx, j);
            int temp3 = getsum(1, j + 1, i, posy);
            int temp4 = getsum(i + 1, j + 1, posx, posy);
            int res = std::max(std::max(temp1, temp2), std::max(temp3, temp4));
            ans = std::min(ans, res);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
