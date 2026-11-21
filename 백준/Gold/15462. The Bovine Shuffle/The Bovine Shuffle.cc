#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

int dfsn[MAX_N + 1], scc[MAX_N + 1], r, c;

vector<int> vt[MAX_N + 1];
vector<vector<int>> res;

stack<int> st;

int dfs(int here) {
    dfsn[here] = ++c;
    int ret = dfsn[here];
    st.push(here);
    for (int next : vt[here]) {
        if (dfsn[next] == 0)
            ret = min(ret, dfs(next));
        else if (scc[next] == 0)
            ret = min(ret, dfsn[next]);
    }
    if (ret == dfsn[here]) {
        vector<int> tmp;
        r++;
        while (1) {
            int t = st.top();
            st.pop();
            scc[t] = r;
            tmp.push_back(t);
            if (t == here) break;
        }
        res.push_back(tmp);
    }
    return ret;
}

int main() 
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    int N, a[MAX_N + 1];
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        vt[i].push_back(a[i]);
    }

    for (int i = 1; i <= N; i++)
        if (!dfsn[i]) dfs(i);

    int answer = 0;
    
    for (int i = 0; i < r; i++) {
        if (res[i].size() >= 2) answer += res[i].size();
        else answer += int(a[res[i][0]] == res[i][0]);
    }
    
    cout << answer;

    return 0;
}