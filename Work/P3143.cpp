#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 50005;
int a[maxn];
int pre[maxn], suf[maxn];
int n, k;

void work1() {
    for(int r = 1, l = 0; r <= n; r++) {
        while(a[r] - a[l + 1] > k) l++;
        pre[r] = std::max(pre[r - 1], r - l);
    }
}
void work2() {
    for(int l = n, r = n + 1; l >= 1; l--) {
        while(a[r - 1] - a[l] > k) r--;
        suf[l] = std::max(suf[l + 1], r - l);
    }
}
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    work1();
    work2();
    int ans = 0;
    for(int i = 1; i <= n + 1; i++) {
        ans = std::max(ans, pre[i - 1] + suf[i]);
    }
    cout << ans << endl;
    return 0;
}
