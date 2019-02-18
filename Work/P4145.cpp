#include<iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
#define ll long long

const ll maxn = 100005;
ll a[maxn];
ll n, m;

struct segTree
{
    ll maxv[maxn << 2], sum[maxn << 2], lazy[maxn << 2];
    #define lson (root << 1)
    #define rson (root << 1 | 1)
    void pushup(ll root)
    {
        maxv[root] = std::max(maxv[lson], maxv[rson]);
        sum[root] = sum[lson] + sum[rson];
    }
    void pushdown(ll root, ll l, ll r)
    {
        if(lazy[root] != 0)
        {
            ll &x = lazy[root];
            ll mid = (l + r) >> 1;
            sum[lson] += x * (mid - l + 1);
            maxv[lson] += x;
            lazy[lson] += x;
            sum[rson] += x * (r - mid);
            maxv[rson] += x;
            lazy[rson] += x;
            x = 0;
        }
    }
    void build(ll root, ll l, ll r)
    {
        lazy[root] = 0;
        if(l == r) maxv[root] = sum[root] = a[l];
        else
        {
            int mid = (l + r) >> 1;
            build(lson, l, mid);
            build(rson, mid + 1, r);
            pushup(root);
        }
    }
    void update(ll root, ll l, ll r, ll x, ll y)
    {
        if(r < x || y < l) return;
        if(maxv[root] == 1 || maxv[root] == 0) return;
        if(l == r)
        {
            sum[root] = maxv[root] = sqrt(sum[root]);
        }
        else
        {
            pushdown(root, l, r);
            ll mid = (l + r) >> 1;
            update(lson, l, mid, x, y);
            update(rson, mid + 1, r, x, y);
            pushup(root);
        }
    }
    ll query(ll root, ll l, ll r, ll x, ll y)
    {
        if(r < x || y < l) return 0;
        if(x <= l && r <= y) return sum[root];
        pushdown(root, l, r);
        int mid = (l + r) >> 1;
        return query(lson, l, mid, x, y) + query(rson, mid + 1, r, x, y);
    }
} seg;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    seg.build(1, 1, n);
    cin >> m;
    while(m--)
    {
        ll k, l, r; cin >> k >> l >> r;
        if(l > r) std::swap(l, r);
        if(k)
        {
            cout << seg.query(1, 1, n, l, r) << endl;
        }
        else
        {
            seg.update(1, 1, n, l, r);
        }
    }
    return 0;
}
