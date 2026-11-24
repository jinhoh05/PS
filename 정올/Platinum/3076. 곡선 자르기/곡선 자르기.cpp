#include <bits/stdc++.h>

using namespace std;
int n, m, ans1, ans2, mx = -1e9;
int x[2000005], y[2000005];

struct data{
    int a, b;
    bool operator<(const data &t)const{
        return a < t.a;
    };
}arr[1000005];

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d %d", &x[i], &y[i]);
        x[n+i] = x[i]; y[n+i] = y[i];
    }

    for(int i=1;i<=n;i++) if (y[i] < 0){
        int state = 0, last = 0;
        for(int j=0;j<n;j++){
            int s = i+j, e = s < 2*n ? s + 1 : 1;
            if(x[s] == x[e] && (long long)y[s] * y[e] < 0){
                if(state) arr[++m] = {min(last, x[s]), max(last, x[s])};
                else last = x[s];
                state ^= 1;
            }
        }
        break;
    }

    sort(arr+1, arr+m+1);

    for(int i=1;i<=m;i++){
        if(mx < arr[i].a) ans1++;
        mx = max(mx, arr[i].b);
        if(i == m || arr[i+1].a > arr[i].b) ans2++;
    }

    printf("%d %d",ans1, ans2);

    return 0;
}