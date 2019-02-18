/*************************************************************************
 @Author: Garen
 @Created Time : Mon 04 Feb 2019 09:19:21 PM CST
 @File Name: P2657.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll maxn = 2000000000;
ll a, b;
ll cnt;
bool check(ll x) {
    if(x >= 1 && x <= 9) return true;
}
int main() {
    printf("const ll chart[] = {");
    for(ll i = 1; i <= maxn; i++) {
        if(check(i)) {
            printf("%lld, \n", i);
            if((++cnt) % 20 == 0) {
                printf("\n");
            }
        }
    }
    printf("};\n");
    return 0;
}
