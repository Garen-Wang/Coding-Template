#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
std::map<int,int> mmp;
std::vector<int> vec;
int n;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int temp; scanf("%d", &temp);
        mmp[temp] = mmp[temp] + 1;
    }
    for(std::map<int,int>::iterator it = mmp.begin(); it != mmp.end(); ++it)
    {
        vec.push_back(it->second);
    }
    std::sort(vec.begin(), vec.end());
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        printf("%d ", *it);
    }
    printf("\n");
    for(int i = 1; i <= vec[0]; i++)
    {
        int base = i * 2;
        int ans = 0;
        int k = 0;
        while(2333)
        {
            int temp = std::lower_bound(vec.begin(), vec.end(), base) - vec.begin();
            printf("%d\n", temp);
            if(temp >= vec.size()) break;
            ans += base;
            base *= 2;
        }
        printf("ans: %d\n", ans);
        printf("\n");
    }
    printf("\n");
    return 0;
}
