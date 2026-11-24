#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int ans;

ll DP[500005][2];

vector<pii> v;

struct data{

    int cost, loc;

    bool operator<(const data &t)const{
        if(cost == t.cost) return loc < t.loc;
        return cost < t.cost;
    }

}book[500005];

int calc(int loc, int i, int dir)
{
    int val;
    int loc1 = book[v[i - 1].first].loc, loc2 = book[v[i - 1].second].loc;
    int loc3 = book[v[i].first].loc, loc4 = book[v[i].second].loc;

    if(loc == 0)
    {
        if(dir == 0) val = abs(loc1 - loc4);
        else val = abs(loc1 - loc3);
    }

    else
    {
        if(dir == 0) val = abs(loc2 - loc4);
        else val = abs(loc2 - loc3);
    }

    return val + abs(loc3 - loc4);
}

void dynamic()
{
    for(int i = 1; i < v.size(); i++)
    {
        DP[i][0] = min(DP[i - 1][0] + calc(0, i, 0), DP[i - 1][1] + calc(1, i, 0));
        DP[i][1] = min(DP[i - 1][0] + calc(0, i, 1), DP[i - 1][1] + calc(1, i, 1));
    }
}

void init()
{
    int st = 1;

    sort(book + 1, book + N + 1);

    v.push_back({0, 0});

    for(int i = 1; i <= N; i++)
    {
        if(book[i].cost != book[i + 1].cost)
        {
            v.push_back({st, i});
            st = i + 1;
        }
    }

    book[0].loc = 1;
}

void input()
{
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &book[i].cost);

        book[i].loc = i;
    }
}

int main()
{
    input();

    init();

    dynamic();

    //for(int i = 1; i < v.size(); i++) printf("%d %d\n", DP[i][0], DP[i][1]);

    printf("%lld", min(DP[v.size() - 1][0], DP[v.size() - 1][1]));

    return 0;
}