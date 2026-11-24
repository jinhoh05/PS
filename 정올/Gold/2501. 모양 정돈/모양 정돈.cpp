#include <bits/stdc++.h>

using namespace std;
int n, ans=200005;
int num[4], order[4], check[4];
int a[100005], arr[100005];

int calc(){
    int pos[4][4]={{0}}, k=0, cnt1=0, cnt2=0;

    for(int i=1;i<=3;i++){
        for(int j=0;j<num[order[i]];j++){
            a[k++] = order[i];
        }
    }

    for(int i=0;i<n;i++) pos[a[i]][arr[i]]++;

    for(int i=1;i<3;i++){
        for(int j=i+1;j<=3;j++){
            k = min(pos[i][j], pos[j][i]);
            cnt1 += k;
            cnt2 += pos[i][j] + pos[j][i] - (k * 2);
        }
    }

    return cnt1 + cnt2 / 3 * 2;
}

void dfs(int lev) {
    if(lev > 3) {
        ans=min(ans, calc());
        return;
    }

    for(int i=1;i<=3;i++) {
        if(check[i]) continue;
        check[i] = 1;
        order[lev] = i;
        dfs(lev + 1);
        check[i] = 0;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
        num[arr[i]]++;
    }

    dfs(1);
    printf("%d", ans);

    return 0;
}