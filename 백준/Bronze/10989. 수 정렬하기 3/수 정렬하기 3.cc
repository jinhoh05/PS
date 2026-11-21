#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int vt[10005];
int num[10005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++){
        int a;
        cin >> a;
        vt[a]++;
    }

    for(int i=1;i<=10000;i++){
        for(int j=0;j<vt[i];j++) cout << i << "\n";
    }
}
