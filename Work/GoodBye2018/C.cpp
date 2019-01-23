#include<iostream>

int n;

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int main()
{
    while(233)
    {
    std::cin >> n;
    for(int k = 1; k <= n; k++)
    {
        std::cout << k << ": 1 ";
        int now = 1, ans = 1;
        now += k; if(now > n) now -= n;
        while(now != 1)
        {
            std::cout << now  << ' ';
            ans += now;
            now += k; if(now > n) now -= n;
        }
        std::cout << "= " << ans << " gcd: " << gcd(n, k) << " len: " << n / gcd(n, k) << std::endl;
    }
    }
    return 0;
}
// when n is prime, answer is "1 (1 + 2 + ... + n)"
// when n k huzhi, answer is (1 + 2 + ... + n)
//
