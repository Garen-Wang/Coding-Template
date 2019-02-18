/*************************************************************************
 @Author: Garen
 @Created Time : Fri 01 Feb 2019 08:23:00 PM CST
 @File Name: T68262.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
int n, ans;
std::map<int,int> mmp;
void dfs(int money, int mianjin) {
    if(mmp.count(money)) {
        ans = std::max(ans, mianjin + mmp[money]);
        return;
    }
    if(money < 5) {
        ans = std::max(ans, mianjin);
        return;
    }
    if(money >= 17) dfs(money - 17, mianjin + 12);
    if(money >= 10) dfs(money - 10, mianjin + 7);
    if(money >= 5) dfs(money - 5, mianjin + 2);
    mmp[money] = ans - mianjin;
}
/*
int main() {
    freopen("out.txt", "w", stdout);
    for(int i = 1; i <= 150; i++) {
        ans = 0;
        dfs(i, 0);
        //printf("idx = %d, ans = %d\n", i, ans);
        printf("%d\n", ans);
    }
    return 0;
}
*/
int main() {
    int T; cin >> T;
    while(T--) {
        cin >> n;
        ans = 0;
        dfs(n, 0);
        cout << ans << endl;
    }
    return 0;
}
