#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n, d;
int cnt;
std::vector<int> vec;
int where[10];

void sure()
{
    if(cnt >= 76)
    {
        exit(0);
    }
}
int main()
{
    scanf("%d%d", &n, &d);
    printf("%d.", n / d);
    cnt = std::max(log10(n / d), 0.0) + 1;
    n = n % d;
    while(cnt <= 76)
    {
        n = n * 10;
        if(n == 0)
        {
            for(int i = 0; i < vec.size(); i++)
            {
                printf("%d", vec[i]);
            }
            return 0;
        }
        if(where[n / d])
        {
            for(int i = 0; i < where[n / d]; i++)
            {
                printf("%d", vec[i]); cnt++;
                sure();
            }
            printf("("); cnt++;
            sure();
            for(int i = where[n / d]; i < vec.size(); i++)
            {
                printf("%d", vec[i]); cnt++;
                sure();
            }
            printf(")"); cnt++;
            sure();
            break;
        }
        else
        {
            vec.push_back(n / d);
            where[n / d] = vec.size() - 1;
        }
        //printf("%d", n / d); cnt++;
        n = n % d;
    }
    printf("\n");
    return 0;
}
