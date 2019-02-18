/*************************************************************************
 @Author: Garen
 @Created Time : Thu 14 Feb 2019 12:14:46 AM CST
 @File Name: temp2.cpp
 @Description:
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
const double t0 = 2019;
const double delta = 0.996;
const double tk = 1e-6;
const long long INF = 1e18;
const int N = 50;
int n;
long long a[N], ans;

inline long long calc() {
    long long x = 0, y = 0;
    for (int i = 1; i <= (n >> 1); i++) x += a[i];
    for (int i = (n >> 1) + 1; i <= n; i++) y += a[i];
    return abs(x - y);
}

inline int Rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

inline void SA() {
    double t = t0;
    while (t > tk) {
        int x = Rand(1, n >> 1), y = Rand((n >> 1) + 1, n);
        swap(a[x], a[y]);
        int now = calc();
        if (now < ans) ans = now;
        else if (exp((double)(ans - now) / t) * RAND_MAX <= rand())
            swap(a[x], a[y]);
        t *= delta;
    }
}

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ans = INF;
    for (int i = 1; i <= 37; i++) SA();
    cout << ans << endl;
}

int main() {
    srand(time(0));
    srand(rand());
    int t;
    cin >> t;
    while (t--) work();
    return 0;
}
