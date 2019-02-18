#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define ll long long
const int maxn = 30005;
int a[maxn];
bool vis[maxn];
int w, n;

int main() {
	cin >> w >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	std::sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1, j = n; i < j; ) {
		if(a[i] + a[j] <= w) {
            //cout << a[i] << ' ' << a[j] << endl;
            vis[i] = vis[j] = true;
			ans++; i++; j--;
		} else {
            //cout << a[j] << endl;
            vis[j] = true;
			ans++; j--;
		}
	}
    for(int i = 1; i <= n; i++) if(!vis[i]) {
        //cout << a[i] << endl;
        ans++;
    }
	cout << ans << endl;
	return 0;
}
