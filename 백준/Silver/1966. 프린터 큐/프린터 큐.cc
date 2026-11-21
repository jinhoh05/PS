#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, m, tc, cnt;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> tc;

    for(int i=0;i<tc;i++){
        cnt = 0;
        cin >> n >> m;

        queue<pii> q;
        priority_queue<int> pq;

        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            q.push({j, x});
            pq.push(x);
        }

        while(!q.empty()){
            pii t = q.front();
            q.pop();

            if(pq.top() == t.second){
                pq.pop();
                cnt++;

                if(t.first == m){
                    cout << cnt << "\n";
                    break;
                }
            }

            else q.push(t);
        }
    }

    return 0;
}
