#include <bits/stdc++.h>

using namespace std;

int N;
int cost[10005];

set<int> s;

int main()
{
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        scanf("%*s %d", &cost[i]);
    }

    s.insert(cost[1]);

    for(int i = 2; i <= N; i++)
    {
        auto P = s.lower_bound(cost[i]);

        if(P != s.end()) s.erase(P);
        s.insert(cost[i]);

        /*
        for(auto it = s.begin(); it != s.end(); it++)
        {
            printf("%d ", *it);
        }
        printf("\n");
        */
    }

    printf("%d", (int)s.size());

    return 0;
}