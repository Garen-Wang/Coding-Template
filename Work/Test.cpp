#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1005;
vector<int> G[maxn];
vector<int> no;
int fa[maxn];
bool vis[maxn];
int cnt[maxn];
int maxd, idx;
int pos1, pos2;
int n, m;

void dfs1(int u, int f, int dep)
{
    if(dep > maxd)
    {
        maxd = dep, idx = u;
    }
    for(auto it : G[u])
    {
        int v = it;
        if(v == f) continue;
        dfs1(v, u, dep + 1);
    }
}
void get_diameter()
{
    maxd = idx = -1;
    dfs1(1, 0, 0);
    pos1 = idx;
    maxd = idx = -1;
    dfs1(pos1, 0, 0);
    pos2 = idx;
}
int diameter()
{
    maxd = idx = -1;
    dfs1(1, 0, 0);
    int temp = idx;
    maxd = idx = -1;
    dfs1(temp, 0, 0);
    return maxd;
}
void dfs2(int u, int f)
{
    fa[u] = f;
    for(auto it : G[u])
    {
        int v = it;
        if(v == f) continue;
        dfs2(v, u);
    }
}
void another_solution()
{
    if(n == 1)
    {
        cout << 0 << endl;
    }
    else if(n == 2)
    {
        cout << 1 << endl << 1 << ' ' << 2 << endl;
    }
    else
    {
        cout << 2 << endl;
        for(int i = 2; i <= n; i++)
        {
            cout << 1 << ' ' << i << endl;
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
        vis[u] = vis[v] = true;
    }
    for(int i = 1; i <= n; i++) if(!vis[i]) no.push_back(i);
    if(m == 0)
    {
        another_solution();
        return 0;
    }
    get_diameter();
    dfs2(pos1, 0);
    int rt = pos2;
    int ans = 0x7fffffff, which = -1;
    while(rt != pos1)
    {
        for(auto it : no)
        {
            G[rt].push_back(it); cnt[rt]++;
            G[it].push_back(rt); cnt[it]++;
        }
        int res = diameter();
        //cout << res << endl;
        if(res < ans)
        {
            ans = res; which = rt;
        }
        for(int i = 1; i <= n; i++)
        {
            while(cnt[i]--)
            {
                G[i].pop_back();
            }
            cnt[i]++;
        }
        rt = fa[rt];
    }
    cout << ans << endl;
    for(auto it : no)
    {
        cout << which << ' ' << it << endl;
    }
    return 0;
}