#include <bits/stdc++.h>

using namespace std;

struct st{
    int s, e, c;
}room[30];

int n, ans;
int DP[30];

void dynamic(){
    DP[0] = room[0].c;
    ans = DP[0];

    if(n > 1){
        DP[1] = room[1].c;
        ans = max(DP[0], DP[1]);
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=i-2;j++){
            DP[i] = max(DP[i], DP[j] + room[i].c);
        }
        ans = max(ans, DP[i]);
    }
}

int main()
{
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d %d %d", &room[i].s, &room[i].e, &room[i].c);
    }

    dynamic();

    printf("%d", ans);

    return 0;
}
