#include<bits/stdc++.h>
const int maxn = 100005;
struct Nodes {
    int l, r, id;
} a[maxn];
int n;
bool cmp1(Nodes A, Nodes B) {
    if(A.l == B.l) return A.r < B.r;
    return A.l < B.l;
}
bool cmp2(Nodes A, Nodes B) {
    return A.id < B.id;
}
int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i].l, &a[i].r); a[i].id = i;
        }
        std::sort(a + 1, a + n + 1, cmp1);
        int k = 0, r = a[1].r;
        for(int i = 2; i <= n; i++) {
            if(r < a[i].l) {
                k = a[i].l;
            }
            r = std::max(r, a[i].r);
        }
        std::sort(a + 1, a + n + 1, cmp2);
        if(k) {
            for(int i = 1; i <= n; i++) {
                printf("%d", (a[i].l >= k ? 2 : 1));
                if(i != n) printf(" ");
            }
        } else printf("-1");
        printf("\n");
    }
    return 0;
}
