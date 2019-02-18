#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 120005;
int num[7];
int weight[maxn];
bool dp[maxn];
int n, m;

bool check() {
    for(int i = 1; i <= 6; i++) if(num[i]) return false;
    return true;
}
int main() {
    int kase = 0;
    while(2333) {
        for(int i = 1; i <= 6; i++) scanf("%d", &num[i]);
        if(check()) break;
        printf("Collection #%d:\n", ++kase);
        n = m = 0;
        for(int i = 1; i <= 6; i++) {
            m += i * num[i];
        }
        if(m % 2) {
            printf("Can't be divided.\n\n");
            continue;
        }
        m /= 2;
        for(int i = 1; i <= 6; i++) {
            int base = 1;
            while(base <= num[i]) {
                weight[++n] = base * i;
                num[i] -= base;
                base *= 2;
            }
            if(num[i]) weight[++n] = num[i] * i;
        }
        memset(dp, false, sizeof dp);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = m; j >= weight[i]; j--) {
                dp[j] = dp[j] || dp[j - weight[i]];
            }
        }
        if(dp[m]) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}
