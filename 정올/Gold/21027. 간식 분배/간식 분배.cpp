#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
int p[200005], vt[200005], snack[200005];

vector<int> student[200005], v[200005], ans;
queue<int> q;

// student: 학생이 좋아하는 간식
// p      : degree
// v      : 특정 간식을 좋아하는 학생
// vt     : 학생 방문
// snack  : 간식 방문

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;

        p[i] = m;
        
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            student[i].push_back(x);
            v[x].push_back(i);          
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 1) q.push(i);
    }

    while (!q.empty())
    {
        int s = q.front();
        q.pop();

        if(vt[s] || p[s] != 1) continue;

        int idx = -1;
        for (int u : student[s])
        {
            if (!snack[u])
            {
                idx = u;
                break;
            }
        }

        if (idx == -1) continue;

        vt[s] = 1;
        ans.push_back(s);
        snack[idx] = 1;

        for (int u : v[idx]) 
        {
            if(vt[u]) continue;

            p[u]--;

            if(p[u] == 1) q.push(u);
        }
    }

    if(ans.size() != n) cout << -1 << "\n";
    else
    {
        for (int u : ans)
        {
            cout << u << " ";
        }
    }

    return 0;
}