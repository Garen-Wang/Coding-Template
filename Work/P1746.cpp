#include<cstdio>
#include<cstring>
#include<queue>
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int maxn = 1005;
int G[maxn][maxn];
int n;
int sx, sy, ex, ey;
struct Nodes
{
	int x, y;
	Nodes(int x, int y): x(x), y(y){}
};
std::queue<Nodes> q;
bool vis[maxn][maxn];
int dist[maxn][maxn];
bool check(int x, int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= n && !G[x][y];
}
void spfa()
{
	memset(dist, 0x3f, sizeof dist);
	q.push(Nodes(sx, sy));
	dist[sx][sy] = 0;
	while(!q.empty())
	{
		Nodes sb = q.front(); q.pop(); vis[sb.x][sb.y] = false;
		if(sb.x == ex && sb.y == ey)
		{
			printf("%d\n", dist[ex][ey]);
			return;
		}
		for(int i = 0; i < 4; i++)
		{
			int newx = sb.x + dx[i], newy = sb.y + dy[i];
			if(check(newx, newy) && dist[sb.x][sb.y] + 1 < dist[newx][newy])
			{
				dist[newx][newy] = dist[sb.x][sb.y] + 1;
				if(!vis[newx][newy])
				{
					q.push(Nodes(newx, newy));
					vis[newx][newy] = true;
				}
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			scanf("%1d", &G[i][j]);
		}
	}
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	spfa();
	return 0;
}
