#include<iostream>
#include<map>
using namespace std;
#define ll long long
const int maxn = 1005;
struct Nodes
{
    int x, y;
} s[maxn];
int n;
map<ll,int> mmp;
ll id(int x, int y)
{
    return (x - 3000000) * 3000000 + y - 3000000;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i].x >> s[i].y;
    }
    for(int i = 1; i <= n; i++)
    {
        int xx, yy; cin >> xx >> yy;
        for(int j = 1; j <= n; j++)
        {
            int newx = s[j].x + xx, newy = s[j].y + yy;
            //std::cout << newx << ' ' << newy << endl;
            mmp[id(newx, newy)]++;
            if(mmp[id(newx, newy)] == n)
            {
                std::cout << newx << ' ' << newy << endl;
                return 0;
            }
        }
    }
    return 0;
}
