#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll INF = 0x7fffffff;

ll p[105], b[105];
ll k, n;
ll ans[100005];

int main()
{
    cin >> k >> n;
    for(int i = 1; i <= k; i++) cin >> p[i];
    ans[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        ll minv = INF;
        for(int j = 1; j <= k; j++)
        {
            while(p[j] * ans[b[j]] <= ans[i - 1]) b[j]++;
            if(p[j] * ans[b[j]] < minv) minv = p[j] * ans[b[j]];
        }
        ans[i] = minv;
    }
    cout << ans[n] << endl;
    return 0;
}
