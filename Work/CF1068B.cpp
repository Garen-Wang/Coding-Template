#include<iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;

#define ll long long
ll b;

ll solve(ll b)
{
    ll ans = 0;
    ll bound = sqrt(b);
    for(int i = 1; i <= bound; i++)
    {
        if(b % i == 0)
        {
            ans++;
            if(b / i != i) ans++;
        }
    }
    return ans;
}
int main()
{
    cin >> b;
    cout << solve(b) << endl;
    return 0;
}
