#include<cstdio>

const int maxn = 1000005;
char ch[maxn];
int n;
int s1[maxn], s2[maxn];
bool b1[maxn], b2[maxn];

int main() {
    scanf("%d", &n);
    scanf("%s", ch + 1);
    for(int i = 1; i <= n; i++) {
        s1[i] = s1[i - 1] + (ch[i] == '(' ? 1 : -1);
        if(s1[i] >= 0) b1[i] = true;
        else break;
    }
    for(int i = n; i >= 1; i--) {
        s2[i] = s2[i + 1] + (ch[i] == ')' ? 1 : -1);
        if(s2[i] >= 0) b2[i] = true;
        else break;
    }
    int ans = 0;
    b1[0] = b1[n + 1] = b2[0] = b2[n + 1] = true;
    for(int i = 1; i <= n; i++) {
        if(b1[i - 1] && b2[i + 1]) {
            if(ch[i] == '(') {
                if(s1[i - 1] - 1 == s2[i + 1]) ans++;
            } else if(ch[i] == ')') {
                if(s1[i - 1] + 1 == s2[i + 1]) ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
