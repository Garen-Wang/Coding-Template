#include<iostream>
using std::cin;
using std::cout;
using std::endl;

const int maxn = 5005, maxm = 30005;
int weight[maxn], value[maxn];
int dp[maxm];

int n, m, k, p;

int main()
{
    cin >> n >> m >> k >> p;
    for(int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= weight[i]; j--)
        {
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    p += dp[m];
    //cout << p << endl;
    int ans = 0;
    for(int i = 1; i <= k; i++)
    {
        int t, w; cin >> t >> w;
        if(t * p >= w) ans++;
    }
    if(ans == k) cout << "AC" << endl;
    else cout << ans << endl;
    return 0;
}
