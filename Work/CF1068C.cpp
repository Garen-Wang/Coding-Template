#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
const int maxn = 105;
#define pii pair<int,int>
std::vector<int> vec;
std::vector<std::pii> rooks[maxn];
bool vis[maxn];
int n, m;
void print()
{
    for(int i = 1; i <= n; i++)
    {
        printf("%d\n", (int)(rooks[i].size()));
        for(auto it = rooks[i].begin(); it != rooks[i].end(); ++it)
        {
            printf("%d %d\n", it->first, it->second);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        rooks[i].push_back(std::make_pair(i, i));
    }
    for(int i = 1; i <= m; i++)
    {
        int x, y; scanf("%d%d", &x, &y);
        rooks[x].push_back(std::make_pair(x, n + i));
        rooks[y].push_back(std::make_pair(y, n + i));
    }
    print();
    return 0;
}
