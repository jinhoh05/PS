#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M;
int cnt;
int ans[100005];
int vt[100005], f[100005], s[100005];

int main()
{
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d", &f[i], &s[i]);
    }

    for(int i = N; i >= 1; i--)
    {
        int j = i;
        int val = f[j];

        while(1)
        {
            if(vt[val] == 0)
            {
                cnt++;
                vt[val] = j;
                break;
            }

            else if(vt[val] < j) break;

            else
            {
                int imp = vt[val];
                vt[val] = j;

                if(s[imp] == val) break;

                j = imp;
                val = s[j];
            }
        }

        ans[i] = cnt;
    }

    for(int i = 1; i <= N; i++)
    {
        printf("%d\n", ans[i]);
    }

    return 0;
}