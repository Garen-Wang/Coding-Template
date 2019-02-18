#include<cstdio>
#include<cmath>
#include<algorithm>

int a[4];
int main()
{
    scanf("%d%d%d", &a[1], &a[2], &a[3]);
    std::sort(a + 1, a + 3 + 1);
    if(a[1] + a[2] > a[3])
    {
        printf("%d\n", 0);
    }
    else
    {
        printf("%d\n", a[3] - a[1] - a[2] + 1);
    }
    return 0;
}