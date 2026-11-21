#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, k, m, v, c;
int bag[300005];
pii jew[300005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> jew[i].first >> jew[i].second;

    for(int i=0;i<k;i++) cin >> bag[i];

    sort(jew, jew + n);
    sort(bag, bag + k);

    long long sum = 0;
    priority_queue<int> pq;

    int j = 0;
    for(int i=0;i<k;i++){
        while(j < n && jew[j].first <= bag[i]) pq.push(jew[j++].second);

        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;

    return 0;
}
