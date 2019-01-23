#include<iostream>
using std::cin;
using std::cout;
using std::endl;

const int maxn = 200005;
int a[maxn];
int bucket[maxn];
int n, m;
bool check(int mid)
{
    int ans = 0;
    for(int i = 1; i <= 200000; i++)
    {
        ans += bucket[i] / mid;
    }
    return ans >= m;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        bucket[a[i]]++;
    }
    int left = 1, right = n, ans = -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(check(mid)) ans = mid, left = mid + 1;
        else right = mid - 1;
    }
    //cout << ans << endl;
    int cnt = 0;
    for(int i = 1; i <= 200000; i++)
    {
        while(bucket[i] >= ans)
        {
            cout << i << ' ';
            bucket[i] -= ans;
            cnt++;
            if(cnt == m)
            {
                cout << endl;
                return 0;
            }
        }
    }
    cout << endl;
    return 0;
}
