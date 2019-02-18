#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 305;
struct Nodes {
    int l, r;
} s[maxn];
int a[maxn];
int n, m;
std::vector<int> answers, results;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> s[i].l >> s[i].r;
    int ans = 0;
    for(int minidx = 1; minidx <= n; minidx++) {
        for(int maxidx = 1; maxidx <= n; maxidx++) {
            if(minidx == maxidx) continue;
            results.clear();
            int res = a[maxidx] - a[minidx];
            for(int i = 1; i <= m; i++) {
                if(s[i].l <= minidx && minidx <= s[i].r) {
                    if(s[i].l <= maxidx && maxidx <= s[i].r) {
                        // both -1
                    } else {
                        // good
                        res++;
                        results.push_back(i);
                    }
                } else {
                    if(s[i]. l <= maxidx && maxidx <= s[i].r) {
                        // bad
                    } else {
                        // both + 1
                    }
                }
            }
            if(res > ans) {
                ans = res;
                answers = results;
            }
        }
    }
    cout << ans << endl;
    cout << answers.size() << endl;
    bool first = true;
    for(auto it : answers) {
        if(first) first = false;
        else cout << ' ';
        cout << it;
    }
    cout << endl;
    return 0;
}
