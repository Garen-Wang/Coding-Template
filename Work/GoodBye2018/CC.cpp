#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define ll long long
vector<ll> vec;
ll n;

ll getsum(ll a1, ll d, ll n)
{
    return n * a1 + n * (n - 1) / 2 * d;
}
int main()
{
    cin >> n;
    for(ll i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            ll temp = n / i;
            // solve i
            //cout << getsum(1, temp, i) << endl;
            vec.push_back(getsum(1, temp, i));
            if(i != temp)
            {
                // solve temp
                //cout << getsum(1, i, temp) << endl;
                vec.push_back(getsum(1, i, temp));
            }
        }
    }
    sort(vec.begin(), vec.end());
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}
