#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const ll maxn = 65;
const double eps = 1e-6;
const double delta = 0.99;
ll a[maxn];
ll ans;
ll n;

ll getans() {
    ll res = 0;
	for(ll i = 1; i <= n; i++) {
		if(i <= (n + 1) / 2) res += a[i];
		else res -= a[i];
	}
	return llabs(res);
}
void SA() {
	for(double T = 4396; T > eps; T *= delta) {
		ll x = rand() % ((n + 1) / 2) + 1, y = rand() % (n / 2) + 1 + ((n + 1) / 2);
        if(x < 1 || x > n || y < 1 || y > n) continue;
		std::swap(a[x], a[y]);
		ll newans = getans();
		double DE = newans - ans;
		if(DE < 0) {
			ans = newans;
		} else if(exp(-DE / T) * RAND_MAX > rand()) {

		} else std::swap(a[x], a[y]);
	}
}
int main() {
	srand(19260817);
	ll t; cin >> t;
	while(t--) {
		cin >> n;
		for(ll i = 1; i <= n; i++) cin >> a[i];
        if(n == 1) {
            cout << a[1] << endl;
            continue;
        }
		ans = getans();
		for(ll i = 1; i <= 50; i++) SA();
		cout << ans << endl;
	}
	return 0;
}
