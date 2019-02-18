/*************************************************************************
 @Author: Garen
 @Created Time : Mon 11 Feb 2019 03:41:08 PM CST
 @File Name: P1045.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
struct INT {
    int a[502], len;
    INT() {
        memset(a, 0, sizeof a); len = 0;
    }
    INT(int x) {
        memset(a, 0, sizeof a); len = 0;
        if(x == 0) len = 1;
        else {
            while(x) {
                a[++len] = x % 10;
                x /= 10;
            }
        }
    }
};

INT mul(INT A, INT B) {
    INT ret;
    ret.len = std::min(500, A.len + B.len + 2);
    for(int i = 1; i <= std::min(500, A.len); i++) {
        for(int j = 1; j <= std::min(500, B.len); j++) {
            if(i + j - 1 <= 500) {
                ret.a[i + j - 1] += A.a[i] * B.a[j];
                if(ret.a[i + j - 1] / 10) {
                    if(i + j <= 500) ret.a[i + j] += ret.a[i + j - 1] / 10;
                    ret.a[i + j - 1] %= 10;
                }
            }
        }
    }
    while(ret.a[ret.len] == 0 && ret.len > 1) ret.len--;
    return ret;
}
INT pow_mod(INT x, int y) {
    INT ans(1);
    while(y) {
        if(y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}
void print(INT x) {
    for(int i = 500; i >= 50; i -= 50) {
        for(int j = i; j > i - 50; j--) printf("%d", x.a[j]);
        printf("\n");
    }
}
void print2(INT x) {
    for(int i = x.len; i >= 1; i--) {
        printf("%d", x.a[i]);
    }
    printf("\n");
}
INT minus(INT x) {
    x.a[1]--;
    for(int i = 1; i <= x.len; i++) {
        if(x.a[i] < 0) {
            x.a[i + 1]--;
            x.a[i] += 10;
        }
    }
    if(x.len == 0) x.len--;
    return x;
}
int main() {
    /*
    int temp1, temp2; scanf("%d %d", &temp1, &temp2);
    INT t1(temp1), t2(temp2);
    INT ans = mul(t1, t2);
    print(ans);
    return 0;
    */
    int p; scanf("%d", &p);
    int ans1 = log10(2) * p + 1;
    printf("%d\n", ans1);
    INT ans2 = minus(pow_mod(INT(2), p));
    print(ans2);
    return 0;
}
