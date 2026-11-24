#include <bits/stdc++.h>

using namespace std;

int N, K;
int city[100005];
int vt[10005];

int answer()
{
    int i = 1, ans = 0;

    while(i <= N)
    {
        bool flag = false;

        for(int j = i + K - 1; (j >= 0) && (j >= i - K + 1); j--)
        {
            if(j <= N && city[j])
            {
                ans++;
                i = j + K;
                flag = true;
                break;
            }
        }

        if(!flag) return -1;
    }

    return ans;
}

int main()
{
    scanf("%d %d", &N, &K);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &city[i]);
    }

    printf("%d", answer());

    return 0;
}