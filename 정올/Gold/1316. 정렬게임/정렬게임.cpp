#include <bits/stdc++.h>

using namespace std;

int N, ans = 1e9;

vector<int> seq;

map<vector<int>, int> rev;

queue<pair<vector<int>, int>> q;

void push(pair<vector<int>, int> t)
{
    int s = 0, e = 1;

    while(s < t.first.size())
    {
        pair<vector<int>, int> test = t;

        reverse(test.first.begin() + s, test.first.begin() + e);

        if(rev.find(test.first) == rev.end())
        {
            rev[test.first] = t.second + 1;
            q.push({test.first, test.second + 1});
        }

        if(e >= t.first.size())
        {
            s = s + 1;
            e = s + 1;
        }

        else e++;
    }
}

void bfs()
{
    q.push({seq, 0});

    while(!q.empty())
    {
        pair<vector<int>, int> t = q.front();
        q.pop();

        int cnt = 0;

        for(int i = 0; i < t.first.size() - 1; i++)
        {
            if(t.first[i] < t.first[i + 1]) cnt++;
        }

        if(cnt == t.first.size() - 1) ans = min(ans, t.second);

        push(t);
    }
}

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int val;
        scanf("%d", &val);

        seq.push_back(val);
    }

    rev[seq] = 0;

    bfs();

    printf("%d", ans);

    return 0;
}