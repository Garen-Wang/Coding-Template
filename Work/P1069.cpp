#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 30005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n, m1, m2;
ll s[maxn];
bool notprime[maxn];
int primes[maxn], tot;
ll st[maxn], pp[maxn];
void init() {
    notprime[1] = true;
    for(int i = 2; i <= 30000; i++) {
        if(!notprime[i]) {
            primes[++tot] = i;
        }
        for(int j = 1; j <= tot && i * primes[j] <= 30000; j++) {
            notprime[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}
void fenjie(ll x, ll idx) {
    for(int i = 1; i <= tot; i++) {
        while(x && x % primes[i] == 0) {
            x /= primes[i];
            if(idx == 0) st[i]++;
            else pp[i]++;
        }
    }
}
int main() {
    //freopen("in.txt", "r", stdin);
    init();
    cin >> n >> m1 >> m2;
    if(m1 == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++) cin >> s[i];
    fenjie(m1, 0);
    for(int i = 1; i <= tot; i++) st[i] *= m2;
    ll ans = INF;
    for(int i = 1; i <= n; i++) {
        memset(pp, 0, sizeof pp);
        fenjie(s[i], i);
        ll res = -INF;
        bool flag = false;
        for(int j = 1; j <= tot; j++) {
            /*
            if(st[j] != 0 && pp[j] == 0) flag = true;
            if(st[j] != 0 && pp[j] != 0) {
                if(st[j] % pp[j] == 0) res = std::max(res, st[j] / pp[j]);
                else res = std::max(res, st[j] / pp[j] + 1);
            }
            */
           if(st[j] == 0) {

           } else {
               if(pp[j] == 0) flag = true;
               else {
                   res = std::max(res, st[j] / pp[j] + (st[j] % pp[j] != 0));
               }
           }
        }
        if(!flag) ans = std::min(ans, res);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}