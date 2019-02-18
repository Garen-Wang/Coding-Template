#include<cstdio>
#include<map>

std::map<int,int> mmp;
int n, k, tim;

int main()
{
    scanf("%d%d", &n, &k);
    tim = n / k;
    for(int i = 1; i <= n; i++)
    {
        int temp; scanf("%d", &temp);
        mmp[temp] = mmp[temp] + 1;
    }
    for(std::map<int,int>::iterator it = mmp.begin(); it != mmp.end(); ++it)
    {
        if(k == 0) break;
        int temp = it->second;
        if(temp < tim) continue;
        while(temp >= tim / 2 + 1)
        {
            printf("%d ", it->first);
            temp -= tim;
            k--;
            if(k == 0) break;
        }
    }
    printf("\n");
    return 0;
}
