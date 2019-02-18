#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 20;
bool isprime[40];
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int n;
bool vis[maxn];
int ans[maxn];
void init() {
    for(int i = 0; i < 12; i++) {
        isprime[primes[i]] = true;
    }
}
void print() {
    for(int i = 1; i <= n; i++) {
        printf("%d", ans[i]);
        if(i != n) printf(" ");
    }
    printf("\n");
}
void dfs(int t) {
    if(t == n + 1) {
        if(!isprime[ans[n] + ans[1]]) return;
        print();
    } else {
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && isprime[i + ans[t - 1]]) {
                vis[i] = true;
                ans[t] = i;
                dfs(t + 1);
                vis[i] = false;
                ans[t] = 0;
            }
        }
    }
}
int main() {
    init();
    int kase = 0;
    while(cin >> n) {
        kase++;
        if(kase >= 2) printf("\n");
        printf("Case %d:\n", kase);
        vis[1] = true;
        ans[1] = 1;
        dfs(2);
        vis[1] = false;
        ans[1] = 0;
    }
    return 0;
}
