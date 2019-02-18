#include<iostream>
#include<algorithm>
const int maxn = 100005;
int a[maxn];
int n, m;

bool check(int mid)
{
    int cnt = 1;
    int now = a[1];
    for(int i = 2; i <= n; i++)
    {
        if(a[i] - now >= mid)
        {
            cnt++;
            now = a[i];
        }
    }
    return cnt >= m;
}
int main()
{
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    //std::cout << check(3) << std::endl;
    int left = 0, right = a[n] - a[1], ans = -1;
    while(left <= right)
    {
        int mid = (left + right) >> 1;
        if(check(mid)) ans = mid, left = mid + 1;
        else right = mid - 1;
    }
    std::cout << ans << std::endl;
    return 0;
}
