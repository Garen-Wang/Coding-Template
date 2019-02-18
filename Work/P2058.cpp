#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 100005;
struct Questions {
    int len;
    std::vector<int> vec;
} que[maxn];
int times[maxn];
int n;
struct Nodes {
    int l, r;
} segment[maxn];
int belong[maxn], len;
int cnt[maxn];
int answers[maxn];
void add(int idx, int &ans) {
    for(int i = 0; i < que[idx].len; i++) {
        if(++cnt[que[idx].vec[i]] == 1) ans++;
    }
}
void remove(int idx, int &ans) {
    for(int i = 0; i < que[idx].len; i++) {
        if(--cnt[que[idx].vec[i]] == 0) ans--;
    }
}
void moqueue() {
    int l = 1, r = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        while(r < segment[i].r) add(++r, ans);
        while(r > segment[i].r) remove(r--, ans);
        while(l < segment[i].l) remove(l++, ans);
        while(l > segment[i].l) add(--l, ans);            
        answers[i] = ans;
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int t, k; cin >> t >> k;
        times[i] = t;
        for(int j = 1; j <= k; j++) {
            int temp; cin >> temp;
            que[i].vec.push_back(temp);
        }
        std::sort(que[i].vec.begin(), que[i].vec.end());
        que[i].len = std::unique(que[i].vec.begin(), que[i].vec.end()) - que[i].vec.begin();
    }
    for(int i = 1; i <= n; i++) {
        int temp1 = std::lower_bound(times + 1, times + n + 1, times[i] - 86400 + 1) - times;// must +1 here
        segment[i].l = temp1, segment[i].r = i;
    }
    len = sqrt(n);
    for(int i = 1; i <= n; i++) belong[i] = (i - 1) / len + 1;
    std::sort(segment + 1, segment + n + 1, [](Nodes A, Nodes B) {
        if(belong[A.l] == belong[B.l]) return A.r < B.r;
        return belong[A.l] < belong[B.l];
    });
    moqueue();
    for(int i = 1; i <= n; i++) cout << answers[i] << endl;
    return 0;
}
