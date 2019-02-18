#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 100005;
int a[maxn];
int n, k, m;
double tot;
int cnt;
int cnt2;
int pos1;

// long long
int main() {
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    cnt = n;
    std::sort(a + 1, a + n + 1);
    pos1 = 1;
    for(int i = 1; i <= m; i++) {
        double avg = tot / cnt;
        double avg1 = cnt > 1 ? (tot - a[pos1]) / (cnt - 1) : 0;
        double avg2 = (tot + 1) / cnt;
        //cout << avg << ' ' << avg1 << ' ' << avg2 << endl;
        if(avg1 < avg2) {
            if(cnt2 < cnt * k) {
                cnt2++;
                tot++;
            } else if(cnt > 1) {
                tot -= a[pos1];
                cnt--;
                pos1++;
            }
        } else {
            if(pos1 < n) {
                tot -= a[pos1];
                cnt--;
                pos1++;
            } else if(cnt2 < cnt * k) {
                cnt2++;
                tot++;
            }
        }
    }
    printf("%.10lf\n", tot / cnt);
    return 0;
}
