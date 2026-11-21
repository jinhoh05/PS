#include <bits/stdc++.h>

using namespace std;

struct st{
    int s, e, c;
}room[100005];

int n, ans;
int DP[100005];

void dynamic(){
    DP[0] = room[0].c;
    ans = DP[0];
    
    if(n > 1){
        DP[1] = room[1].c;
        ans = max(ans, DP[1]);
    }

    if(n > 2){
        DP[2] = room[2].c + DP[0];
        ans = max(ans, DP[2]);
    }

    for(int i=3;i<n;i++){
        DP[i] = max(DP[i - 2], DP[i - 3]) + room[i].c;
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
