/*************************************************************************
 @Author: Garen
 @Created Time : Sat 09 Feb 2019 03:40:36 PM CST
 @File Name: CF1101B.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
#define ll long long
const int maxn = 500005;
char ch[maxn];
int pos1, pos2, pos3, pos4, cnt;
int main() {
    fgets(ch + 1, maxn, stdin);
    int n = strlen(ch + 1);
    for(int i = 1; i <= n; i++) {
        if(ch[i] == '[') {
            pos1 = i; break;
        }
    }
    for(int i = n; i >= 1; i--) {
        if(ch[i] == ']') {
            pos2 = i; break;
        }
    }
    if(pos1 == 0 || pos2 == 0 || pos1 >= pos2) {
        printf("-1\n");
        return 0;
    }
    for(int i = pos1 + 1; i < pos2; i++) {
        if(ch[i] == ':') {
            pos3 = i; break;
        }
    }
    for(int i = pos2 - 1; i > pos1; i--) {
        if(ch[i] == ':') {
            pos4 = i; break;
        }
    }
    if(pos3 == 0 || pos4 == 0 || pos3 >= pos4) {
        printf("-1\n");
        return 0;
    }
    for(int i = pos3 + 1; i < pos4; i++) {
        if(ch[i] == '|') cnt++;
    }
    printf("%d\n", cnt + 4);
    return 0;
}
