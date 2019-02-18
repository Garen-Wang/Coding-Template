#include<iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;

#define ll long long
ll n, m, k, l;

ll solve()
{
    if(n < m) return -1;
    if(k + l > n) return -1;
    ll temp = (k + l) / m;
    if(temp * m < k + l) temp++;
    if(temp == 0) return -1;
    else
    {
        if(temp * m > n) return -1;
        return temp;
    }
}
int main()
{
    cin >> n >> m >> k >> l;
    cout << solve() << endl;
    return 0;
}
