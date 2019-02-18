/*************************************************************************
 @Author: Garen
 @Created Time : Fri 01 Feb 2019 09:24:01 PM CST
 @File Name: T68264.cpp
 @Description:
 ************************************************************************/
#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
struct Nodes {
    ll a, b;
};
std::vector<Nodes> vec;
ll n;
ll ans;
bool cmp(Nodes A, Nodes B) {
    if(A.a == B.a) return A.b > B.b;
    return A.a > B.a;
}
bool cmp2(Nodes A, Nodes B) {
    return A.b < B.b;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        vec.push_back((Nodes){x, y});
    }
    for(int i = 1; i <= n; i++) {
        if(i % 2) {
            std::sort(vec.begin(), vec.end(), cmp);
            Nodes sb = *vec.begin();
            std::reverse(vec.begin(), vec.end());
            vec.pop_back();
            // print
            //cout << "Alice: " << sb.a << ' ' << sb.b << endl;
        } else {
            std::sort(vec.begin(), vec.end(), cmp2);
            Nodes sb = *(--vec.end());
            ans += sb.b;
        }
    }
    cout << ans << endl;
    return 0;
}
