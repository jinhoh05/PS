#include <bits/stdc++.h>

using namespace std;

int N, ans = 1;
int vt[2005];

vector<int> idx;

set<int> s[2005];

void isdeq()
{
    int x = 1001, mode = 0;

    for(int u : idx)
    {
        while(s[u].size() > 0)
        {
            auto p = s[u].lower_bound(x);

            //printf("%d ", *p);

            if(mode == 0)
            {
                if(p == s[u].begin())
                {
                    mode = 1;
                }

                else
                {
                    p--;
                    x = *p;
                    s[u].erase(p);
                }
            }

            else
            {
                if(p == s[u].end())
                {
                    mode = 0;
                    ans++;
                }

                else
                {
                    x = *p;
                    s[u].erase(p);
                }
            }
        }
    }

}

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int val;
        scanf("%d", &val);
        val += 1000;

        if(!vt[val]) idx.push_back(val);
        vt[val] = 1;

        s[val].insert(i);
    }

    sort(idx.begin(), idx.end());

    isdeq();

    printf("%d", ans);

    return 0;
}
