#include<cstdio>
#include<cmath>
#include<iostream>

const int maxn = 10005;
const double eps = 1e-8;
int n, k;
double a[maxn];
bool check(double mid)
{
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cnt += a[i] / mid;
    }
    return cnt >= k;
}
int main() {
    std::cin >> n >> k;
    double left = 0, right = 0;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        left = std::min(left, a[i]);
        right = std::max(right, a[i]);
    }
    while(right - left > eps) {
        //std::cout << left << ' ' << right << std::endl;
        double mid = (left + right) / 2.0;
        if(check(mid)) left = mid;
        else right = mid;
    }
    printf("%.2lf\n", floor(right * 100) / 100);
    return 0;
}
