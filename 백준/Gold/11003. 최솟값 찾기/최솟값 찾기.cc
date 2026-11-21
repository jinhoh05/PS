#include <bits/stdc++.h>

using namespace std;

int A[5000000];
deque<pair<int, int>> dq;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;

    for(int i=0;i<n;i++) cin >> A[i];

    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front().second <= i - l) dq.pop_front();

        while(!dq.empty() && dq.back().first > A[i]) dq.pop_back();

        dq.push_back({A[i], i});

        cout << dq.front().first << " ";
    }

    return 0;
}
