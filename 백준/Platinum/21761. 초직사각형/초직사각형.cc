#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, K;

ll len[4];

vector<int> v[4];

void input()
{
    scanf("%d %d", &N, &K);
    scanf("%lld %lld %lld %lld", &len[0], &len[1], &len[2], &len[3]);

    for(int i = 1; i <= N; i++)
    {
        int val;
        char c;

        scanf(" %c %d", &c, &val);

        if(c == 'A') v[0].push_back(val);
        else if(c == 'B') v[1].push_back(val);
        else if(c == 'C') v[2].push_back(val);
        else v[3].push_back(val);
    }
}

int main()
{
    input();

    for(int i = 0; i < 4; i++) sort(v[i].begin(), v[i].end());

    for(int i = 0; i < K; i++)
    {
        ll idx = 0;

        for(int j = 1; j < 4; j++)
        {
            if(v[idx].size() == 0)
            {
                idx = j;
                continue;
            }

            if(v[j].size() == 0) continue;

            ll sum1 = len[j] * v[idx].back();
            ll sum2 = len[idx] * v[j].back();

            if(sum1 < sum2) idx = j;
        }

        len[idx] += v[idx].back();

        if(idx == 0) printf("A ");
        else if(idx == 1) printf("B ");
        else if(idx == 2) printf("C ");
        else printf("D ");
        printf("%d\n", v[idx].back());

        v[idx].pop_back();
    }

    return 0;
}
